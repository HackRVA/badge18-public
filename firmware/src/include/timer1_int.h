#ifndef timer1_int_h
#define timer1_int_h
void red(unsigned char onPWM) ;
void green(unsigned char onPWM) ;
void blue(unsigned char onPWM) ;
void led(unsigned char r, unsigned char g, unsigned char b);
void backlight(unsigned char bright) ;
void led_input_hack(unsigned char OnOff) ; // use LEDs as inputs
void timerInit();

void beginNote(unsigned short freq);
void endNote();

extern unsigned char G_led_input_hack;
#endif

