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
   const TickType_t xDelay = 50 / portTICK_PERIOD_MS;
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

		FbMove(10,30);
		unsigned char tmp3[] = {
			hextab[(ADCbuffer[9] >> 8)& 0xF],
			hextab[(ADCbuffer[9]     )& 0xF],
			' ',
			hextab[(ADCbuffer[10] >> 8)& 0xF],
			hextab[(ADCbuffer[10]     )& 0xF],
			' ',
			hextab[(ADCbuffer[11] >> 8)& 0xF],
			hextab[(ADCbuffer[11]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp3);

		FbMove(10,40);
		unsigned char tmp4[] = {
			hextab[(ADCbuffer[9] >> 8)& 0xF],
			hextab[(ADCbuffer[9]     )& 0xF],
			' ',
			hextab[(ADCbuffer[10] >> 8)& 0xF],
			hextab[(ADCbuffer[10]     )& 0xF],
			' ',
			hextab[(ADCbuffer[11] >> 8)& 0xF],
			hextab[(ADCbuffer[11]     )& 0xF],
			'\0',
		};
		FbWriteLine(tmp4);


		// the ADC samples each pin in sequence, need to pic them apart
		// and plot them on their own line

		for (i=ADCbufferCntMark; i < ADCbufferCntMark+8; i++) {
		   if ((i % N_ADC_PINS) == 0) {
			if ((108 - (int)ADCbuffer[i]) > 1)
			   FbPoint(i, 108 - (int)ADCbuffer[i]);
		   }
		   if ((i % N_ADC_PINS) == 1) {
			if ((118 - (int)ADCbuffer[i]) > 1)
			   FbPoint(i, 118 - (int)ADCbuffer[i]);
		   }
		   if ((i % N_ADC_PINS) == 2) {
			if ((127 - (int)ADCbuffer[i]) > 1)
			   FbPoint(i, 127 - (int)ADCbuffer[i]);
		   }
		} 
                FbSwapBuffers();
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
