//#define SDL_BADGE

#include "colors.h"

#ifdef SDL_BADGE
#include "sdl_fb.h"
#include "sdl_buttons.h"
#else
#include "app.h"
#include "fb.h"
#include "buttons.h"
#endif
//#include "rgb_led.h"
#include "utils.h"
#include <math.h>
#include <assetList.h>

#define WORLD_DIM 1024
#define WORLD_HEIGHT 1024
#define WORLD_WIDTH  1024

#define CELL_DIM 100
#define GRID_DIM 100

#define PIXEL_DIM (CELL_DIM * GRID_DIM)


//----
#define MIN_WIDTH 9
#define GRID_COLOR 0xb0b0b0
#define CALC_STEP_SIZE(zoom) ((short) MIN_WIDTH + (short) zoom);
struct ship_description{
};




struct badgelandia_basic_object_t {
       float loc_x, loc_y, // quantize to fixed point?
             vel_x, vel_y;
};

#define BADGELANDIA_NUM_ITEM_TYPES 6
//#define BADGELANDIA_NUM_ITEM_TYPES 2
enum BADGELANDIA_ITEM {
    UNUSED_ITEM,
    FUEL_UP_ITEM,
    SHIELD_UP_ITEM,
    WEAPON_SPRAYSHOT_ITEM,
    WEAPON_MISSILE_ITEM,

    // Something that a ship can run into
    OBSTACLE_ITEM,

};

struct badgelandia_basic_item_t{
    struct badgelandia_basic_object_t o;
    enum BADGELANDIA_ITEM item_type;
    char modifier;
};

//#define BADGELANDIA_MAX_ITEMS 30
#define BADGELANDIA_MAX_ITEMS 3
struct badgelandia_world_t {
    float view_x, view_y;
    unsigned char zoom;
    struct badgelandia_basic_item_t items[BADGELANDIA_MAX_ITEMS];
};

void ctor_badgelandia_basic_object(struct badgelandia_basic_object_t *o){
    o->loc_x = .0;
    o->loc_y = .0;
    o->vel_x = .0;
    o->vel_y = .0;
}

struct badgelandia_basic_ship_t {
    struct badgelandia_basic_object_t o;

    float orientation_rads;
    unsigned char ship_id;

    unsigned short max_fuel, current_fuel, ticks_per_fuel;
    char thruster_amnt, max_thruster;
    unsigned char max_hp, current_hp;
};

struct badgelandia_basic_inventory_t {
    unsigned int credits;
    unsigned char health_kits, repair_kits;

    unsigned char available_weapons_mask;
    unsigned char available_thruster_mask;
};

struct badgelandia_player_t {

   struct badgelandia_basic_ship_t ship;
   struct badgelandia_basic_inventory_t inventory;

};

struct badgelandia_goon_t {
    struct badgelandia_basic_object_t o;
    unsigned char health;
};


////
#define  MAX_FUEL 8100
#define FUEL_MAX_SHIFT 6 // log2(MAX_FUEL/132)
void badgelandia_init_level(struct badgelandia_player_t* player,
                            struct badgelandia_world_t* world){
    world->view_x = 0;
    world->view_y = 0;
    world->zoom = 100;

    player->ship.max_fuel = MAX_FUEL;
    player->ship.current_fuel = 3000;
    player->ship.thruster_amnt = 0;
    player->ship.orientation_rads = 0.0;
    player->ship.o.vel_x = player->ship.o.vel_y = 0.0;
    player->ship.o.loc_x = player->ship.o.loc_y = 50.0;

}

#define SET_PT_XY(pts, i, x, y) pts[i][0] = x; pts[i][1] = y;
void goon_follow(struct badgelandia_player_t goons,
                 short target_x, short target_y) {

}

void create_player_vector(short pts[][2]){
    //pts[0][0] =
    SET_PT_XY(pts, 0,
              9, 0);
    SET_PT_XY(pts, 1,
              -9, -9);
    SET_PT_XY(pts, 2,
              -3, 0);
    SET_PT_XY(pts, 3,
              -9, 9);

}

