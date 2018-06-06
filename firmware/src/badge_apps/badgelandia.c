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
#include "badge_menu.h"

#define WORLD_DIM 1024

#define CELL_DIM 100
#define GRID_DIM 100

#define PIXEL_DIM (CELL_DIM * GRID_DIM)


//----
#define MIN_WIDTH 9
#define GRID_COLOR 0xb0b0b0
#define MAX_FUEL 8100
#define MAX_HEALTH 100

enum BADGELANDIA_STATE {BADGELANDIA_INSTRUCT, BADGELANDIA_INIT, BADGELANDIA_RUN,
                        BADGELANDIA_FAILURE, BADGELANDIA_WIN,
                        BADGELANDIA_MENU, BADGELANDIA_EXIT};
enum BADGELANDIA_STATE badgelandia_state = BADGELANDIA_INSTRUCT;

void set_run_mode(){
    badgelandia_state = BADGELANDIA_RUN;
}

void exit_badgelandia(){
    badgelandia_state = BADGELANDIA_EXIT;
}

struct menu_t badgelandia_menu[] = {
        {"return", VERT_ITEM|DEFAULT_ITEM, FUNCTION, {(struct menu_t *)set_run_mode}},
        {"exit", VERT_ITEM|LAST_ITEM, FUNCTION, {(struct menu_t *)exit_badgelandia}},
};

struct badgelandia_basic_location_t {
       short loc_x, loc_y;
};

struct badgelandia_basic_object_t {
       float loc_x, loc_y, // quantize to fixed point?
             vel_x, vel_y;
};

#define BADGELANDIA_NUM_ITEM_TYPES 4
//#define BADGELANDIA_NUM_ITEM_TYPES 2
enum BADGELANDIA_ITEM {
    UNUSED_ITEM,
    FUEL_UP_ITEM,
    SHIELD_UP_ITEM,
    HEALTH_UP_ITEM,

    GOLD_ASTEROID,
    //WEAPON_SPRAYSHOT_ITEM,
    //WEAPON_MISSILE_ITEM,

    // Something that a ship can run into
    //OBSTACLE_ITEM,

};

struct badgelandia_basic_item_t{
    struct badgelandia_basic_object_t o;
    enum BADGELANDIA_ITEM item_type;
    char modifier, modifier2, modifier3;
};


struct badgelandia_basic_ship_t {
    struct badgelandia_basic_object_t o;

    float orientation_rads;
    unsigned char ship_id;

    unsigned short max_fuel, current_fuel, ticks_per_fuel;
    char thruster_amnt;
    unsigned char max_hp, current_hp;
};

#define MAX_SHIELD 1000
struct badgelandia_basic_inventory_t {
    unsigned int credits;
    short shield_amnt;

    unsigned char available_weapons_mask;
    unsigned char available_thruster_mask;
};

enum PROJECTILE_TYPE{UNUSED_PROJECTILE, RIFLE_PROJECTILE};
struct badgelandia_weapon_projectile_t{
    struct badgelandia_basic_object_t o;
    enum PROJECTILE_TYPE type;
    unsigned char n_steps;

};

#define MAX_PLAYER_PROJECTILES 7
struct badgelandia_player_t {
    struct badgelandia_basic_ship_t ship;
    struct badgelandia_basic_inventory_t inventory;
    struct badgelandia_weapon_projectile_t projectiles[MAX_PLAYER_PROJECTILES];
    short projectile_cooldown;
    unsigned short kill_points;
};

#define BADGELANDIA_NUM_GOON_TYPES 3
enum BADGELANDIA_GOON{
    UNUSED_GOON,
    DOT_GOON,
    SMALL_GOON
};

#define BADGELANDIA_MAX_GOONS 20
struct badgelandia_goon_t {
    //struct badgelandia_basic_object_t o;
    struct badgelandia_basic_location_t o;
    enum BADGELANDIA_GOON goon_type;
    unsigned char modified;
};

