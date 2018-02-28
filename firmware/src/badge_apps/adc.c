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

		strcpy(title, "kHZ ");
		strcat(title, samples_info[hz_num].name);

		ADC_init(hz_num); // slowest

		FbWriteLine(title);
                FbSwapBuffers();
                break;

            case DRAW:
                if(BUTTON_PRESSED_AND_CONSUME) state++;

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
		unsigned short RFmin, RFmax, RFdelta, RFdiv;
		unsigned short touchMin, touchMax, touchDelta, touchDiv;
		unsigned short micMin, micMax, micDelta, micDiv;

		// find min and maxes
		RFmin = touchMin = micMin = 0xFFFF;
		RFmax = touchMax = micMax = 0x0000;

		for (i=0; i < ADC_BUFFER_SIZE; i+=4) {
			if (ADCbuffer[i] < RFmin) RFmin = ADCbuffer[i];
			if (ADCbuffer[i] > RFmax) RFmax = ADCbuffer[i];
		}
		for (i=1; i < ADC_BUFFER_SIZE; i+=4) {
			if (ADCbuffer[i] < touchMin) touchMin = ADCbuffer[i];
			if (ADCbuffer[i] > touchMax) touchMax = ADCbuffer[i];
		}
		for (i=2; i < ADC_BUFFER_SIZE; i+=4) {
			if (ADCbuffer[i] < micMin) { 
			   if (ADCbuffer[i] != 0) micMin = ADCbuffer[i]; // wtf. ignore false zeros
			}
			if (ADCbuffer[i] > micMax) micMax = ADCbuffer[i];
		}
		RFdelta = RFmax - RFmin;
		touchDelta = touchMax - touchMin;
		micDelta = micMax - micMin;

		RFdiv = RFdelta >> 5; // RFdelta/32
		RFdiv++;

		touchDiv = touchDelta >> 5;
		touchDiv++;

		micDiv = micDelta >> 5;
		micDiv++;

		// the ADC samples and buffers each pin in sequence, 
		// need to pic them apart and plot them on their own line
		// avoid division when posible
		for (i=0; i < ADC_BUFFER_SIZE; i+=4) { // RF
			FbColor(B_RED);
			if (touchDiv > 1)
			   FbPoint(i/4,  32 - (ADCbuffer[i] - RFmin) / RFdiv);
			else
			   FbPoint(i/4,  32 - (ADCbuffer[i] - RFmin));
		}

		for (i=1; i < ADC_BUFFER_SIZE; i+=4) { // touch
			FbColor(GREEN);
			if (touchDiv > 1)
			   FbPoint(i/4,  64 - (ADCbuffer[i] - touchMin) / touchDiv);
			else
			   FbPoint(i/4,  64 - (ADCbuffer[i] - touchMin));
		}

		for (i=2; i < ADC_BUFFER_SIZE; i+=4) { // mic
			FbColor(YELLOW);
			if (micDiv > 1)
			   FbPoint(i/4,  96 - (ADCbuffer[i] - micMin) / micDiv);
			else
			   FbPoint(i/4,  96 - (ADCbuffer[i] - micMin));
		}

		for (i=3; i < ADC_BUFFER_SIZE; i+=4) { // AVss
			FbColor(WHITE);
			FbPoint(i/4, 128 - (ADCbuffer[i] >> 1));
		}

		// handshake to empty buffer and start aquiring again
		ADCbufferCntMark = 1; 

		ADCloopCnt++;
		if (ADCloopCnt==3) { // clear FB after a bit
			ADCloopCnt=0;
			FbSwapBuffers();
		}
		else
			FbPushBuffer();
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