void update_player(struct badgelandia_player_t* player){
    float tmp = 0.;


    if(player->ship.current_fuel > 0){
        if((player->ship.current_fuel - player->ship.thruster_amnt) > 0)
            player->ship.current_fuel -= player->ship.thruster_amnt;
        else{
            player->ship.thruster_amnt = player->ship.current_fuel;
            player->ship.current_fuel = 0;
        }
    }
    else{
        player->ship.thruster_amnt = 0;
    }

    //----
    player->ship.o.vel_x /= 1.2;
    player->ship.o.vel_y /= 1.2;

    if(abs(player->ship.o.vel_x) < 0.01)
        player->ship.o.vel_x = 0.0;

    if(abs(player->ship.o.vel_y) < 0.01)
        player->ship.o.vel_y = 0.0;

    if( abs((int)player->ship.o.vel_x) < 6)
        player->ship.o.vel_x += player->ship.thruster_amnt * cos(player->ship.orientation_rads) ;
    if( abs((int)player->ship.o.vel_y) < 6)
        player->ship.o.vel_y += player->ship.thruster_amnt * sin(player->ship.orientation_rads) ;

    tmp = player->ship.o.loc_x + player->ship.o.vel_x;
    if(tmp < 9) {
        player->ship.o.loc_x = 9;
        player->ship.o.vel_x = 0;
    }else if (tmp > PIXEL_DIM - 9 ){
            player->ship.o.loc_x = PIXEL_DIM - 9;
            player->ship.o.vel_x = 0;
    }else
        player->ship.o.loc_x  = tmp;

    tmp = player->ship.o.loc_y + player->ship.o.vel_y;
    if(tmp < 9) {
        player->ship.o.loc_y = 9;
        player->ship.o.vel_y = 0;
    }
    else if (tmp > PIXEL_DIM - 9 ){
        player->ship.o.loc_y = PIXEL_DIM - 9;
        player->ship.o.vel_y = 0;
    }else
        player->ship.o.loc_y  = tmp;


#define HIGH_RESET WORLD_DIM
#define LOW_RESET 1

#ifdef WORLD_WRAP
    // Wrap around
    if(player->ship.o.loc_y  < LOW_RESET)
        player->ship.o.loc_y = HIGH_RESET - 1;
    else if(player->ship.o.loc_y  > HIGH_RESET)
        player->ship.o.loc_y  = LOW_RESET + 1;

    if(player->ship.o.loc_x < LOW_RESET)
        player->ship.o.loc_x=HIGH_RESET - 1;
    else if(player->ship.o.loc_x > HIGH_RESET)
        player->ship.o.loc_x = LOW_RESET + 1;
#endif

}



#define MAX_OF(a, b) (a > b ? a : b)
unsigned char update_world_view(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world) {
    // Repositions the view (x, y) to keep player in focus

    if ((player->ship.o.loc_x - world->view_x) > 90)
        world->view_x = MAX_OF(player->ship.o.loc_x - 90, 0);
    else if ((player->ship.o.loc_x - world->view_x) < 30)
        world->view_x = MAX_OF(player->ship.o.loc_x - 30, 0);
    else if (player->ship.o.loc_x < 30)
        world->view_x = 0;

    if ((player->ship.o.loc_y - world->view_y) > 90)
        world->view_y = MAX_OF(player->ship.o.loc_y - 90, 0);
    else if ((player->ship.o.loc_y - world->view_y) < 30)
        world->view_y = MAX_OF(player->ship.o.loc_y - 30, 0);
    else if (player->ship.o.loc_y < 30)
        world->view_y = 0;
}

unsigned char badgelandia_vector_ship(short shared_vertices[][2],
                                  char draw_id,
                             short loc_x, short loc_y,
                                  float rotation){
    switch (draw_id){
        case 0:
            FbColor(GREEN);
            create_player_vector(shared_vertices);

            //rotate_points_to(points, 3, ship_rotation);
            rotate_points(shared_vertices, 4, rotation);

            FbPolygonFromPoints(shared_vertices, //points,
                                4, loc_x, loc_y);

            break;
        case 1: // Green GOON
            FbColor(GREEN);
            equilateral_polygon_points(shared_vertices,
                                      9.0, 6, 0);
                                       //goon_rotation);
           rotate_points(shared_vertices, 6, rotation);
           FbPolygonFromPoints(shared_vertices,//goon_vertices,
                               6, loc_x, loc_y);
        default:
            break;
    }

}

