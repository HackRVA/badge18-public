
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
    RUBIX_CYAN=0,
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

//rubix cursor location
void rubix_cursor(struct _cursor pos);

struct _rubix {
    unsigned char state;
    unsigned char side_order[6];
    unsigned char input_mode;
    struct _cursor cursor;
};



struct _rubix rubix = {RUBIX_INIT,{0,1,2,3,4,5},0,{0,0,0}};

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
//[SIDE][y][x]
//initialize empty screen as white and set defaults in control
void rubix_init(void) {
    rubix.state = RUBIX_RENDER;
    unsigned char blk_clr;
    unsigned char blk_index=0;
    unsigned char blk_x;
    unsigned char blk_y;
    for(blk_clr = RUBIX_CYAN;blk_clr < (RUBIX_YELLOW+1); blk_clr++) {
        for(blk_y=0;blk_y<4;blk_y++) {
            for(blk_x=0;blk_x<4;blk_x++) {
                rubix_cube[blk_index][blk_y][blk_x]=blk_clr;
            }
        }
        rubix.side_order[blk_index]=blk_index;
        blk_index++;
    }
    FbBackgroundColor(BLACK);
    FbClear();
}

unsigned short rubix_color_to_short(unsigned char rubix_clr) {
    switch(rubix_clr) {
        case RUBIX_CYAN:
            return CYAN;
        case RUBIX_WHITE:
            return WHITE;
        case RUBIX_RED:
            return RED;
        case RUBIX_GREEN:
            return GREEN;
        case RUBIX_BLUE:
            return BLUE;
        case RUBIX_YELLOW:
            return YELLOW;
        default:
            return BLACK;
    }
}

unsigned short rubix_get_block_color(unsigned char side,unsigned char x, unsigned char y) {
    unsigned short rubix_shrt_color = rubix_color_to_short(rubix_cube[side][x][y]);
    return rubix_shrt_color;
}

rubix_draw_cursor(void) {
    FbColor(MAGENTA);
    if(rubix.cursor.y < 3) {
        FbMove(rubix.cursor.x*32+14,rubix.cursor.y*32+9);
        FbRectangle(31,31);
    }
    if(rubix.cursor.y == 3) {
        if(rubix.cursor.x == 0) {
            FbMove(14,105);
            FbRectangle(63,21);
        }
        else {
            FbMove(78,105);
            FbRectangle(31,21);
        }
    }
}

//render all pixels and cursor to the display
void rubix_render(void) {
    rubix.state = RUBIX_GET_INPUT;
    FbMove(15,10);
    FbColor(rubix_get_block_color(rubix.side_order[0],0,0));
    FbFilledRectangle(30,30);
    FbMove(47,10);
    FbColor(rubix_get_block_color(rubix.side_order[0],0,1));
    FbFilledRectangle(30,30);
    FbMove(79,10);
    FbColor(rubix_get_block_color(rubix.side_order[0],0,2));
    FbFilledRectangle(30,30);
    FbMove(15,42);
    FbColor(rubix_get_block_color(rubix.side_order[0],1,0));
    FbFilledRectangle(30,30);
    FbMove(47,42);
    FbColor(rubix_get_block_color(rubix.side_order[0],1,1));
    FbFilledRectangle(30,30);
    FbMove(79,42);
    FbColor(rubix_get_block_color(rubix.side_order[0],1,2));
    FbFilledRectangle(30,30);
    FbMove(15,74);
    FbColor(rubix_get_block_color(rubix.side_order[0],2,0));
    FbFilledRectangle(30,30);
    FbMove(47,74);
    FbColor(rubix_get_block_color(rubix.side_order[0],2,1));
    FbFilledRectangle(30,30);
    FbMove(79,74);
    FbColor(rubix_get_block_color(rubix.side_order[0],2,2));
    FbFilledRectangle(30,30);
    FbColor(WHITE);
    FbMove(15,106);
    FbFilledRectangle(62,20);
    FbMove(79,106);
    FbFilledRectangle(30,20);
    FbColor(BLUE);
    FbMove(80,111);
    FbWriteLine("Exit");
    FbColor(RED);
    FbMove(17,111);
    FbWriteLine("Restart");
    rubix_draw_cursor();
    FbSwapBuffers();
}


