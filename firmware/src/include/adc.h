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

#define N_ADC_PINS 4

// one LCD scanline
#define ADC_BYTES_PER_SAMPLE N_ADC_PINS
#define ADC_SAMPLES_PER_LINE 128
#define ADC_BUFFER_SIZE (ADC_SAMPLES_PER_LINE * ADC_BYTES_PER_SAMPLE)

void ADC_init(unsigned char sample_rate);

struct sample_info_t {
   unsigned char hz; // see list below
   char name[8]; // human name
   unsigned char SAMC;
   unsigned char ADCS;
} sample_info_t;

enum SAMPLE_HZ {
   HZ_1000,
   HZ_8000,
   HZ_16000,
   HZ_32000,
   HZ_64000,
   HZ_96000,
   HZ_LAST
};

extern const struct sample_info_t samples_info[];

extern volatile unsigned short ADCbuffer[];
extern volatile unsigned int ADCbufferCnt;
extern volatile unsigned int ADCbufferCntMark;
extern const volatile unsigned int *ADCbufferAddresses[][8];
 
#define AUDIO_PHASE1 LATAbits.LATA9
#define AUDIO_PHASE2 LATAbits.LATA4

#endif	/* ADC_H */