enum BADGELANDIA_ITEM random_item_type(){
    int r = rand();

    // skip over unused (item 0)
    r = r % (BADGELANDIA_NUM_ITEM_TYPES - 1);
    r++;
    return (enum BADGELANDIA_ITEM ) r;

}

void set_world_items_unused(struct badgelandia_world_t* world){
    unsigned char i = 0;
    for(i=0; i < BADGELANDIA_MAX_ITEMS; i++){
        world->items[i].item_type = UNUSED_ITEM;
    }
}

unsigned char update_world_items(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world ){
#define GET_WORLD_ITEM(i) world->items[i]
#define SHIP_X (unsigned char)(player->ship.o.loc_x - world->view_x)
#define SHIP_Y (unsigned char)(player->ship.o.loc_y - world->view_y)
#define SHIP_HEIGHT 15
#define SHIP_WIDTH 15
    unsigned char i  = 0, tmp = 0;
    for(i=0; i < BADGELANDIA_MAX_ITEMS; i++){
#define ITEM GET_WORLD_ITEM(i)
        switch (world->items[i].item_type){
            case UNUSED_ITEM:
                world->items[i].item_type = random_item_type();

                // INIT ITEMS
                switch(world->items[i].item_type){
                    case UNUSED_ITEM:
                        break;
                    default:
                        world->items[i].o.loc_x = player->ship.o.loc_x;
                        world->items[i].o.loc_x += rand()%300;
                        world->items[i].o.loc_x -= rand()%300;

                        if(world->items[i].o.loc_x < 0)
                            world->items[i].o.loc_x = 5;


                        world->items[i].o.loc_y = player->ship.o.loc_y;
                        world->items[i].o.loc_y += rand()%300;
                        world->items[i].o.loc_y -= rand()%300;

                        if(world->items[i].o.loc_y < 0)
                            world->items[i].o.loc_y = 5;

                        world->items[i].o.vel_x = 0;
                        world->items[i].o.vel_y = 0;

                        world->items[i].modifier = 100;
                        break;
                }
                break;

            case FUEL_UP_ITEM:
                tmp = big_check_box_collision(player->ship.o.loc_x, player->ship.o.loc_y, SHIP_WIDTH, SHIP_HEIGHT,
                                          world->items[i].o.loc_x, world->items[i].o.loc_y,
                                        20, 20);
                if(tmp){
                    if(player->ship.current_fuel < player->ship.max_fuel){
                        if((player->ship.max_fuel - player->ship.current_fuel) < world->items[i].modifier *10){
                            player->ship.current_fuel = player->ship.max_fuel;
                        }else{
                            player->ship.current_fuel += world->items[i].modifier *10;
                        }
                    }

                    world->items[i].item_type = UNUSED_ITEM;
                }


                break;
            default:
                tmp = big_check_box_collision(player->ship.o.loc_x, player->ship.o.loc_y, SHIP_WIDTH, SHIP_HEIGHT,
                                              world->items[i].o.loc_x, world->items[i].o.loc_y,
                                              20, 20);
                if(tmp)
                    world->items[i].item_type = UNUSED_ITEM;
                break;
            }
    }

}

#define BADGELANDIA_WORLD_X_TO_SCREEN_X(x) x - world->view_x
#define BADGELANDIA_WORLD_Y_TO_SCREEN_Y(y) y - world->view_y
void draw_world_items(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world ){
    unsigned char i  = 0, tmp = 0;
    short x, y = 0;
    for(i=0; i < BADGELANDIA_MAX_ITEMS; i++) {
        x = BADGELANDIA_WORLD_X_TO_SCREEN_X(world->items[i].o.loc_x);
        y = BADGELANDIA_WORLD_Y_TO_SCREEN_Y(world->items[i].o.loc_y);

        if ((x < 0) || (y < 0) || (x > 132) || (y > 132))
            continue;

        switch (world->items[i].item_type) {
            case FUEL_UP_ITEM:
                FbMove(x, y);
                FbColor(WHITE);
                FbFilledRectangle(10, 10);
                break;
            case SHIELD_UP_ITEM:
                FbMove(x, y);
                FbColor(CYAN);
                FbFilledRectangle(10, 10);
                break;
            case WEAPON_SPRAYSHOT_ITEM:
                FbMove(x, y);
                FbColor(YELLOW);
                FbFilledRectangle(10, 10);
                break;
            case WEAPON_MISSILE_ITEM:
                FbMove(x, y);
                FbColor(RED);
                FbFilledRectangle(10, 10);
                break;
            case OBSTACLE_ITEM:
                FbMove(x, y);
                FbTransparentIndex(3);
                FbImage(BADGEY_BIRD, 0);
                break;
            default:
                break;
        }
    }
}

