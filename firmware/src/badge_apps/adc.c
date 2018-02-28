#include "app.h"
#include "colors.h"
#include "fb.h"
#include "buttons.h"
#include "adc.h"
#include "flare_leds.h"

extern char hextab[];

enum adc_state {
    INIT,
    DRAW,
    EXIT
};

void adc_task(void* p_arg) {
   unsigned char cnt=0;
   //const TickType_t xDelay = 50 / portTICK_PERIOD_MS;
   const TickType_t xDelay = 10 / portTICK_PERIOD_MS;
   static unsigned char state = INIT;
   int i, ADCloopCnt=0;
   char title[32];
   int hz_num=0;


   for(;;){
        switch(state){
            case INIT:
		FbBackgroundColor(GREY1);
		FbClear();

                if(cnt == 5 || BUTTON_PRESSED_AND_CONSUME){
                    state++;
                    cnt = 0;
                }
                FbColor(WHITE);
		FbMove(10,10);

		// pwm can affect the ADC conversions
		led(0,0,0);

		// allow hz change here
		if (LEFT_BTN_AND_CONSUME) {
		   hz_num--;
		   if (hz_num < 0) hz_num = 0;
		   state = INIT; // reinit app
		}

		if (RIGHT_BTN_AND_CONSUME) {
		   hz_num++;
		   if (hz_num == HZ_LAST) hz_num--;
		   state = INIT; // reinit app
		}
		strcpy(title, "kHZ ");
		strcat(title, samples_info[hz_num].name);

		ADC_init(hz_num); // slowest

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
		}

		if (RIGHT_BTN_AND_CONSUME) {
		   hz_num++;
		   if (hz_num == HZ_LAST) hz_num--;
		   state = INIT; // reinit app
		}

	if (ADCbufferCntMark == 0) { // has started filling buffer yet
	    if (ADCbufferCnt >= ADC_BUFFER_SIZE ) { // done
		unsigned short RFmin, RFmax, RFdelta, RFdiv, RFLshift, RFRshift;
		unsigned short touchMin, touchMax, touchDelta, touchDiv, touchLshift, touchRshift;
		unsigned short micMin, micMax, micDelta, micDiv, micLshift, micRshift;
		unsigned char x;
		unsigned char b;

		// find min and maxes
		RFmin = touchMin = micMin = 0xFFFF;
		RFmax = touchMax = micMax = 0x0000;

		for (i=0; i < ADC_BUFFER_SIZE; i+=4) {
			if (ADCbuffer[i] < RFmin) RFmin = ADCbuffer[i];
			if (ADCbuffer[i] > RFmax) RFmax = ADCbuffer[i];
			if (ADCbuffer[i+1] < touchMin) touchMin = ADCbuffer[i+1];
			if (ADCbuffer[i+1] > touchMax) touchMax = ADCbuffer[i+1];
			if (ADCbuffer[i+2] < micMin) micMin = ADCbuffer[i+2];
			if (ADCbuffer[i+2] > micMax) micMax = ADCbuffer[i+2];
		}
		RFdelta = RFmax - RFmin;
		touchDelta = touchMax - touchMin;
		micDelta = micMax - micMin;

//		RFdiv = RFdelta >> 5; // RFdelta/32
//		RFdiv++;

//		touchDiv = touchDelta >> 5;
//		touchDiv++;

//		micDiv = micDelta >> 5;
//		micDiv++;

		RFRshift = touchRshift = micRshift = 0;
		RFLshift = touchLshift = micLshift = 0;
		// find highest bit to for scale down
		for (b=9; b>=5; b--) {
		   if (RFdelta & (1<<b))    { if (RFRshift==0)    RFRshift = b-4; };
		   if (touchDelta & (1<<b)) { if (touchRshift==0) touchRshift = b-4; };
		   if (micDelta & (1<<b))   { if (micRshift==0)   micRshift = b-4; };
		}
		// find highest bit for scale up
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
			FbPoint(x,       (((ADCbuffer[i] - RFmin) << RFLshift) >> RFRshift));

			FbColor(GREEN);
			FbPoint(x,  32 + (((ADCbuffer[i+1] - touchMin) << touchLshift) >> touchRshift));

			FbColor(YELLOW);
			FbPoint(x,  64 + (((ADCbuffer[i+2] - micMin) << micLshift) >> micRshift));

			FbColor(WHITE);
			FbPoint(x, 96 + (ADCbuffer[i+3] >> 2));
		}

		// handshake to empty buffer and start aquiring again
		ADCbufferCntMark = 1; 

		ADCloopCnt++;
		// need to make this controlable from the UI
//		if (ADCloopCnt==3) { // clear FB after a bit
//			ADCloopCnt=0;
//			FbSwapBuffers();
//		}
//		else
//			FbPushBuffer();
			FbSwapBuffers();
	    }
	}
		break;

            case EXIT:
		state = INIT;
                returnToMenus();
                break;
        }
	vTaskDelay(xDelay);
	cnt++;
   }
}
