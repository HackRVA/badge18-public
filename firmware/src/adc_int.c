#include <plib.h>
#include "adc.h"
#include "rf.h"

// see adc.h for HZ_ enums
const struct sample_info_t samples_info[] = {
   //{HZ_1000,  "1 ", 28, 124},
   {HZ_1000,  "1 ", 30, 118},
   {HZ_8000,  "8 ", 27, 15},
   {HZ_32000, "16 ", 27,  7},
   {HZ_48000, "32 ", 27,  3},
   {HZ_96000, "48 ", 27,  1},
   {HZ_96000, "96 ", 14,  1}
};

unsigned int volatile ADCbufferCnt = 0;
unsigned int volatile ADCbufferCntMark = 0;

// results copied to share with the user app
volatile unsigned short ADCbuffer[ADC_BUFFER_SIZE+8]; // extra 8 bytes so interrupts have a place to store 

void ADC_init(unsigned char sample_hz_num) // HZ_1000 ... (HZ_LAST-1)
{
   int i;

   IEC0bits.AD1IE = 0; // disable int to reconfig
   AD1CON1bits.ON = 0;   // adc off
   RF_POWER = 1; // turn on RF

   // MIC_INPUT RC3 / AN12
   // TRISCbits.TRISC3 = 1; // mic is an analog input

   // RF_IN     RB1 / AN3
   // TRISBbits.TRISB1 = 1; // RF input is analog

   // touch in  RB2 / AN4
   // TRISBbits.TRISB2 = 1; // touch pad input

           
   IEC0bits.AD1IE = 0; // disable interrupt
   IFS0bits.AD1IF = 0; // clear flag

   AD1CON1bits.SIDL = 0; // stop in idle mode
   AD1CON1bits.FORM = 0b000; // results are integers
   AD1CON1bits.SSRC = 0b111; // auto sample & start
   AD1CON1bits.CLRASAM = 0; // buffer will be overwritten next sample
   AD1CON1bits.DONE = 0; // not really needed, handle automatically

   AD1CON2bits.VCFG = 0; // use Vdd and Vss for voltage refs
   AD1CON2bits.OFFCAL = 0; // disable calibration mode
   AD1CON2bits.CSCNA = 1; // scan all analoginputs when auto sampling
   AD1CON2bits.BUFS = 0; // indicates which buffer is being filled
   AD1CON2bits.SMPI = 5; // interrupt and the end of 6 samples
   AD1CON2bits.BUFM = 1; // ** double buffered, one for ADC, one for copy out
   AD1CON2bits.ALTS = 0; // don't alternate between mux A/B for sample. used for differential IO

   AD1CON3bits.ADRC = 0; // PBCLK. clock source is FRC or PBCLK
   AD1CON3bits.SAMC = 31; // Tad = 1..31
   AD1CON3bits.ADCS = 154; // PB * 8 needed for autoconvert. conversion clock select

   AD1CHSbits.CH0NB = 0; // pos channel select not use with scanning
   AD1CHSbits.CH0SB = 0b0000; // not use with scanning
   AD1CHSbits.CH0NA = 0; // Vr-
   AD1CHSbits.CH0SA = 0b0000; // neg channel select not use with scanning

   // Vref=AN15 AN12=mic AN4=touch AN3 == RF
   AD1CSSLbits.CSSL = 0b1001000000011000; // scan bit mask
   
   IPC5bits.AD1IP = 5; // priority 4
   IPC5bits.AD1IS = 0;  // sub pri. 1

   AD1CON1bits.ASAM = 1; // ** auto sample
   AD1CON1bits.ON = 1;   // adc on
 
   IEC0bits.AD1IE = 1; // enable interrupt
}

// {IPL4}SOFT == overwritten registers are shadow by software. 
// Some pic32 have shadow regs. for interrupts for speed purposes
void __ISR(_ADC_VECTOR, IPL5SOFT) ADC_handler(void)
{
   int krap;

//   if (ADCbufferCntMark != 0) {
//	ADCbufferCntMark = 0; // reset handshake
//	ADCbufferCnt = 0; // signal to empty
//   }

   if (ADCbufferCnt == ADC_BUFFER_SIZE) {
	if  (ADCbufferCntMark != 0) {
	   ADCbufferCntMark = 0;
	   ADCbufferCnt = 0;
	}
	else
	   ADCbufferCnt -= 8; // reset to last buffer
   }

   // 8-15 are full (and the ADC uses only 10bits)
   // but have to read them all or the interrupt won't clear see "persistant interrupts"
   if (AD1CON2bits.BUFS) {
	ADCbuffer[ADCbufferCnt++] = ADC1BUF0;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF1;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF2;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF3;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF4;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF5;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF6;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF7;
	krap = ADC1BUF8;
	krap = ADC1BUF9;
	krap = ADC1BUFA;
	krap = ADC1BUFB;
	krap = ADC1BUFC;
	krap = ADC1BUFD;
	krap = ADC1BUFE;
	krap = ADC1BUFF;
	IFS0bits.AD1IF = 0; // clear int
   }
   else {
	krap = ADC1BUF0;
	krap = ADC1BUF1;
	krap = ADC1BUF2;
	krap = ADC1BUF3;
	krap = ADC1BUF4;
	krap = ADC1BUF5;
	krap = ADC1BUF6;
	krap = ADC1BUF7;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF8;
	ADCbuffer[ADCbufferCnt++] = ADC1BUF9;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFA;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFB;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFC;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFD;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFE;
	ADCbuffer[ADCbufferCnt++] = ADC1BUFF;
	IFS0bits.AD1IF = 0; // clear int
   }
   AD1CON1bits.ASAM = 1; // re-enable auto sampling
}