#define SECTOR_DIM 32
#define MAX_WIDTH 100

#define SIMPLE_GRID
void badgelandia_draw_grid(struct badgelandia_world_t *world){
    FbColor(GRID_COLOR);

#ifdef SIMPLE_GRID
    unsigned short x, y;
    for(x=world->view_x, y=world->view_y;
                (x < (132 + world->view_x ) &&
                (y < (132 + world->view_y)));
                    x++, y++){
        if(x % (MIN_WIDTH + world->zoom) == 0){
            FbVerticalLine(x - (short)world->view_x, 0,
                           x - (short)world->view_x, 132);
        }

        if(y % (MIN_WIDTH + world->zoom) == 0) {
            FbHorizontalLine(0, y - (short) world->view_y,
                             132, y - (short) world->view_y);
        }
    }
#else
    // These values are the real location at the pixel level
    // - these coordinates + zoom level define the view completely
    //short step_size = (short) MIN_WIDTH + world->zoom;
    short step_size = CALC_STEP_SIZE(world->zoom);
    short x = (short) world->view_x + (short)132;
    short y = (short) world->view_y + (short)132;

    // Add the remainder back in
    x -= ((short) world->view_x) % step_size;
    y -= ((short) world->view_y) % step_size;
    short tmp = 0;

    while(
            ((x - (short)world->view_x) > 0) &&
            ((y - (short)world->view_y) > 0)

    ){
        tmp = x - (short)world->view_x;
        FbVerticalLine(tmp, 0,
                       tmp, 132);


        tmp = y - (short)world->view_y;
        FbHorizontalLine(0, tmp,
                         132, tmp);

        x -= step_size;
        y -= step_size;
    }

    // As zoom level adjusts
    //  - the location of the view must continue to keep the ship centered
    //  - x values de-aggregate/de-bin

#endif
}

//#define ZOOM_X(player, world) ((player.ship.o.loc_x - world.view_x)/world.zoom)
//#define ZOOM_Y(player, world) ((player.ship.o.loc_y - world.view_y)/world.zoom)

unsigned char badgelandia_user_io(struct badgelandia_player_t* player,
                                  struct badgelandia_world_t* world){
    unsigned char redraw = 0;
    if(UP_BTN_HOLD(3)){
        if(player->ship.thruster_amnt < 10)
            player->ship.thruster_amnt++;
        redraw = 1;
    }
    if(DOWN_BTN_HOLD(3)){
        if(player->ship.thruster_amnt > 0)
            player->ship.thruster_amnt--;
        redraw = 1;
    }
    if(LEFT_BTN_HOLD(3)){
        player->ship.orientation_rads -= ((float)G_left_button_cnt)/150.0;
        if(player->ship.orientation_rads < 0.0)
            player->ship.orientation_rads += 6.282;
        redraw = 1;
    }
    if(RIGHT_BTN_HOLD(3)) {
        player->ship.orientation_rads += ((float)G_right_button_cnt)/150.0;
        if(player->ship.orientation_rads > 6.282)
           player->ship.orientation_rads -= 6.282;
        redraw = 1;
    }
    return redraw;
}

