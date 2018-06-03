
/*******************************************************************************
 * Author: Jonathan Lundquist / jonathan46000@gmail.com
 * Date: 5-28-18
 ******************************************************************************/

#include "app.h"
#include "colors.h"
#include "fb.h"
#include "assetList.h"
#include "buttons.h"
#include "utils.h"
#include "ir.h"

#define SCREEN_WIDTH 128                //width of samsung display
#define STORE 1
#define PUT 0
#define RIGHT 1
#define LEFT 0
#define CW 1
#define CCW 0
#define UP 1
#define DOWN 0

enum {                                  //rubix color control enumerator
    RUBIX_BLACK=0,
    RUBIX_WHITE,
    RUBIX_RED,
    RUBIX_GREEN,
    RUBIX_BLUE,
    RUBIX_YELLOW,
};

enum {
    ROT_UP,
    ROT_DOWN,
    ROT_LEFT,
    ROT_RIGHT,
};

enum {
    RUBIX_INIT,
    RUBIX_RENDER,
    RUBIX_GET_INPUT,
    RUBIX_EXIT,
    RUBIX_PROCESS,
};


//App control structs
struct _cursor {                        //cursor position
    unsigned char x;
    unsigned char y;                                       
    unsigned char moved;                //cursor moved true or false
};

//Game State Functions
void rubix_init(void);
void rubix_render(void);
void rubix_get_input(void);
void rubix_exit(void);
void rubix_process(void);

unsigned char rubix_cube[6][3][3];
unsigned char tmp_face[3][3];

//rubix cursor location
void rubix_cursor(struct _cursor pos);

struct _rubix {
    unsigned char state;
    unsigned char side_order[6];
    struct _cursor cursor;
};



struct _rubix rubix = {RUBIX_INIT,{0,1,2,3,4,5},{0,0,0}};

//app loop
void rubix_task(void *p_arg){
    static unsigned char init = 1;
    if(init) {
        init=0;
    }
    for(;;) {
        switch(rubix.state) {
            case RUBIX_INIT:
                rubix_init();
                break;
            case RUBIX_RENDER:
                rubix_render();
                break;
            case RUBIX_GET_INPUT:
                rubix_get_input();
                break;
            case RUBIX_EXIT:
                rubix_exit();
                break;
            case RUBIX_PROCESS:
                rubix_process();
                break;
            default:
                rubix_exit();
        }
    } 
}

//initialize empty screen as white and set defaults in control
void rubix_init(void) {
    rubix.state = RUBIX_RENDER;
    FbBackgroundColor(BLACK);
    FbClear();
}

//render all pixels and cursor to the display
void rubix_render(void) {
    rubix.state = RUBIX_GET_INPUT;
    FbSwapBuffers();
}

//get inputs and set data accordingly
void rubix_get_input(void) {
    rubix.state = RUBIX_PROCESS;
    if(BUTTON_PRESSED_AND_CONSUME) {
        
    }
    if(DOWN_BTN) {
        
    }
    if(UP_BTN) {
        
    }
    if(LEFT_BTN) {
        
    }
    if(RIGHT_BTN) {
        
    }
    if(DOWN_TOUCH_AND_CONSUME) {
        
    }
    if(UP_TOUCH_AND_CONSUME) {
        
    }
}

//process data based on what changed in rubix_get_input
void rubix_process() {
    rubix.state = RUBIX_RENDER;
    
}

//sets function pointer and returns to menus
void rubix_exit(void) {
    rubix.state = RUBIX_RENDER;
    returnToMenus();
}

void rubix_store_put_face(unsigned char face_index, unsigned char store) {
    unsigned char i, j;
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++){
            if(store) {
                tmp_face[i][j] = rubix_cube[face_index][i][j];
            }
            else {
                rubix_cube[face_index][i][j] = tmp_face[i][j];
            }
        }
    }
}

void rubix_rotate_face(unsigned char face_index, unsigned char direction) { //right = 1 //left = 0 right is cw left is ccw
    unsigned char tmp;
    if(direction) {
        tmp = rubix_cube[face_index][0][2];
        rubix_cube[face_index][0][2] = rubix_cube[face_index][0][1];
        rubix_cube[face_index][0][1] = rubix_cube[face_index][0][0];
        rubix_cube[face_index][0][0] = rubix_cube[face_index][1][0];
        rubix_cube[face_index][1][0] = rubix_cube[face_index][2][0];
        rubix_cube[face_index][2][0] = rubix_cube[face_index][2][1];
        rubix_cube[face_index][2][1] = rubix_cube[face_index][2][2];
        rubix_cube[face_index][2][2] = rubix_cube[face_index][1][2];
        rubix_cube[face_index][1][2] = tmp;
    }
    else {
        tmp = rubix_cube[face_index][0][0];
        rubix_cube[face_index][0][0] = rubix_cube[face_index][0][1];
        rubix_cube[face_index][0][1] = rubix_cube[face_index][0][2];
        rubix_cube[face_index][0][2] = rubix_cube[face_index][1][2];
        rubix_cube[face_index][1][2] = rubix_cube[face_index][2][2];
        rubix_cube[face_index][2][2] = rubix_cube[face_index][2][1];
        rubix_cube[face_index][2][1] = rubix_cube[face_index][2][0];
        rubix_cube[face_index][2][0] = rubix_cube[face_index][1][0];
        rubix_cube[face_index][1][0] = tmp;
    }
}

void rubix_rotate_cube(unsigned char rot_direction) {//ROT_UP ROT_DOWN ROT_LEFT ROT_RIGHT
    //use the envelope and rotate face/ store put face functions to do this 
    switch (rot_direction) {
        case ROT_LEFT:
            
            break;
        case ROT_RIGHT:
            
            break;
        case ROT_UP:
            
            break;
        case ROT_DOWN:
            
            break;
        default:
            break;
    }
    
}

void rubix_move_collumn(unsigned char collumn_number, unsigned char up_down) {//up = 1 down = 0
    
}

void rubix_move_row(unsigned char row_number, unsigned char direction) {
    
}


