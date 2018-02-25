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
   int currentPin, i;

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
		FbWriteLine("ADC");
                FbSwapBuffers();
                break;

            case DRAW:
                if(BUTTON_PRESSED_AND_CONSUME) state++;

/*
		FbMove(10,10);
		unsigned char tmp[] = {
			hextab[(ADCbuffer[0+ADCbufferCntMark] >> 8)& 0xF], // pin1 samp1
			hextab[(ADCbuffer[0+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[1+ADCbufferCntMark] >> 8)& 0xF], // pin2 samp1
			hextab[(ADCbuffer[1+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[2+ADCbufferCntMark] >> 8)& 0xF], // pin3 samp1
			hextab[(ADCbuffer[2+ADCbufferCntMark]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp);

		FbMove(10,20);
		unsigned char tmp2[] = {
			hextab[(ADCbuffer[3+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[3+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[4+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[4+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[5+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[5+ADCbufferCntMark]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp2);

		FbMove(10,30);
		unsigned char tmp3[] = {
			hextab[(ADCbuffer[6+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[6+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[7+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[7+ADCbufferCntMark]     )& 0xF],
			' ',
			hextab[(ADCbuffer[8+ADCbufferCntMark] >> 8)& 0xF],
			hextab[(ADCbuffer[8+ADCbufferCntMark]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp3);
*/

		// the ADC samples and buffers each pin in sequence, 
		// need to pic them apart and plot them on their own line
	if (ADCbufferCntMark == 0) { // ADC to start new buffer
		if (ADCbufferCnt >= ADC_BUFFER_SIZE ) { // on last buffer 
		   for (i=0; i < ADC_BUFFER_SIZE; i++) {
			if ((i % N_ADC_PINS) == 0) {
			   FbColor(RED);
			   if ((96 - (ADCbuffer[i] % 128)) > 0)
			      FbPoint(i/3, 96 - (ADCbuffer[i] % 128));
			}

			if ((i % N_ADC_PINS) == 1) {
			   FbColor(GREEN);
			   if ((112 - (ADCbuffer[i] % 128)) > 0)
			      FbPoint(i/3, 112 - (ADCbuffer[i] % 128));
			}

			if ((i % N_ADC_PINS) == 2) {
			   FbColor(BLUE);
			   if ((128 - (ADCbuffer[i] % 128)) > 0)
			   FbPoint(i/3, 128 - (ADCbuffer[i] % 128));
			}
		   }
		   ADCbufferCntMark = 1; // handshake to empty buffer and start aquiring again
		}
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
