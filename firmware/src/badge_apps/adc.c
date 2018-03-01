#include "app.h"
#include "colors.h"
#include "fb.h"
#include "buttons.h"
#include "adc.h"
#include "timer1_int.h"
#include "flare_leds.h"

extern char hextab[];

// exercise the ADC
// peb 20180228
// todo: a bigger buffer with downscaling

enum adc_state {
    INIT,
    DRAW,
    EXIT
};

void adc_task(void* p_arg) {
   unsigned char cnt=0;
   //const TickType_t xDelay = 50 / portTICK_PERIOD_MS;
   const TickType_t xDelay = 2 / portTICK_PERIOD_MS; // not nice
   static unsigned char state = INIT;
   int i, ADCloopCnt=0;
   char title[32];
   static int hz_num=0;


   for(;;){
        switch(state){
            case INIT:
                if (cnt == 10 || BUTTON_PRESSED_AND_CONSUME){ // delay to read
                    state++;
                    cnt = 0;
                }
		// pwm can affect the ADC conversions
		led(0,0,0);

		if (DOWN_BTN_AND_CONSUME) {
		   G_led_input_hack = !G_led_input_hack;
		   state = INIT; // reinit app
                   cnt = 0;
		}

		// allow hz change here
		if (LEFT_BTN_AND_CONSUME) {
		   hz_num--;
		   if (hz_num < 0) hz_num = 0;
		   state = INIT; // reinit app
                   cnt = 0;
		}

		if (RIGHT_BTN_AND_CONSUME) {
		   hz_num++;
		   if (hz_num == HZ_LAST) hz_num--;
		   state = INIT; // reinit app
                   cnt = 0;
		}
		ADC_init(hz_num); // current hz_num


		FbBackgroundColor(GREY1);
		FbClear();

                FbColor(WHITE);
		FbMove(10,10);

		strcpy(title, "kHZ ");
		strcat(title, samples_info[hz_num].name);
		FbWriteLine(title);

		FbMove(10,20);
		strcpy(title, "left/right: HZ ");
		FbWriteLine(title);

		FbMove(10,30);
		strcpy(title, "down: mode ");
		FbWriteLine(title);

		FbMove(10,40);
		if (G_led_input_hack)
		   strcpy(title, "LEDS ");
		else
		   strcpy(title, "RF Mic touch ");

		FbWriteLine(title);

                FbSwapBuffers();
                break;

            case DRAW:
                if(BUTTON_PRESSED_AND_CONSUME) state++;

		// allow hz change here also
		if (LEFT_BTN_AND_CONSUME) {
		   hz_num--;
		   if (hz_num < 0) hz_num = 0;
		   state = INIT; // reinit app
                   cnt = 0;
		}

		if (RIGHT_BTN_AND_CONSUME) {
		   hz_num++;
		   if (hz_num == HZ_LAST) hz_num--;
		   state = INIT; // reinit app
                   cnt = 0;
		}

		if (DOWN_BTN_AND_CONSUME) {
		   G_led_input_hack = !G_led_input_hack;
		   state = INIT; // reinit app
                   cnt = 0;
		}

		if (ADCbufferCntMark == 0) { // has started filling buffer yet
		    if (ADCbufferCnt >= ADC_BUFFER_SIZE ) { // ADC has filled
			unsigned short RFmin, RFmax, RFdelta, RFdiv, RFLshift, RFRshift;
			unsigned short touchMin, touchMax, touchDelta, touchDiv, touchLshift, touchRshift;
			unsigned short micMin, micMax, micDelta, micDiv, micLshift, micRshift;
			unsigned char x;
			unsigned char b;

			// find min and maxes
			RFmin = touchMin = micMin = 0xFFFF;
			RFmax = touchMax = micMax = 0x0000;

			// RF, touch and mic change names to r/g/b when G_led_input_hack is enabled
			for (i=0; i < ADC_BUFFER_SIZE; i+=4) {
				if (ADCbuffer[i] < RFmin) RFmin = ADCbuffer[i];
				if (ADCbuffer[i] > RFmax) RFmax = ADCbuffer[i];
				if (ADCbuffer[i+1] < touchMin) touchMin = ADCbuffer[i+1];
				if (ADCbuffer[i+1] > touchMax) touchMax = ADCbuffer[i+1];
				if (ADCbuffer[i+2] < micMin) micMin = ADCbuffer[i+2];
				if (ADCbuffer[i+2] > micMax) micMax = ADCbuffer[i+2];
				// skiping 4th sample==Vss
			}

			RFdelta = RFmax - RFmin;
			touchDelta = touchMax - touchMin;
			micDelta = micMax - micMin;

			RFRshift = touchRshift = micRshift = 0;
			RFLshift = touchLshift = micLshift = 0;
			// find highest bit to for scale down
			for (b=9; b>=5; b--) {
			   if (RFdelta & (1<<b))    { if (RFRshift==0)    RFRshift = b-4; };
			   if (touchDelta & (1<<b)) { if (touchRshift==0) touchRshift = b-4; };
			   if (micDelta & (1<<b))   { if (micRshift==0)   micRshift = b-4; };
			}
			// find highest bit for scale up
			// if the levels are really low (b<=2) this just amplifies noise
			// the dev version has better filtering on AVss 
			for (b=4; b>2; b--) {
			   if (RFdelta & (1<<b))    { if (RFRshift == 0)    RFLshift = 4-b; };
			   if (touchDelta & (1<<b)) { if (touchRshift == 0) touchLshift = 4-b; };
			   if (micDelta & (1<<b))   { if (micRshift == 0)   micLshift = 4-b; };
			}

			// the ADC samples and buffers each pin in sequence, 
			// need to pic them apart and plot them on their own line
			// avoid division when posible
			for (i=0,x=0; i < ADC_BUFFER_SIZE; i+=4,x++) { // RF
				FbColor(B_RED);
				FbPoint(x,   8 +   (((ADCbuffer[i] - RFmin) << RFLshift) >> RFRshift));
	
				FbColor(GREEN);
				FbPoint(x,  40 + (((ADCbuffer[i+1] - touchMin) << touchLshift) >> touchRshift));
	
				FbColor(YELLOW);
				FbPoint(x,  72 + (((ADCbuffer[i+2] - micMin) << micLshift) >> micRshift));
	
// Vss==dont bother unless curious
//				FbColor(WHITE);
//				FbPoint(x, 96 + (ADCbuffer[i+3] >> 2));
			}
	
			// handshake to empty buffer and start aquiring again
			ADCbufferCntMark = 1; 
	
//			ADCloopCnt++;
//			// need to make this controlable from the UI
//			if (ADCloopCnt==3) { // clear FB after a bit
//				ADCloopCnt=0;
//				FbSwapBuffers();
//			}
//			else
//				FbPushBuffer();
				FbSwapBuffers();
		    }
		}
		break;

            case EXIT:
		state = INIT;
                cnt = 0;
                returnToMenus();
                break;
        }
	vTaskDelay(xDelay);
	cnt++;
   }
}