//#define BADGELANDIA_MAX_ITEMS 30
#define BADGELANDIA_MAX_ITEMS 10
struct badgelandia_world_t {
    float view_x, view_y;
    unsigned char zoom;
    struct badgelandia_basic_item_t items[BADGELANDIA_MAX_ITEMS];
    struct badgelandia_goon_t goons[BADGELANDIA_MAX_GOONS];
};


#define SET_PT_XY(pts, i, x, y) pts[i][0] = x; pts[i][1] = y;
void create_player_vector(short pts[][2]){
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
    float tmp = 0;


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

    unsigned char i = 0;
    for(i = 0; i < MAX_PLAYER_PROJECTILES; i++) {
        if (player->projectiles[i].type == UNUSED_PROJECTILE)
            continue;

        player->projectiles[i].o.loc_x += player->projectiles[i].o.vel_x;
        player->projectiles[i].o.loc_y += player->projectiles[i].o.vel_y;
        if(player->projectiles[i].n_steps < 50)
            player->projectiles[i].n_steps++;
        else {
            player->projectiles[i].n_steps = 0;
            player->projectiles[i].type = UNUSED_PROJECTILE;
        }
    }
}

unsigned char damage_player(struct badgelandia_player_t* player, short damage_amnt) {
    if (damage_amnt >= player->inventory.shield_amnt) {
        damage_amnt -= player->inventory.shield_amnt;
        player->inventory.shield_amnt = 0;
    } else {
        player->inventory.shield_amnt -= damage_amnt;
        damage_amnt = 0;
    }

    if(damage_amnt >= player->ship.current_hp) {
        player->ship.current_hp = 0;
    }else {
        player->ship.current_hp -= damage_amnt;
    }

    return (unsigned char)(player->ship.current_hp == 0);
}

void draw_player(struct badgelandia_player_t* player,
                 struct badgelandia_world_t* world){
    static float rot = 0.0;
    short shared_vertices[8][2] = {0};
    unsigned char x = (unsigned char)(player->ship.o.loc_x - world->view_x);
    unsigned char y = (unsigned char)(player->ship.o.loc_y - world->view_y);

    FbColor(GREEN);
    create_player_vector(shared_vertices);

    //rotate_points_to(points, 3, ship_rotation);
    rotate_points(shared_vertices, 4, player->ship.orientation_rads);

    FbPolygonFromPoints(shared_vertices, //points,
                        4, x, y);

    //if(player->inventory.shield_amnt== 0)
    //    return;

    FbColor(CYAN);
    if(player->inventory.shield_amnt > 200){
        equilateral_polygon_points(shared_vertices,
                                   17.0, 6, rot);
        FbPolygonFromPoints(shared_vertices,//goon_vertices,
                            6, x, y);
    }
    if(player->inventory.shield_amnt > 500){
        equilateral_polygon_points(shared_vertices,
                                   20.0, 6, rot*.5);
        FbPolygonFromPoints(shared_vertices,//goon_vertices,
                            6, x, y);
    }
    if(player->inventory.shield_amnt > 700){
        equilateral_polygon_points(shared_vertices,
                                   23.0, 6, rot*.25);
        FbPolygonFromPoints(shared_vertices,//goon_vertices,
                            6, x, y);
    }
    rot += 0.05;

    unsigned char i = 0;
    for(i = 0; i < MAX_PLAYER_PROJECTILES; i++) {
        if (player->projectiles[i].type == UNUSED_PROJECTILE)
            continue;
        if(big_check_box_collision(world->view_x, world->view_y,
                                    132, 132,
                                    player->projectiles[i].o.loc_x, player->projectiles[i].o.loc_y,
                                    20, 20)){
            x = player->projectiles[i].o.loc_x - world->view_x;
            y = player->projectiles[i].o.loc_y - world->view_y;
            FbMove(x, y);
            FbColor(WHITE);
            FbFilledRectangle(4, 4);
        }
    }
}

// -- Goons --
enum BADGELANDIA_GOON random_goon_type(){
    int r = rand();

    // skip over unused (item 0)
    r = r % (BADGELANDIA_NUM_GOON_TYPES - 1);
    r++;
    return (enum BADGELANDIA_GOON) r;
}