//get inputs and set data accordingly
void rubix_get_input(void) {
    rubix.state = RUBIX_PROCESS;
    if(rubix.input_mode) {
        if(BUTTON_PRESSED_AND_CONSUME) {
            if(rubix.cursor.y<3) {
                rubix.input_mode = !rubix.input_mode;
            }
            if(rubix.cursor.y == 3 && rubix.cursor.x == 1) {
                rubix.state = RUBIX_EXIT;
            }
            if(rubix.cursor.y == 3 && rubix.cursor.x == 0) {
                rubix.state = RUBIX_INIT;
            }
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
    else {
        if(BUTTON_PRESSED_AND_CONSUME) {
            if(rubix.cursor.y<3) {
                rubix.input_mode = !rubix.input_mode;
            }
            if(rubix.cursor.y == 3 && rubix.cursor.x == 1) {
                rubix.state = RUBIX_EXIT;
            }
            if(rubix.cursor.y == 3 && rubix.cursor.x == 0) {
                rubix.state = RUBIX_INIT;
            }
        }
        if(DOWN_BTN) {
            if(rubix.cursor.y < 3) {
                rubix.cursor.y++;
            }
            if(rubix.cursor.y == 3) {
                rubix_rotate_cube(ROT_DOWN);
            }
        }
        if(UP_BTN) {
            if(rubix.cursor.y > 0) {
                rubix.cursor.y--;
            }
            if(rubix.cursor.y == 0) {
                rubix_rotate_cube(ROT_UP);
            }
        }
        if(LEFT_BTN) {
            if(rubix.cursor.x > 0) {
                rubix.cursor.x--;
            }
            if(rubix.cursor.x == 0) {
                rubix_rotate_cube(ROT_LEFT);
            }
        
        }
        if(RIGHT_BTN) {
            if(rubix.cursor.x < 2) {
                rubix.cursor.x++;
            }
            if(rubix.cursor.x == 2) {
                rubix_rotate_cube(ROT_RIGHT);
            }
            if(rubix.cursor.y == 3 && rubix.cursor.x == 1) {
                rubix_rotate_cube(ROT_RIGHT);
            }
        }
        if(DOWN_TOUCH_AND_CONSUME) {
        
        }
        if(UP_TOUCH_AND_CONSUME) {
        
        }
        if(rubix.cursor.y == 3 && rubix.cursor.x > 1) {
                rubix.cursor.x = 1;
        }
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
    unsigned char tmp_index = 0;
    switch (rot_direction) {
        case ROT_LEFT:
            tmp_index = rubix.side_order[1];
            rubix.side_order[1] = rubix.side_order[0];
            rubix.side_order[0] = rubix.side_order[3];
            rubix.side_order[3] = rubix.side_order[5];
            rubix.side_order[5] = tmp_index;
            rubix_rotate_face(rubix.side_order[2],CW);
            rubix_rotate_face(rubix.side_order[4],CCW);
            rubix_rotate_face(rubix.side_order[3],CW);
            rubix_rotate_face(rubix.side_order[3],CW);
            rubix_rotate_face(rubix.side_order[5],CW);
            rubix_rotate_face(rubix.side_order[5],CW);
            break;
        case ROT_RIGHT:
            tmp_index = rubix.side_order[3];
            rubix.side_order[3] = rubix.side_order[0];
            rubix.side_order[0] = rubix.side_order[1];
            rubix.side_order[1] = rubix.side_order[5];
            rubix.side_order[5] = tmp_index;
            rubix_rotate_face(rubix.side_order[2],CCW);
            rubix_rotate_face(rubix.side_order[4],CW);
            rubix_rotate_face(rubix.side_order[1],CW);
            rubix_rotate_face(rubix.side_order[1],CW);
            rubix_rotate_face(rubix.side_order[5],CW);
            rubix_rotate_face(rubix.side_order[5],CW);
            break;
        case ROT_UP:
            tmp_index = rubix.side_order[2];
            rubix.side_order[2] = rubix.side_order[0];
            rubix.side_order[0] = rubix.side_order[4];
            rubix.side_order[4] = rubix.side_order[5];
            rubix.side_order[5] = tmp_index;
            rubix_rotate_face(rubix.side_order[1],CCW);
            rubix_rotate_face(rubix.side_order[3], CW);
            break;
        case ROT_DOWN:
            tmp_index = rubix.side_order[5];
            rubix.side_order[5] = rubix.side_order[4];
            rubix.side_order[4] = rubix.side_order[0];
            rubix.side_order[0] = rubix.side_order[2];
            rubix.side_order[2] = tmp_index;
            break;
        default:
            break;
    }
    
}

void rubix_move_collumn(unsigned char collumn_number, unsigned char up_down) {//up = 1 down = 0
    
}

void rubix_move_row(unsigned char row_number, unsigned char direction) {
    
}


