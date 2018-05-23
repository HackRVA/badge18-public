#include "app.h"
#include "buttons.h"
#include "adc.h"

unsigned char G_pressed_button = 0;

// Solo bottom right btn
unsigned char G_button_cnt = 0;

// D-Pad
unsigned char G_up_button_cnt = 0;
unsigned char G_down_button_cnt = 0;
unsigned char G_left_button_cnt = 0;
unsigned char G_right_button_cnt = 0;

// Cap Touch
unsigned char G_up_touch_cnt = 0;
unsigned char G_middle_touch_cnt = 0;
unsigned char G_down_touch_cnt = 0;
char G_touch_pct = 0;


unsigned int G_entropy_pool = 961748927;
unsigned int timestamp = 0;
unsigned int last_input_timestamp = 0;

// 
// the initial version of this is from example 37-3 of pic32_pdfs/pic32-sec37-ctmu-61167B.pdf
// 



void init_CTMU18()
{
    /* setup analog pins */
    TRISBbits.TRISB2 = 1; //AN4 
    ANSELBbits.ANSB2 = 1; // RB2
    // wait because...?
    vTaskDelay(1 / portTICK_PERIOD_MS);
    // CTMU Setup
    CTMUCONbits.IRNG = 3;  // 1 = 0.55uA 2 = 5.5uA 3 = 55uA 0 = 550uA
    CTMUCONbits.ON = 1;    // Turn on CTMU
    vTaskDelay(1 / portTICK_PERIOD_MS);    // Wait 1 msec

    // ADC Setup
    AD1CON2 = 0x0; // VR+ = AVDD, V- = AVSS, Don't scan, MUX A only

    // ADC clock derived from peripheral buss clock
    // Tadc = 4 * Tpbus = 4 * 25 ns = 100 ns > 65 ns required
    // Tadc = 2*(    1       +1)*Tpbus
    // Tadc = 2*(AD1CON3<7:0>+1)*Tpbus
    AD1CON3 = 1;          // PEB 16 * Tpb;
// WTF   AD1CON3bits.ADRC = 0; // PBCLK. clock source is FRC or PBCLK
// WTF   AD1CON3bits.SAMC = 0b10000; // Tad = 1..31
// WTF   AD1CON3bits.ADCS = 0b00010000; // needed for autoconvert. conversion clock select

    // 2018 XXX    AD1CSSL = 0x0;        // No channels scanned
    IEC0bits.AD1IE = 0;   // Disable ADC interrupts
    AD1CON1bits.ON = 1;   // Turn on ADC
}


