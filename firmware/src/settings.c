#include <plib.h>
#include "string.h"
#include "flash.h"
#include "badge_menu.h"
#include "buttons.h"
//#include "stopwatch.h"
//#include "display.h"
#include "ir.h"
#include "fb.h"

extern unsigned short pinged;
extern unsigned short ping_responded;
void ping_cb(){
    static unsigned char num_pinged = 0;
    if(!num_pinged){
        FbClear();
        FbSwapBuffers();
        //FbMove(50, 100);
        //FbWriteLine("No response");
        union IRpacket_u pkt;
        pkt.p.command = IR_WRITE;
        pkt.p.address = IR_PING;
        pkt.p.badgeId = 0;
        pkt.p.data = PING_REQUEST;
        IRqueueSend(pkt);
        num_pinged++;
    }
    
    if(ping_responded)
    {
        unsigned char bid[4] = {'0' + ping_responded/100 % 10,
                                '0' + ping_responded/10 % 10,
                                '0' + ping_responded % 10,
                                0};

        FbMove(10, 10 + ((num_pinged-1)*10));
        FbWriteLine(bid);
        FbPushBuffer();
        blue(100);
        ping_responded = 0;
    }

    if(BUTTON_PRESSED_AND_CONSUME){
        blue(0);
        num_pinged = 0;
    }
}

/*
    set badge Id
*/
void myBadgeid_cb(struct menu_t *h) {
   struct menu_t *selectedMenu;
   extern const char hextab[];

   //dstMenu = getSelectedMenuStack(1);
   selectedMenu = getSelectedMenu();

   selectedMenu->name[0] = hextab[((G_sysData.badgeId >> 12) & 0xF)];
   selectedMenu->name[1] = hextab[((G_sysData.badgeId >>  8) & 0xF)];
   selectedMenu->name[2] = hextab[((G_sysData.badgeId >>  4) & 0xF)];
   selectedMenu->name[3] = hextab[((G_sysData.badgeId      ) & 0xF)];
   selectedMenu->name[4] = 0;
   //strcpy(dstMenu->name, selectedMenu->name);

}

struct menu_t myBadgeid_m[] = {
    {"check",   VERT_ITEM, FUNCTION, {(struct menu_t *)myBadgeid_cb} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};

/*
    peer we want to talk to
*/
void peerBadgeid_cb(struct menu_t *h) {
   struct menu_t *dstMenu, *selectedMenu;

   dstMenu = getSelectedMenuStack(1);
   selectedMenu = getSelectedMenu();

   /* update calling menu's name field */
   G_peerBadgeId = selectedMenu->attrib & 0xFF;

   strcpy(dstMenu->name, selectedMenu->name);
}


const struct menu_t peerBadgeNum_m[] = {
    {"ALL", 0|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  1", 1|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  2", 2|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  3", 3|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  4", 4|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  5", 5|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  6", 6|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  7", 7|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"  8", 8|VERT_ITEM, FUNCTION, {(struct menu_t *)peerBadgeid_cb} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};

struct menu_t peerBadgeid_m[] = {
    {"0",   VERT_ITEM, MENU, {peerBadgeNum_m} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};


/*
    backlight
*/
void backlight_cb(struct menu_t *h) {
   struct menu_t *dstMenu, *selectedMenu;

   dstMenu = getSelectedMenuStack(1);
   selectedMenu = getSelectedMenu();

   /* update calling menu's name field */
   strcpy(dstMenu->name, selectedMenu->name);

   G_sysData.backlight = selectedMenu->attrib & 0x1FF;
   backlight(G_sysData.backlight);
   led(0, 100, 10);
}

const struct menu_t backlightList_m[] = {
//    {"       ", 0|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} }, oh support... why is my screen black?
    {"      -",  16|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {"     --",  32|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {"    ---",  64|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {"   ----", 128|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {"  -----", 192|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {" ------", 224|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },
    {"-------", 255|VERT_ITEM, FUNCTION, {(struct menu_t *)backlight_cb} },

    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};

struct menu_t backlight_m[] = {
    {"-------",   VERT_ITEM,     MENU, {backlightList_m} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};


/*
   rotate screen
*/
void rotate_cb(struct menu_t *h) {
    unsigned char rotated=0;
    struct menu_t *selectedMenu;
    extern unsigned char G_outputMode;
    extern unsigned char G_entry; 

    selectedMenu = getSelectedMenu();

    rotated = selectedMenu->attrib & 0x1FF;
    if (rotated) {
	G_outputMode = 0b00000111; /* CDIR=1 */
	G_entry = 0b10000010; /* Y=Yend -> X incremented */
    }
    else {
	/* old way */
	G_outputMode = 0b00000110; /* CDIR=0 */
	G_entry = 0b10000000; /* X=Xend -> Y incremented */
    }

    LCDReset();
};

const struct menu_t rotate_m[] = {
    {" default",   0|VERT_ITEM, FUNCTION, {(struct menu_t *)rotate_cb} },
    {" rotated",   1|VERT_ITEM, FUNCTION, {(struct menu_t *)rotate_cb} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};



/*
    LED brightness
*/
void LEDlight_cb(struct menu_t *h) {
    void led_brightness(unsigned char bright) ;
    struct menu_t *dstMenu, *selectedMenu;
    extern unsigned char G_red_pwm, G_green_pwm, G_blue_pwm;

    dstMenu = getSelectedMenuStack(1);
    selectedMenu = getSelectedMenu();

    strcpy(dstMenu->name, selectedMenu->name);

    G_sysData.ledBrightness = selectedMenu->attrib & 0x1FF;
    led_brightness(G_sysData.ledBrightness);
    /* because of calcs done on pwm, 
       have to reload the values for
       it to take effect. because of division, 
       info is lost in this process
    */
    red(G_red_pwm);
    green(G_green_pwm);
    blue(G_blue_pwm);
}


const struct menu_t LEDlightList_m[] = {
    {"       ", 7|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"      -", 6|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"     --", 5|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"    ---", 4|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"   ----", 3|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"  -----", 2|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {" ------", 1|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"-------", 0|VERT_ITEM, FUNCTION, {(struct menu_t *)LEDlight_cb} },
    {"Back", VERT_ITEM|LAST_ITEM| DEFAULT_ITEM, BACK, {NULL} },
};

struct menu_t LEDlight_m[] = {
    {"--------",   VERT_ITEM,     MENU, {LEDlightList_m} },
    {"Back", VERT_ITEM|LAST_ITEM| DEFAULT_ITEM, BACK, {NULL} },
};

extern unsigned short G_mute;
void buzzer_config_cb()
{
    struct menu_t *dstMenu, *selectedMenu;
    extern unsigned char G_red_pwm, G_green_pwm, G_blue_pwm;

    dstMenu = getSelectedMenuStack(1);
    selectedMenu = getSelectedMenu();

    strcpy(dstMenu->name, selectedMenu->name);

    G_mute = selectedMenu->attrib & 0x1;
}

struct menu_t buzzer_config_m[] = {
    {"Buzzer: On",   0|VERT_ITEM,     FUNCTION, {(struct menu_t *)buzzer_config_cb} },
    {"Buzzer: Off",  1|VERT_ITEM,     FUNCTION, {(struct menu_t *)buzzer_config_cb} },
    {"Back", VERT_ITEM|LAST_ITEM| DEFAULT_ITEM, BACK, {NULL} },
};

struct menu_t buzzer_m[] = {
    {"Buzzer: On",   VERT_ITEM,     MENU, {buzzer_config_m} },
    {"Back", VERT_ITEM|LAST_ITEM|DEFAULT_ITEM, BACK, {NULL} },
};