void set_world_goons_unused(struct badgelandia_world_t* world){
    unsigned char i = 0;
    for(i=0; i < BADGELANDIA_MAX_GOONS; i++){
        world->goons[i].goon_type = UNUSED_GOON;
    }
}

// returns whether the new init is colliding with something existing
unsigned char random_init_object(//struct badgelandia_basic_object_t *o,
                        short *loc_x, short *loc_y,
                        struct badgelandia_world_t *world,
                        short init_x, short init_y){ // init coords are usually player's ship
    unsigned char is_colliding = 0;

    *loc_x = init_x;
    *loc_x += rand() % 1000;
    *loc_x -= rand() % 1000;

    if (*loc_x < 0)
        *loc_x = 5;
    else if(*loc_x > (PIXEL_DIM - 10))
        *loc_x = PIXEL_DIM - 10;

    // ---- Y
    *loc_y = init_y;
    *loc_y += rand() % 1000;
    *loc_y -= rand() % 1000;

    if(*loc_y < 0)
        *loc_y = 5;
    else if(*loc_y > (PIXEL_DIM - 10))
        *loc_y = PIXEL_DIM - 10;

    ///-----
    if (
            big_check_box_collision(world->view_x, world->view_y,
                                    132, 132,
                                    *loc_x, *loc_y,
                                    20, 20)
            ) {
        *loc_x += 132;
        *loc_y += 132;
    }

    // Check against items
    short _i;
    for (_i = 0; _i < BADGELANDIA_MAX_ITEMS; _i++) {
        if (big_check_box_collision(world->items[_i].o.loc_x, world->items[_i].o.loc_y,
                                    20, 20,
                                    *loc_x, *loc_y,
                                    20, 20)) {
            is_colliding |= 1;
        }
    }

    // check agains goons
    for (_i = 0; _i < BADGELANDIA_MAX_GOONS; _i++) {
        if (big_check_box_collision(world->goons[_i].o.loc_x, world->goons[_i].o.loc_y,
                                    20, 20,
                                    *loc_x, *loc_y,
                                    20, 20)) {
            is_colliding |= 1;
        }
    }
    return is_colliding;
}

unsigned char update_world_goons(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world){
    unsigned char redraw = 0;
    unsigned char i  = 0, tmp = 0;
    unsigned char goon_dim = 5;
    unsigned char goon_points = 0;
    short distance = 0, min_sniff_distance = 50;
    for(i=0; i < BADGELANDIA_MAX_GOONS; i++) {
        switch (world->goons[i].goon_type) {
            case UNUSED_GOON:
                world->goons[i].goon_type = random_goon_type();
                random_init_object(&world->goons[i].o.loc_x, &world->goons[i].o.loc_y,
                                   world, player->ship.o.loc_x, player->ship.o.loc_y);

                // INIT goons
                switch (world->goons[i].goon_type) {
                    case UNUSED_GOON:
                        break;
                    case DOT_GOON:
                        //world->goons[i].modifier = 100;
                        break;
                    case SMALL_GOON:
                        //world->goons[i].modifier = 50;
                        break;
                    default:
                        break;
                }
                break;
#define DOT_GOON_DAMAGE 10
            case DOT_GOON:
                goon_points = goon_dim = 5;
                distance = big_distance_between_coords(world->goons[i].o.loc_x, world->goons[i].o.loc_y,
                                                       player->ship.o.loc_x, player->ship.o.loc_y);
                if(distance < 10){
                    damage_player(player, DOT_GOON_DAMAGE);
                    world->goons[i].goon_type = UNUSED_GOON;
                }
                else if(distance < 250){
                    big_path_between_points(&world->goons[i].o.loc_x,
                                            &world->goons[i].o.loc_y,
                                            player->ship.o.loc_x, player->ship.o.loc_y);

                    big_path_between_points(&world->goons[i].o.loc_x,
                                            &world->goons[i].o.loc_y,
                                            player->ship.o.loc_x, player->ship.o.loc_y);
                }
                break;

#define SMALL_GOON_DAMAGE 100
            case SMALL_GOON:
                goon_points = goon_dim = 10;
                distance = big_distance_between_coords(world->goons[i].o.loc_x, world->goons[i].o.loc_y,
                                                       player->ship.o.loc_x, player->ship.o.loc_y);
                if(distance < 15){
                    damage_player(player, SMALL_GOON_DAMAGE);
                    world->goons[i].goon_type = UNUSED_GOON;
                }
                else if(distance < 700){
                    big_path_between_points(&world->goons[i].o.loc_x,
                                            &world->goons[i].o.loc_y,
                                            player->ship.o.loc_x, player->ship.o.loc_y);
                }
                break;
            default:
                break;
        }

        // If very Far away - re create
        if (distance > 1000){
            world->goons[i].goon_type = UNUSED_GOON;
        }

        if(big_check_box_collision(world->view_x, world->view_y,
                                    132, 132,
                                    world->goons[i].o.loc_x, world->goons[i].o.loc_y,
                                    goon_dim, goon_dim)){
            redraw |= 1;
        }

        unsigned char p = 0;
        for(p = 0; p < MAX_PLAYER_PROJECTILES; p++) {
            if (player->projectiles[p].type == UNUSED_PROJECTILE)
                continue;
            if(big_check_box_collision(world->goons[i].o.loc_x, world->goons[i].o.loc_y,
                                        goon_dim, goon_dim,
                                        player->projectiles[p].o.loc_x, player->projectiles[p].o.loc_y,
                                        5, 5)){
                player->projectiles[p].type = UNUSED_PROJECTILE;
                world->goons[i].goon_type = UNUSED_GOON;
                player->kill_points += goon_points;
            }
        }
    }
    return redraw;
}

