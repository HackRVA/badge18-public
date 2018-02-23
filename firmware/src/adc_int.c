#include <plib.h>

void adc_int()
{
   // MIC_INPUT RC3 / AN12
   // TRISCbits.TRISC3 = 1; // mic is an analog input

   // RF_IN     RB1 / AN3
   // RF_POWER =1; turn on RF
   // TRISBbits.TRISB1 = 1; // RF input is analog

   // touch in  RB2 / AN4
   // TRISBbits.TRISB2 = 1; // touch pad input
            
   AD1CON1bits.ON = 1;   // adc on
   AD1CON1bits.SIDL = 1; // stop in idle mode
   AD1CON1bits.FORM = 0b000; // results are integers
   AD1CON1bits.SSRC = 0b111; // auto sample & start
   AD1CON1bits.CLRASAM = 0b0; // buffer will be overwritten next sample
   AD1CON1bits.ASAM = 0b1; // auto sample
   AD1CON1bits.DONE = 0; // not really needed, handle automatically

   AD1CON2bits.VCFG = 0; // use Vdd and Vss for voltage refs
   AD1CON2bits.OFFCAL = 0; // disable calibration mode
   AD1CON2bits.CSCNA = 1; // *** scan all analoginputs when auto sampling
   AD1CON2bits.BUFS = 0; // indicates which buffer is being filled
   AD1CON2bits.SMPI = 8; // interupt and the end of 8 samples
   AD1CON2bits.BUFM = 1; // double buffered, one for ADC, one for copy out
   AD1CON2bits.ALTS = 0; // don't alternate between mux A/B for sample. used for differential IO

   AD1CON3bits.ADRC = 0; // PBCLK. clock source is FRC or PBCLK
   AD1CON3bits.SAMC = 0b10000; // Tad = 1..31
   AD1CON3bits.ADCS = 0b00010000; // needed for autoconvert. conversion clock select

   AD1CHSbits.CH0NB = 0; // pos channel select not use with scanning
   AD1CHSbits.CH0SB = 0b0000; // neg channel select not use with scanning
   AD1CHSbits.CH0NA = 0; // pos channel select not use with scanning
   AD1CHSbits.CH0SA = 0b0000; // neg channel select not use with scanning

   AD1CSSLbits.CSSL = 0b1000000011000; // AN0-AN12 bit mask
   
   IEC0bits.AD1IE = 0; // disable interrupt
   IFS0bits.AD1IF = 1; // clear flag
   IPC5bits.AD1IP = 0b011; // priority 3
   IPC5bits.AD1IS = 0b01;  // sub pri. 1
   IEC0bits.AD1IE = 1; // enable interrupt

//   IPS6SET = 0x0014; // Set Priority to 5
//   IPS6SET = 0x0003; // Set Sub Priority to 3
//   IFS1CLR = 0x0002; // Ensure the interrupt flag is clear
//   IEC1SET = 0x0002; // Enable ADC interrupts
 
}


void __ISR(_ADC_VECTOR, IPL3) ADC_handler(void)
{
   IFS0bits.AD1IF = 0; // clear int
}
