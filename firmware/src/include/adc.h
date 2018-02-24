/* 
   adc buffer
*/

#ifndef ADC_H
#define	ADC_H

/* 
   needs to be an multiple of the pins being sampled
   so multiples fit in the buffer- in this case 3
   mic, RF and touch
*/

#define N_ADC_PINS 3

#define ADC_BUFFER_SIZE 16 * N_ADC_PINS
extern volatile unsigned short ADCbuffer[];
extern volatile unsigned int ADCbufferCnt;
extern volatile unsigned int ADCbufferCntMark;
extern const volatile unsigned int *ADCbufferAddresses[][8];
 
#define AUDIO_PHASE1 LATAbits.LATA9
#define AUDIO_PHASE2 LATAbits.LATA4

#endif	/* ADC_H */

