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
   const TickType_t xDelay = 20 / portTICK_PERIOD_MS;
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

		strcpy(title, "kHZ left-right ");
		strcat(title, samples_info[hz_num].name);

		ADC_init(hz_num); // slowest

		FbWriteLine("ADC");
                FbSwapBuffers();
                break;

            case DRAW:
                if(BUTTON_PRESSED_AND_CONSUME) state++;

/*
	if (ADCbufferCntMark == 0) { // ADC to start new buffer
		FbColor(WHITE);

		FbMove(10,10);
		unsigned char tmp[] = {
			hextab[(ADCbuffer[0] >> 8)& 0xF], // pin1 samp1
			hextab[(ADCbuffer[0]     )& 0xF],
			' ',
			hextab[(ADCbuffer[1] >> 8)& 0xF], // pin2 samp1
			hextab[(ADCbuffer[1]     )& 0xF],
			' ',
			hextab[(ADCbuffer[2] >> 8)& 0xF], // pin3 samp1
			hextab[(ADCbuffer[2]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp);

		FbMove(10,20);
		unsigned char tmp2[] = {
			hextab[(ADCbuffer[3] >> 8)& 0xF],
			hextab[(ADCbuffer[3]     )& 0xF],
			' ',
			hextab[(ADCbuffer[4] >> 8)& 0xF],
			hextab[(ADCbuffer[4]     )& 0xF],
			' ',
			hextab[(ADCbuffer[5] >> 8)& 0xF],
			hextab[(ADCbuffer[5]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp2);


		FbMove(10,40);
		unsigned char tmp4[] = {
			hextab[(ADCbuffer[8] >> 8)& 0xF],
			hextab[(ADCbuffer[8]     )& 0xF],
			' ',
			hextab[(ADCbuffer[9] >> 8)& 0xF],
			hextab[(ADCbuffer[9]     )& 0xF],
			' ',
			hextab[(ADCbuffer[10] >> 8)& 0xF],
			hextab[(ADCbuffer[10]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp4);

		FbMove(10,50);
		unsigned char tmp5[] = {
			hextab[(ADCbuffer[11] >> 8)& 0xF],
			hextab[(ADCbuffer[11]     )& 0xF],
			' ',
			hextab[(ADCbuffer[12] >> 8)& 0xF],
			hextab[(ADCbuffer[12]     )& 0xF],
			' ',
			hextab[(ADCbuffer[13] >> 8)& 0xF],
			hextab[(ADCbuffer[13]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp5);

                FbSwapBuffers();
*/

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

	if (ADCbufferCntMark == 0) { // ADC to start new buffer
		// the ADC samples and buffers each pin in sequence, 
		// need to pic them apart and plot them on their own line
		if (ADCbufferCnt >= ADC_BUFFER_SIZE ) { // on last buffer 
		   for (i=0; i < ADC_BUFFER_SIZE; i++) {
			if ((i % N_ADC_PINS) == 0) {
			   FbColor(RED);
			   FbPoint(i/4,  80 - (ADCbuffer[i] >> 0));
			}

			if ((i % N_ADC_PINS) == 1) {
			   FbColor(GREEN);
			   FbPoint(i/4,  64 - (ADCbuffer[i] >> 0));
			}

			if ((i % N_ADC_PINS) == 2) {
			   FbColor(B_BLUE);
			   FbPoint(i/4, 128 - (ADCbuffer[i] >> 0));
			}

			if ((i % N_ADC_PINS) == 3) { // Vref
			   FbColor(WHITE);
			   FbPoint(i/4, 128 - (ADCbuffer[i] >> 1));
			}
		   }
		   ADCbufferCntMark = 1; // handshake to empty buffer and start aquiring again
		}
		ADCloopCnt++;
		if (ADCloopCnt==10) {
                   ADCloopCnt=0;
                   FbSwapBuffers();
		}
		else
                   FbPushBuffer();
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
