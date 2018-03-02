#include <plib.h>
#include "adc.h"
#include "rf.h"
#include "timer1_int.h"
#include <math.h>

// setup and do analog to digital conversion
// peb 20180228

unsigned char calc_adcs(unsigned char chans,  int hz, unsigned char *samc_out) ;

// see adc.h for MASK enums
const struct analog_src_t analog_info[] = {
   {"mic/touch/RF/Vss", AN_MIC_MASK|AN_TOUCH_MASK|AN_RF_MASK|AN_VSS_MASK, 4}, // needs to be multiples of 1/2/4
   {"mic/touch", AN_MIC_MASK|AN_TOUCH_MASK, 2}, // needs to be multiples of 1/2/4
   {"mic", AN_MIC_MASK, 1},
   {"touch", AN_TOUCH_MASK, 1},
   {"RF", AN_RF_MASK, 1},
   {"R/G/B/Vss", AN_RED_MASK|AN_GREEN_MASK|AN_BLUE_MASK|AN_VSS_MASK, 4}, // needs to be multiples of 1/2/4
   {"red led", AN_RED_MASK, 1},
   {"green led", AN_GREEN_MASK, 1},
   {"blue led", AN_BLUE_MASK, 1},
   {"VSS", AN_BLUE_MASK, 1},
};

// see adc.h for HZ_ enums
const struct sample_info_t samples_info[] = {
   {500,  "0.5 "},
   {1000,  "1 "},
   {2000,  "2 "},
   {4000,  "4 "},
   {8000,  "8 "},
   {16000, "16 "},
   {32000, "32 "},
   {64000, "64 "},
   {96000, "96 "}
};

// compiler: because of interrupts, dont optimize and think these don't change
unsigned int volatile ADCbufferCnt = 0;
unsigned int volatile ADCbufferCntMark = 0;

// results copied to share with the user app
volatile unsigned short ADCbuffer[ADC_BUFFER_SIZE+8]; // extra 8 bytes so interrupts have a place to store when full

void ADC_init(unsigned char analog_src_num, unsigned char hz_num) // enum {HZ_500 ... (HZ_LAST-1)}
{
   int i;
   unsigned short analog_src_mask;
   unsigned short adcs;
   unsigned char samc;

   IEC0bits.AD1IE = 0; // disable int to reconfig
   AD1CON1bits.ON = 0; // adc off
   RF_POWER = 1; // turn on RF

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
   AD1CON2bits.SMPI = 7; // always fill 8 samples per interrupt. user has to deinterlace results
   AD1CON2bits.BUFM = 1; // ** double buffered, one for ADC, one for copy out
   AD1CON2bits.ALTS = 0; // don't alternate between mux A/B for sample. used for differential IO

   AD1CON3bits.ADRC = 0; // PBCLK. clock source is FRC or PBCLK

   adcs = calc_adcs(analog_info[analog_src_num].chans,  samples_info[hz_num].hz, &samc) ;
   //AD1CON3bits.SAMC = samples_info[hz_num].SAMC; // see calc_sample_rate.sh
   //AD1CON3bits.ADCS = samples_info[hz_num].ADCS; // see calc_sample_rate.sh
   AD1CON3bits.SAMC = samc; // see calc_sample_rate.sh
   AD1CON3bits.ADCS = adcs; // see calc_sample_rate.sh

   AD1CHSbits.CH0NB = 0; // pos channel select (not used with scanning)
   AD1CHSbits.CH0SB = 0b0000; // not used with scanning
   AD1CHSbits.CH0NA = 0; // Vr- not used with scanning
   AD1CHSbits.CH0SA = 0b0000; // neg channel select (not used with scanning)


   analog_src_mask = analog_info[analog_src_num].ANmask;

   // special case for LEDS. normally are outputs, reconfig as inputs for led hack
   // RB3=green, RC0 == red, RC1= blue
   if (analog_src_mask & AN_RED_MASK) {
	ANSELCbits.ANSC0 = 1;
	TRISCbits.TRISC0 = 1; 
   } else {
	ANSELCbits.ANSC0 = 0;
	TRISCbits.TRISC0 = 0; 
   }

   if (analog_src_mask & AN_GREEN_MASK) {
	ANSELBbits.ANSB3 = 1; 
	TRISBbits.TRISB3 = 1; 
   } else {
	ANSELBbits.ANSB3 = 0;
	TRISBbits.TRISB3 = 0;
   }

   if (analog_src_mask & AN_BLUE_MASK) {
	ANSELCbits.ANSC1 = 1;
	TRISCbits.TRISC1 = 1; 
   } else {
	ANSELCbits.ANSC1 = 0;
	TRISCbits.TRISC1 = 0; 
   }

   AD1CSSLbits.CSSL = analog_src_mask; // scan bit mask

   IPC5bits.AD1IP = 4; // priority 4
   IPC5bits.AD1IS = 0;  // sub pri. 0 // No need for sub bcs no shared interrupts right now

   AD1CON1bits.ASAM = 1; // ** auto sample
   AD1CON1bits.ON = 1;   // adc on
 
   IEC0bits.AD1IE = 1; // enable interrupt
}

// {IPL4}SOFT == overwritten registers are shadow by software. 
// Some pic32 have shadow regs. for interrupts for speed purposes
void __ISR(_ADC_VECTOR, IPL4SOFT) ADC_handler(void)
{
   int krap;

   if (ADCbufferCnt == ADC_BUFFER_SIZE) {
	if  (ADCbufferCntMark != 0) { // signal from user that buffer is processed
	   ADCbufferCntMark = 0;
	   ADCbufferCnt = 0;
	}
	else
	   ADCbufferCnt -= 8; // reset to last buffer. user not done
   }

   // note: the ADC is only 10bits. top bits are zero
   // BUFS==1: ADC buffer 8-15 are full. 
   // but have to read them all or the interrupt won't clear. see "persistant interrupts"
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

#define FOSC 40000000.0

unsigned char calc_adcs(unsigned char chans,  int hz, unsigned char *samc_out) {
   float adcs;
   unsigned char samc;

   for (samc=31; samc>2; samc--) {
	// (FOSC.fosc/((2 * 12)*(SAMC.samc+12)/12)/ADC_HZ.adc_hz/CHANNELS.chans-1) as ADCS
	adcs = (((FOSC / ((2.0 * 12.0)*( (float)(samc) + 12.0)/12.0)) / (float)hz) / (float)(chans)) - 1;
	if (adcs - floor(adcs + 0.09) < 0.01) {
	    adcs = floor(adcs + 0.09);
	    break;
	}
	if (adcs - floor(adcs) < 0.09) {
	   adcs = floor(adcs);
	   break;
	}
   }
   if (adcs > 255) adcs = 255; // register is only 8 bits. results TBD
   *samc_out = samc;
   return (unsigned char)adcs;
}