#define DEBOUNCE_CNT 3
void badgelandia_task(void* p_arg){
    const TickType_t tick_rate = 10 / portTICK_PERIOD_MS;
    unsigned char i = 0, redraw=1;
    unsigned char spkr_factor = 10;
    struct badgelandia_world_t world;
    struct badgelandia_player_t player;

    unsigned char thrust_str[5];

    badgelandia_init_level(&player, &world);
    set_world_items_unused(&world);

#define N_GOONS 5
#define GOON_ROTATION_DELTA .01
    struct badgelandia_goon_t goons[N_GOONS];

    short shared_vertices[8][2] = {0};

    FbBackgroundColor(GREY2);
    FbClear();
    redraw = 1;

#ifdef SDL_BADGE
    while(G_Fb.status)
#else
    for(;;)
#endif
    {
#ifndef SDL_BADGE
        if(BUTTON_PRESSED_AND_CONSUME)
            returnToMenus();
#endif

        redraw |= badgelandia_user_io(&player, &world);
        update_player(&player);

        update_world_view(&player, &world);

        update_world_items(&player, &world);

        if(redraw || (G_touch_pct > 0)
            || (player.ship.o.vel_x != 0.0)
                || (player.ship.o.vel_y != 0.0)){

#define SHOW_SHIP_COORDS
#ifdef SHOW_SHIP_COORDS
            //----
            FbColor(YELLOW);
            badge_itoa((int)(player.ship.o.loc_x), thrust_str, 6);
            FbMove(0, 115);
            FbWriteLine(thrust_str);

            badge_itoa((int)(player.ship.o.loc_y), thrust_str, 6);
            FbMove(80, 115);
            FbWriteLine(thrust_str);
#endif
            ///-----
            FbColor(WHITE);
            //badge_itoa((int)(G_touch_pct), thrust_str, 6);
            badge_itoa((int)(player.ship.thruster_amnt), thrust_str, 6);
            FbMove(80, 10);
            FbWriteLine(thrust_str);
            ///-----



            badgelandia_draw_grid(&world);

            draw_world_items(&player, &world);

            //TODO: Consider zoom level in how ships/ are drawn
            // -
#ifdef USE_ZOOM
            if(world.zoom < 5){
                FbColor(GREEN);
                FbMove(
                        //(unsigned char)(player.ship.o.loc_x - world.view_x),
                        //(unsigned char)(player.ship.o.loc_y - world.view_y)
                        (short)((player.ship.o.loc_x - world.view_x)/world.zoom) ,
                        (short)((player.ship.o.loc_y - world.view_y)/world.zoom)
                        //ZOOM_X(player, world),
                        //ZOOM_Y(player, world),
                );
                FbFilledRectangle(MIN_WIDTH, MIN_WIDTH);
            } else{
                badgelandia_vector_ship(shared_vertices, 0,
                                        (short)((player.ship.o.loc_x - world.view_x)/world.zoom) ,
                                        (short)((player.ship.o.loc_y - world.view_y)/world.zoom),
                                        //ZOOM_X(player, world),
                                        //ZOOM_Y(player, world)
                                        //(short)(player.ship.o.loc_x - world.view_x),
                                        //(short)(player.ship.o.loc_y - world.view_y),
                                        player.ship.orientation_rads);
            }
#endif
           badgelandia_vector_ship(shared_vertices, 0,
                        (short)((player.ship.o.loc_x - world.view_x)) ,
                        (short)((player.ship.o.loc_y - world.view_y)),
                        //ZOOM_X(player, world),
                        //ZOOM_Y(player, world)
                        //(short)(player.ship.o.loc_x - world.view_x),
                        //(short)(player.ship.o.loc_y - world.view_y),
                        player.ship.orientation_rads);
            // -----
            //player.ship.current_fuel
            FbColor(WHITE);
            FbMove(3, 124);
            FbRectangle(player.ship.max_fuel >> FUEL_MAX_SHIFT, 5);

            if(player.ship.current_fuel < 500)
                FbColor(RED);
            else if (player.ship.current_fuel < 1000)
                FbColor(YELLOW);
            else if (player.ship.current_fuel < 5000)
                FbColor(GREEN);
            FbMove(4, 125);
            FbFilledRectangle(player.ship.current_fuel >> FUEL_MAX_SHIFT, 3);
            FbSwapBuffers();
            redraw = 0;
        }
        vTaskDelay(tick_rate);
    }
}

