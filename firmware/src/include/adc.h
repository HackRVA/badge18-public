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

// 128 = one LCD scanline
//#define ADC_BUFFER_SIZE 128 * N_ADC_PINS
#define ADC_BUFFER_SAMPLES 16
#define ADC_BUFFER_MULTIPLE (ADC_BUFFER_SAMPLES * N_ADC_PINS)

// one hidden multiple for when user is processing
#define ADC_BUFFER_SIZE ((128 / 16) * ADC_BUFFER_MULTIPLE)
#define ADC_BUFFER_SIZE_EXTRA (ADC_BUFFER_SIZE + ADC_BUFFER_MULTIPLE)

extern volatile unsigned short ADCbuffer[];
extern volatile unsigned int ADCbufferCnt;
extern volatile unsigned int ADCbufferCntMark;
extern const volatile unsigned int *ADCbufferAddresses[][8];
 
#define AUDIO_PHASE1 LATAbits.LATA9
#define AUDIO_PHASE2 LATAbits.LATA4

#endif	/* ADC_H */