void button_task(void* p_arg)
{
#define BADGE_2018

    const unsigned char ButtonADCChannels[2] = {3,4};
    const unsigned char n_averages = 4, log2_n_averages = 2;
    unsigned short int ButtonVavgADCs[2]={0,0};
    
    
    unsigned short int VmeasADC; // Measured Voltages, 65536 = Full Scale
    unsigned long int ADC_Sum; // For averaging multiple ADC measurements
    unsigned char i = 0, chan_idx = 0;

    TickType_t xDelay = 5 / portTICK_PERIOD_MS;
    
//#define ADC_TOUCH    
#define CTMU_TOUCH
    // Two ways:
    // (1) Use raw ADC values on the pad to gauge touch
    //      - Probably not as accurate, or might require more ops
    // (2) Use CTMU
    //      - Drawback: Have to toggle between ADC and CTMU modes?
    
    // Use ADC_init

#ifdef ADC_TOUCH
#define CHANNEL 0
#define N_CHANNELS 4
    
    init_CTMU18();
    unsigned short i=0;
    static unsigned short touch_adc_val=0;
    
    static unsigned char bcnt = 0;
#endif
 
char words[8]={'.', '\n', '\0', 0, 0, 0, 0, 0};

#ifdef CTMU_TOUCH    
    init_CTMU18();
#endif
    for(;;){
        timestamp++;
#ifdef ADC_TOUCH
        if(ADCbufferCntMark == 0){
            if (ADCbufferCnt >= ADC_BUFFER_SIZE ){
                for(i=0; i < ADC_BUFFER_SIZE; i+=N_CHANNELS){
                    touch_adc_val = ADCbuffer[i+CHANNEL];

                    itoa(words, (int)touch_adc_val, 10);
                    
                    print_to_com1(words);
                    print_to_com1("\n\0");
                    vTaskDelay(50/portTICK_PERIOD_MS);  
                }
                ADCbufferCntMark = 1; 
            }
        }

        //print_to_com1(words);
        //print_to_com1("\n\0");
        //vTaskDelay(100/portTICK_PERIOD_MS);   
#endif
        
  
#ifdef CTMU_TOUCH
        #define AN4 ButtonVavgADCs[1]
        //------------------
        //---CTMU---
        //for(chan_idx=0; chan_idx < 2; chan_idx++)
        chan_idx = 1;
        {
            //AD1CHSbits.CH0SA = ButtonADCChannels[chan_idx];
            AD1CHSbits.CH0SA = 4;
            for(i=0; i < n_averages; i++)
            {
                //CTMUCONCLR = 0x03000000;
                AD1CON1bits.SAMP = 1;
                CTMUCONbits.IDISSEN = 1;
                vTaskDelay(1 / portTICK_PERIOD_MS);
                CTMUCONbits.IDISSEN = 0;

                // TODO: CHECK THESE STEPS against docs
                CTMUCONbits.EDG1STAT = 1; // Begin charging the circuit
                unsigned char nops;
                // TODO: Can we give up less time to make this faster?
                // Or give longer sleep for coop with other tasks
                for(nops=0; nops < 10; nops++); 
                AD1CON1bits.SAMP = 0;     // Begin analog-to-digital conversion
                CTMUCONbits.EDG1STAT = 0; // Stop charging circuit
                while(!(AD1CON1bits.DONE))
                {

                }
                AD1CON1bits.DONE = 0; // ADC conversion done, clear flag
                VmeasADC = ADC1BUF0;  // Get the value from the ADC
                ADC_Sum += VmeasADC;  // Update averaging sum                
            }
            
            if ( log2_n_averages-6 > 0 )
                ButtonVavgADCs[chan_idx] = ADC_Sum >> (log2_n_averages-6); // Full scale = 2^10<<6 = 65536
            else 
                ButtonVavgADCs[chan_idx] = ADC_Sum << (6-log2_n_averages); // Full scale = 2^10<<6 = 65536

            // May be mixing too often...
            G_entropy_pool = (ADC_Sum ^ 
                    ((G_entropy_pool)<<(0xF&timestamp)) ^
                    (timestamp));
            ADC_Sum = 0;
        }      
                 
        char tmp_touch = ((char)(AN4 >> 6)) - 35;
        if( tmp_touch > 100 )
            tmp_touch = 100;
        else if( tmp_touch < 0 )
            tmp_touch = 0;
        
        G_touch_pct = tmp_touch;
#define NULL_TOUCH_BTN_THRESH 9000
//#define LOW_TOUCH_BTN_THRESH 5800
#define LOW_TOUCH_BTN_THRESH 6800
#define HIGH_TOUCH_BTN_LOWER_THRESH 7200        
#define HIGH_TOUCH_BTN_UPPER_THRESH 8100        
        if((AN4 < LOW_TOUCH_BTN_THRESH)){
            if(G_down_touch_cnt < 255)
                G_down_touch_cnt++;

            G_middle_touch_cnt = G_up_touch_cnt = 0;
        }
//        else if( (AN4 >= LOW_TOUCH_BTN_THRESH) 
//                && (AN4 < HIGH_TOUCH_BTN_THRESH)){
//            if(G_middle_touch_cnt < 255)
//                G_middle_touch_cnt++;
//            G_up_touch_cnt = G_down_touch_cnt = 0;
//        }
        else if( (AN4 >= HIGH_TOUCH_BTN_LOWER_THRESH)
                && (AN4 < HIGH_TOUCH_BTN_UPPER_THRESH)){
            if(G_up_touch_cnt < 255)
                G_up_touch_cnt++;
            
            G_middle_touch_cnt = G_down_touch_cnt = 0;
        }
        else{
            G_up_touch_cnt = G_down_touch_cnt = G_middle_touch_cnt = G_touch_pct =0;
            REMOVE_FROM_MASK(G_pressed_button, ALL_TOUCH_MASK);
        }
        //itoa(words, (int)G_touch_pct, 10);
//        itoa(words, (int)AN4, 10);
//        print_to_com1(words);
//        print_to_com1("\n\0");
//        vTaskDelay(50/portTICK_PERIOD_MS);  
#endif
        
        
    //---------------------
    //---Tactile Buttons---
    // If btn is being pressed
    //   - increment its counter, but don't overflow
    // else if btn is not being pressed
    //   - Zero its counter and zero out 'pressed' bit flag
        
        // Standalone button
// 2018        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_C,PORTS_BIT_POS_3)){
        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_C,PORTS_BIT_POS_4)){
            if(G_button_cnt < 255)
                G_button_cnt++;
        }
        else{
            G_button_cnt = 0;
            REMOVE_FROM_MASK(G_pressed_button, SOLO_BTN_MASK);
        }
        
        //UP:
        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_B,PORTS_BIT_POS_14)){
            if(G_up_button_cnt < 255)
                G_up_button_cnt++;
        }
        else{
            
            G_up_button_cnt = 0;
            REMOVE_FROM_MASK(G_pressed_button, UP_BTN_MASK);
        }
        
        //LEFT:
        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_B,PORTS_BIT_POS_15)){
            if(G_left_button_cnt < 255)
                G_left_button_cnt++;
        }
        else{
            G_left_button_cnt = 0;
            REMOVE_FROM_MASK(G_pressed_button, LEFT_BTN_MASK);
        }
        
        //RIGHT:
        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_0)){
            if(G_right_button_cnt < 255)
                G_right_button_cnt++;
        }
        else{
            G_right_button_cnt = 0;
            REMOVE_FROM_MASK(G_pressed_button, RIGHT_BTN_MASK);
        }
        
        //DOWN:
        if(!PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_1))
            G_down_button_cnt++;
        else{
            G_down_button_cnt = 0;
            REMOVE_FROM_MASK(G_pressed_button, DOWN_BTN_MASK);
        }
        
        if(DOWN_BTN || UP_BTN || LEFT_BTN || RIGHT_BTN || (G_button_cnt > DEFAULT_BTN_DBC)){
            last_input_timestamp = timestamp;
        }

        vTaskDelay(xDelay);
    }
}


void clear_buttons(){
    
    G_button_cnt = 0;
    G_up_button_cnt = 0;
    G_down_button_cnt = 0;
    G_left_button_cnt = 0;
    G_right_button_cnt = 0;
    
    G_up_touch_cnt = 0;
    G_middle_touch_cnt = 0;
    G_down_touch_cnt = 0;
    G_touch_pct = 0;
}
