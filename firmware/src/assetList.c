/**
    simple assetList library
    Author: Paul Bruggeman
    paul@killercats.com
    4/2015
*/

//#include "badge16.h"
#ifdef SDL_BADGE
#include "sdl_fb.h"
#endif
#include "assetList.h"
#include "assets.h"
#include "colors.h"

//#define HACKRVA4BIT_LORES
#include "hackrva4bit.h"

#define RVASEC2016BITS_LORES
#include "rvasec2016.h"

//#define DRBOB_LORES
//#include "drbob.h"

//#define BINVAD_LORES
//#include "binvad.h"

#include "badgeybird_img.h"

#include "font_2.xbm"

#include "song/badgio.h"
#include "song/burgundy_power.h"
#include "song/dfire_blurgggh.h"
#include "song/dfire_boss.h"
#include "song/dfire_dirigible.h"
#include "song/dfire_gameof.h"
#include "song/dfire_imperial.h"
#include "song/dfire_slurm.h"
#include "song/j46k.h"
#include "song/mau5.h"
#include "song/nge.h"
#include "song/sand.h"

/* for 1 bit images */
/* testing color instead of BW */
const static char BW_cmap[2][3] = {
{ 32, 32, 32 },
{ 64, 192, 64 },
};

/*
   all pixels should fill a whole byte and be evenly divided.
   1 bit/pixel image has a min width of 8 pixels
   2 bits/pixel = 4 pixels wide min.
   4 bits/pixel = 2 pixels wide min.

 NOTE
 NOTE   if you add or remove an item ALSO add or remove it in the enum in assetList.h
 NOTE

*/
#ifdef SDL_BADGE
const struct asset assetList[] = {
{ FONT, PICTURE1BIT, 42, 8, 8, (const char *)BW_cmap, (const char *)font_2_bits, (FbImage1bit) },
//    { DRBOB, DRBOB_BITS, 1, DRBOB_WIDTH, DRBOB_HEIGHT, (const char *)DRBOB_CMAP, (const char *)DRBOB_DATA, (drawLCD8) },
    { HACKRVA4, HACKRVA4_BITS, 1, HACKRVA4_WIDTH, HACKRVA4_HEIGHT, (const char *)HACKRVA4_CMAP, (const char *)HACKRVA4_DATA, (FbImage2bit) },
    { RVASEC2016, RVASEC2016_BITS, 1, RVASEC2016_WIDTH, RVASEC2016_HEIGHT, (const char *)RVASEC2016_CMAP, (const char *)RVASEC2016_DATA, (FbImage2bit) },
    
//    { BI_SPRITE, BADINVAD_BITS, 1, BI_sprite_width, BI_sprite_height, (const char *)BW_cmap, (const char *)BADINVAD_DATA, (drawLCD1) },
    { BADGEY_BIRD, BADGEYBIRD_BITS, 1, BADGEYBIRD_WIDTH, BADGEYBIRD_HEIGHT, (const char *)BADGEYBIRD_CMAP, (const char *)BADGEYBIRD_DATA, (FbImage4bit) },
};
#else
const struct asset assetList[] = {
 { FONT, PICTURE1BIT, 42, 8, 8, (const char *) BW_cmap, (const char *) font_2_bits, (drawLCD1) },
 { BADGIO, AUDIO, NOTEDATA_badgio_NOTES, NOTEDATA_badgio_SPEED, 0, (void *) 0, notedata_badgio, (void *) 0 },
 { BURGUNDY_POWER, AUDIO, NOTEDATA_burgundy_power_NOTES, NOTEDATA_burgundy_power_SPEED, 1, (void *) 0, notedata_burgundy_power, (void *) 0 },
 { DFIRE_BLURGGGH, AUDIO, NOTEDATA_dfire_blurgggh_NOTES, NOTEDATA_dfire_blurgggh_SPEED, 33, (void *) 0, notedata_dfire_blurgggh, (void *) 0 },
 { DFIRE_BOSS, AUDIO, NOTEDATA_dfire_boss_NOTES, NOTEDATA_dfire_boss_SPEED, 1, (void *) 0, notedata_dfire_boss, (void *) 0 },
 { DFIRE_DIRIGIBLE, AUDIO, NOTEDATA_dfire_dirigible_NOTES, NOTEDATA_dfire_dirigible_SPEED, 1, (void *) 0, notedata_dfire_dirigible, (void *) 0 },
 { DFIRE_GAMEOF, AUDIO, NOTEDATA_dfire_gameof_NOTES, NOTEDATA_dfire_gameof_SPEED, 1, (void *) 0, notedata_dfire_gameof, (void *) 0 },
 { DFIRE_IMPERIAL, AUDIO, NOTEDATA_dfire_imperial_NOTES, NOTEDATA_dfire_imperial_SPEED, 1, (void *) 0, notedata_dfire_imperial, (void *) 0 },
 { DFIRE_SLURM, AUDIO, NOTEDATA_dfire_slurm_NOTES, NOTEDATA_dfire_slurm_SPEED, 0, (void *) 0, notedata_dfire_slurm, (void *) 0 },
 { J46K, AUDIO, NOTEDATA_j46k_NOTES, NOTEDATA_j46k_SPEED, 1, (void *) 0, notedata_j46k, (void *) 0 },
 { MAU5, AUDIO, NOTEDATA_mau5_NOTES, NOTEDATA_mau5_SPEED, 1, (void *) 0, notedata_mau5, (void *) 0 },
 { NGE, AUDIO, NOTEDATA_nge_NOTES, NOTEDATA_nge_SPEED, 1, (void *) 0, notedata_nge, (void *) 0 },
 { SAND, AUDIO, NOTEDATA_sand_NOTES, NOTEDATA_sand_SPEED, 1, (void *) 0, notedata_sand, (void *) 0 },
 //{ DRBOB, DRBOB_BITS, 1, DRBOB_WIDTH, DRBOB_HEIGHT, (const char *)DRBOB_CMAP, (const char *)DRBOB_DATA, (drawLCD8) },
 { HACKRVA4, HACKRVA4_BITS, 1, HACKRVA4_WIDTH, HACKRVA4_HEIGHT, (const char *)HACKRVA4_CMAP, (const char *)HACKRVA4_DATA, (drawLCD4) },
 { RVASEC2016, RVASEC2016_BITS, 1, RVASEC2016_WIDTH, RVASEC2016_HEIGHT, (const char *)RVASEC2016_CMAP, (const char *)RVASEC2016_DATA, (drawLCD2) },

 //{ BI_SPRITE, BADINVAD_BITS, 1, BI_sprite_width, BI_sprite_height, (const char *)BW_cmap, (const char *)BADINVAD_DATA, (drawLCD1) },
 { BADGEY_BIRD, BADGEYBIRD_BITS, 1, BADGEYBIRD_WIDTH, BADGEYBIRD_HEIGHT, (const char *)BADGEYBIRD_CMAP, (const char *)BADGEYBIRD_DATA, (drawLCD4) },
};
#endif
