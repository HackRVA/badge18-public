#include "colors.h"
#include "badge_menu.h"
#include "buttons.h"
#include "jukebox.h"

#include "assetList.h"

// If ordering changed, make sure indices still work
// in the populate function
struct menu_t jukebox_config_m[] = {
    {"Blurgggh", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_blurgggh}},
    {"Bpower", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_burgundy_power}},
    {"Boss", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_boss}},
    {"Dirigible", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_dirigible}},
    {"Game of", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_gameof}},
    {"Imperial", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_imperial}},
    {"Mau5", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_mau5}},
    {"J46k", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_j46k}},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"Next page", VERT_ITEM|DEFAULT_ITEM, FUNCTION, {(struct menu_t *) jb_switch_pages}},
    {"Exit", VERT_ITEM|LAST_ITEM, FUNCTION, {(struct menu_t *) set_jb_exit}},
};

struct menu_t jukebox_config_n[] = {
    {"Slurm", VERT_ITEM, FUNCTION, {(struct menu_t *) jb_play_slurm}},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"", VERT_ITEM|SKIP_ITEM, TEXT, 0},
    {"Prev page", VERT_ITEM|DEFAULT_ITEM, FUNCTION, {(struct menu_t *) jb_switch_pages}},
    {"Exit", VERT_ITEM|LAST_ITEM, FUNCTION, {(struct menu_t *) set_jb_exit}},
};

char which_menu = 0;

char image = 0;

enum
{
    INIT,
    SHOW_MENU,
    RUN_jukebox
};

char jb_state = INIT;

void set_jb_exit(void)
{
    jb_state = INIT;
    returnToMenus();
}

void jb_play_burgundy_power(void)
{
    playAsset(BURGUNDY_POWER);
}

void jb_play_blurgggh(void)
{
    playAsset(DFIRE_BLURGGGH);
}

void jb_play_boss(void)
{
    playAsset(DFIRE_BOSS);
}

void jb_play_dirigible(void)
{
    playAsset(DFIRE_DIRIGIBLE);
}

void jb_play_gameof(void)
{
    playAsset(DFIRE_GAMEOF);
}

void jb_play_imperial(void)
{
    playAsset(DFIRE_IMPERIAL);
}

void jb_play_slurm(void)
{
    playAsset(DFIRE_SLURM);
}

void jb_play_j46k(void)
{
    playAsset(J46K);
}

void jb_play_mau5(void)
{
    playAsset(MAU5);
}

void jb_switch_pages(void)
{
    which_menu = !which_menu;
}

void jukebox_task(void *args)
{
    for (;;) {
        switch (jb_state) {

        case INIT:
            jb_state++;
            break;

        case SHOW_MENU:
            genericMenu((struct menu_t *) (which_menu ? jukebox_config_n : jukebox_config_m), MAIN_MENU_STYLE);
            FbSwapBuffers();
            break;
        }
    }
}