#define BADGELANDIA_WORLD_X_TO_SCREEN_X(x) x - world->view_x
#define BADGELANDIA_WORLD_Y_TO_SCREEN_Y(y) y - world->view_y
void draw_world_goons(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world ){
    unsigned char i  = 0, tmp = 0;
    short shared_vertices[8][2] = {0};
    float tmp_float = 0.0;
    short x, y = 0;
    for(i=0; i < BADGELANDIA_MAX_GOONS; i++) {
        x = BADGELANDIA_WORLD_X_TO_SCREEN_X(world->goons[i].o.loc_x);
        y = BADGELANDIA_WORLD_Y_TO_SCREEN_Y(world->goons[i].o.loc_y);

        if ((x < 0) || (y < 0) || (x > 132) || (y > 132))
            continue;

        switch (world->goons[i].goon_type) {
            case DOT_GOON:
                FbMove(x, y);
                FbColor(RED);
                FbFilledRectangle(3, 3);
                //FbMove(x+1, y+1);
                FbColor(YELLOW);
                //FbFilledRectangle(1, 1);
                FbPoint(x+1, y+1);
                break;
            case SMALL_GOON:
                FbColor(RED);
                equilateral_polygon_points(shared_vertices,
                                           9.0, 6, 0.);
                FbPolygonFromPoints(shared_vertices,
                                    6, x, y);
                FbColor(YELLOW);
                equilateral_polygon_points(shared_vertices,
                                           5.0, 6, 0.);
                FbPolygonFromPoints(shared_vertices,
                                    6, x, y);
                break;
            default:
                break;
        }
    }
}

//-- Items --
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
#define SHIP_HEIGHT 15
#define SHIP_WIDTH 15
    unsigned char redraw = 0;
    unsigned char i  = 0, tmp = 0;
    short tmp_x, tmp_y;
    for(i=0; i < BADGELANDIA_MAX_ITEMS; i++){
        if(world->items[i].item_type == UNUSED_ITEM){
            world->items[i].item_type = random_item_type();

            tmp_x = (short)world->items[i].o.loc_x;
            tmp_y = (short)world->items[i].o.loc_y;
            random_init_object(&tmp_y, &tmp_x,
                               world, player->ship.o.loc_x, player->ship.o.loc_y);

            world->items[i].o.loc_x = tmp_x;
            world->items[i].o.loc_y = tmp_y;

            //----
            world->items[i].o.vel_x = 0;
            world->items[i].o.vel_y = 0;

            // INIT ITEMS
            switch(world->items[i].item_type){
                case UNUSED_ITEM:
                    break;
                case FUEL_UP_ITEM:
                    world->items[i].modifier = 100;
                    break;
                case SHIELD_UP_ITEM:
                    world->items[i].modifier = 50;
                    break;
                case HEALTH_UP_ITEM:
                    world->items[i].modifier = 25;
                    break;
                case GOLD_ASTEROID:
                    world->items[i].o.vel_x = (float)0.01 * (rand()%100);
                    world->items[i].o.vel_y = (float)0.01* (rand()%100);
                    world->items[i].modifier = 5;
                    break;
                default:
                    break;
            }
        }

        switch (world->items[i].item_type){
            case UNUSED_ITEM:
                break;

            case FUEL_UP_ITEM:
                tmp = big_check_box_collision(player->ship.o.loc_x, player->ship.o.loc_y, SHIP_WIDTH, SHIP_HEIGHT,
                                          world->items[i].o.loc_x, world->items[i].o.loc_y,
                                        20, 20);
                if(tmp){
                    if(player->ship.current_fuel < player->ship.max_fuel){
                        if((player->ship.max_fuel - player->ship.current_fuel) < world->items[i].modifier *15){
                            player->ship.current_fuel = player->ship.max_fuel;
                        }else{
                            player->ship.current_fuel += world->items[i].modifier *15;
                        }
                    }

                    world->items[i].item_type = UNUSED_ITEM;
                }


                break;
            case SHIELD_UP_ITEM:
                tmp = big_check_box_collision(player->ship.o.loc_x, player->ship.o.loc_y, SHIP_WIDTH, SHIP_HEIGHT,
                                              world->items[i].o.loc_x, world->items[i].o.loc_y,
                                              20, 20);
                if(tmp){
                    if(player->ship.current_fuel < player->ship.max_fuel){
                        if((MAX_SHIELD - player->inventory.shield_amnt) < world->items[i].modifier * 10){
                            player->inventory.shield_amnt = MAX_SHIELD;
                        }else{
                            player->inventory.shield_amnt += world->items[i].modifier * 10;
                        }
                    }
                    world->items[i].item_type = UNUSED_ITEM;
                }
                break;
            case HEALTH_UP_ITEM:
               tmp = big_check_box_collision(player->ship.o.loc_x, player->ship.o.loc_y, SHIP_WIDTH, SHIP_HEIGHT,
                                              world->items[i].o.loc_x, world->items[i].o.loc_y,
                                              20, 20);
                if(tmp){
                    if(player->ship.current_hp < MAX_HEALTH){
                        if((MAX_HEALTH - player->ship.current_hp) < world->items[i].modifier){
                            player->ship.current_hp = MAX_HEALTH;
                        }else{
                            player->ship.current_hp += world->items[i].modifier;
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

        short distance = big_distance_between_coords(world->items[i].o.loc_x, world->items[i].o.loc_y,
                                               player->ship.o.loc_x, player->ship.o.loc_y);
        if (distance > 1000){
            world->items[i].item_type = UNUSED_ITEM;
        }

        world->items[i].o.loc_x += world->items[i].o.vel_x;
        if (world->items[i].o.loc_x < 5){
            if(world->items[i].o.vel_x < 0)
                world->items[i].o.vel_x *= -1;
        }
        if (world->items[i].o.loc_x > PIXEL_DIM - 9){
            if(world->items[i].o.vel_x > 0)
                world->items[i].o.vel_x *= -1;
        }

        world->items[i].o.loc_y += world->items[i].o.vel_y;
        if (world->items[i].o.loc_y < 5){
            if(world->items[i].o.vel_y < 0)
                world->items[i].o.vel_y *= -1;
        }
        if (world->items[i].o.loc_y > PIXEL_DIM - 9){
            if(world->items[i].o.vel_y > 0)
                world->items[i].o.vel_y *= -1;
        }

        if(big_check_box_collision(world->view_x, world->view_y,
                                    132, 132,
                                    world->items[i].o.loc_x, world->items[i].o.loc_y,
                                    20, 20)){
            redraw |= 1;
        }
    }
    return redraw;
}

void draw_world_items(struct badgelandia_player_t* player,
                        struct badgelandia_world_t* world ){
    unsigned char i  = 0, tmp = 0;
    short shared_vertices[8][2] = {0};
    float tmp_float = 0.0;
    short x, y = 0;
    for(i=0; i < BADGELANDIA_MAX_ITEMS; i++) {
        x = BADGELANDIA_WORLD_X_TO_SCREEN_X(world->items[i].o.loc_x);
        y = BADGELANDIA_WORLD_Y_TO_SCREEN_Y(world->items[i].o.loc_y);

        if ((x < 0) || (y < 0) || (x > 132) || (y > 132))
            continue;

        switch (world->items[i].item_type) {
            case FUEL_UP_ITEM:
                FbColor(WHITE);
                tmp_float = (float)world->items[i].modifier2 * 0.1;
                world->items[i].modifier2++;
                equilateral_polygon_points(shared_vertices,
                                           9.0, 6, tmp_float);
                FbPolygonFromPoints(shared_vertices,//goon_vertices,
                                    6, x, y);
                break;
            case SHIELD_UP_ITEM:
                FbMove(x, y);
                FbColor(CYAN);
                FbFilledRectangle(10, 10);
                break;
//            case WEAPON_SPRAYSHOT_ITEM:
//                FbMove(x, y);
//                FbColor(YELLOW);
//                FbFilledRectangle(10, 10);
//                break;
            case HEALTH_UP_ITEM:
                FbColor(WHITE);
                FbMove(x-5, y - 5);
                FbFilledRectangle(10, 10);

                FbColor(RED);
                FbMove(x-2, y - 5);
                FbFilledRectangle(4, 10);
                FbMove(x-5, y - 2);
                FbFilledRectangle(10, 4);
                break;

            case GOLD_ASTEROID:
                FbColor(YELLOW);
                equilateral_polygon_points(shared_vertices,
                           9.0, 6, tmp_float);
                FbPolygonFromPoints(shared_vertices,//goon_vertices,
                                    6, x, y);
                break;
//            case WEAPON_MISSILE_ITEM:
//                FbMove(x, y);
//                FbColor(RED);
//                FbFilledRectangle(10, 10);
//                break;
//            case OBSTACLE_ITEM:
//                FbMove(x, y);
//                FbTransparentIndex(3);
//                FbImage(BADGEY_BIRD, 0);
//                break;
            default:
                break;
        }
    }
}

// -- end items --


// -- Level stuff --
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
    if(DOWN_TOUCH_AND_CONSUME){

        if(player->projectile_cooldown == 0){
            unsigned char i = 0;
            for(i = 0; i < MAX_PLAYER_PROJECTILES; i++) {
                if (player->projectiles[i].type != UNUSED_PROJECTILE)
                    continue;

                player->projectiles[i].type = RIFLE_PROJECTILE;
                player->projectiles[i].o.vel_y = 10 * sin(player->ship.orientation_rads);
                player->projectiles[i].o.vel_x = 10 * cos(player->ship.orientation_rads);
                player->projectiles[i].o.vel_y += player->ship.o.vel_y;
                player->projectiles[i].o.vel_x += player->ship.o.vel_x;

                player->projectiles[i].o.loc_x = player->ship.o.loc_x;
                player->projectiles[i].o.loc_y = player->ship.o.loc_y;

                player->projectiles[i].n_steps = 0;
                player->projectile_cooldown = 5;
                break;
            }
        }
    }

    if(player->projectile_cooldown > 0)
        player->projectile_cooldown--;

    return redraw;
}

void badgelandia_draw_grid(struct badgelandia_world_t *world){
    FbColor(GRID_COLOR);

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
}


#define MAX_OF(a, b) (a > b ? a : b)
void update_world_view(struct badgelandia_player_t* player,
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


////
#define FUEL_MAX_SHIFT 6 // log2(MAX_FUEL/132)
void badgelandia_init_level(struct badgelandia_player_t* player,
                            struct badgelandia_world_t* world){
    world->view_x = (PIXEL_DIM/2) - 66;
    world->view_y = (PIXEL_DIM/2) - 66;
    world->zoom = 100;

    player->ship.max_fuel = MAX_FUEL;
    player->ship.current_fuel = 3000;
    player->ship.thruster_amnt = 0;
    player->ship.orientation_rads = 0.0;
    player->ship.o.vel_x = player->ship.o.vel_y = 0.0;
    player->ship.o.loc_x = player->ship.o.loc_y = (float)PIXEL_DIM/2;

    //player->inventory.shield_amnt = MAX_SHIELD;
    player->inventory.shield_amnt = 250;
    player->ship.current_hp = MAX_HEALTH - 40;
    player->kill_points = 0;
    player->projectile_cooldown = 0;

    unsigned char i = 0;
    for(i = 0; i < MAX_PLAYER_PROJECTILES; i++){
        player->projectiles[i].type = UNUSED_PROJECTILE;
        player->projectiles[i].o.loc_x = 0;
        player->projectiles[i].o.loc_y = 0;
        player->projectiles[i].o.vel_x = 0;
        player->projectiles[i].o.vel_y = 0;
    }
    /*
    player->projectiles[0].type = RIFLE_PROJECTILE;
    player->projectiles[0].o.loc_x = 10;
    player->projectiles[0].o.loc_y = 10;
    player->projectiles[0].o.vel_x = 3;
    player->projectiles[0].o.vel_y = 3;
     */

    // I T E M S
    set_world_items_unused(world);
    world->items[0].item_type = FUEL_UP_ITEM;
    world->items[0].o.loc_x = 20;
    world->items[0].o.loc_y = 100;
    world->items[0].o.vel_x = -.8;
    world->items[0].o.vel_y = -.8;
    world->items[0].modifier = 100;

    world->items[1].item_type = HEALTH_UP_ITEM;
    world->items[1].o.loc_x = 20;
    world->items[1].o.loc_y = 20;
    world->items[1].o.vel_x = .0;
    world->items[1].o.vel_y = .0;
    world->items[1].modifier = 25;

    // G O O N S
    set_world_goons_unused(world);
    world->goons[0].goon_type = DOT_GOON;
    world->goons[0].o.loc_x = 100;
    world->goons[0].o.loc_y = 10;

}
// -- end level stuff --

// -- MAIN

void badgelandia_task(void* p_arg){
    const TickType_t tick_rate = 10 / portTICK_PERIOD_MS;
    unsigned char redraw=1;
    struct badgelandia_world_t world;
    struct badgelandia_player_t player;

    unsigned char thrust_str[5];

    FbBackgroundColor(GREY2);
    FbClear();
    redraw = 1;

#ifdef SDL_BADGE
    while(G_Fb.status)
#else
    for(;;)
#endif
    {
        switch (badgelandia_state){
            case BADGELANDIA_INSTRUCT:
                if(BUTTON_PRESSED_AND_CONSUME)
                    badgelandia_state = BADGELANDIA_INIT;
                else
                    vTaskDelay(tick_rate);

                FbColor(GREEN);
                FbMove(1, 3);
                FbWriteLine("D-Pad controls");
                FbMove(20, 15);
                FbWriteLine("ship");

                FbMove(1, 30);
                FbWriteLine("Down on slider");
                FbMove(20, 40);
                FbWriteLine("for Weapon");

                FbColor(CYAN);
                FbMove(1, 65);
                FbWriteLine("Blue Button");
                FbMove(20, 75);
                FbWriteLine("for menu");

                FbMove(1, 105);
                FbWriteLine("Blue Button");
                FbMove(20, 115);
                FbWriteLine("to start!");


                FbSwapBuffers();

                break;
            case BADGELANDIA_INIT:
                badgelandia_init_level(&player, &world);
                badgelandia_state = BADGELANDIA_RUN;
                break;
            case BADGELANDIA_RUN:
                if(BUTTON_PRESSED_AND_CONSUME)
                    badgelandia_state = BADGELANDIA_MENU;

                if(player.ship.current_hp == 0){
                    badgelandia_state = BADGELANDIA_FAILURE;

                } else{
                    redraw |= badgelandia_user_io(&player, &world);

                    update_player(&player);
                    update_world_view(&player, &world);

                    redraw |= update_world_items(&player, &world);
                    redraw |= update_world_goons(&player, &world);
                }

                // -_-
                if(player.inventory.shield_amnt > 0)
                    redraw |= 1;

                if(redraw || (G_touch_pct > 0)
                    || (player.ship.o.vel_x != 0.0)
                        || (player.ship.o.vel_y != 0.0)){

                    //----
                    FbColor(YELLOW);
                    badge_itoa((int)(player.ship.o.loc_x), thrust_str, 6);
                    FbMove(0, 115);
                    FbWriteLine(thrust_str);

                    badge_itoa((int)(player.ship.o.loc_y), thrust_str, 6);
                    FbMove(80, 115);
                    FbWriteLine(thrust_str);
                    ///-----
                    FbColor(WHITE);
                    //badge_itoa((int)(G_touch_pct), thrust_str, 6);
                    badge_itoa((int)(player.ship.thruster_amnt), thrust_str, 6);
                    FbMove(80, 3);
                    FbWriteLine(thrust_str);
                    ///-----

                    badgelandia_draw_grid(&world);

                    draw_world_items(&player, &world);
                    draw_world_goons(&player, &world);

                    draw_player(&player, &world);

                    // -----
                    //player.ship.current_fuel
                    FbColor(WHITE);
                    FbMove(3, 124);
                    FbRectangle((unsigned char) (player.ship.max_fuel >> FUEL_MAX_SHIFT), 5);

                    if(player.ship.current_fuel < 500) {
                        FbColor(RED);
                        FbMove(43, 90);
                        if(player.ship.current_fuel > 0)
                            FbWriteLine("LOW FUEL");
                        else
                            FbWriteLine("NO FUEL");
                    }
                    else if (player.ship.current_fuel < 1000)
                        FbColor(YELLOW);
                    else if (player.ship.current_fuel < 5000)
                        FbColor(GREEN);
                    FbMove(4, 125);
                    FbFilledRectangle(player.ship.current_fuel >> FUEL_MAX_SHIFT, 3);

                    // -----
                    // player health
                    FbColor(WHITE);
                    FbMove(3, 80);
                    FbRectangle(5, 26);

                    if(player.ship.current_hp < 25)
                        FbColor(RED);
                    else if (player.ship.current_hp < 70)
                        FbColor(YELLOW);
                    else
                        FbColor(GREEN);
                    FbMove(4, 81);
                    FbFilledRectangle(4, (unsigned char) (player.ship.current_hp >> 2));

                    //------
                    // Player points
                    FbColor(GREEN);
                    FbMove(3, 3);
                    badge_itoa((int)(player.kill_points), thrust_str, 6);
                    FbWriteLine(thrust_str);

                    FbSwapBuffers();
                    redraw = 0;
                }
                break;
            case BADGELANDIA_FAILURE:
                FbMove(28, 45);
                FbColor(WHITE);
                FbFilledRectangle(80, 17);
                FbMove(30, 50);
                FbColor(BLACK);
                FbWriteLine("You Failed");
                FbPushBuffer();
                if(BUTTON_PRESSED_AND_CONSUME)
                    badgelandia_state = BADGELANDIA_EXIT;
                break;
            case BADGELANDIA_WIN: //haha condition never met /sadface
                FbMove(28, 45);
                FbColor(WHITE);
                FbFilledRectangle(80, 17);
                FbMove(30, 50);
                FbColor(GREEN);
                FbWriteLine("You WIN");
                FbPushBuffer();
                if(BUTTON_PRESSED_AND_CONSUME)
                    badgelandia_state = BADGELANDIA_EXIT;
                break;
            case BADGELANDIA_MENU:
                genericMenu((struct menu_t *) badgelandia_menu,
                            WHITE_ON_BLACK);
                FbSwapBuffers();
                break;
            case BADGELANDIA_EXIT:
#ifndef SDL_BADGE
                returnToMenus();
#endif
                break;
            default:
                break;

        }
        vTaskDelay(tick_rate);
    }
}

