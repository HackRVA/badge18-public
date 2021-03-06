/** \file
 * Data structure for large binary data assets.
 */
#ifndef assetList_h
#define assetList_h

/*
 NOTE
 NOTE   LASTASSET has to be the LAST item in the enum 
 NOTE   insert new enums before it.
 NOTE
*/
enum {
        //DRBOB=0,
        FONT=0,
        BADGIO1,
        BADGIO2,
        BURGUNDY_POWER,
        DFIRE_BLURGGGH,
        DFIRE_BOSS,
        DFIRE_DIRIGIBLE,
        DFIRE_GAMEOF,
        DFIRE_IMPERIAL,
        DFIRE_SLURM,
        J46K,
        MAU5,
        NGE,
        SAND,
        WINXP,
        HACKRVA4,
        RVASEC2016,
        //BI_SPRITE,
        BADGEY_BIRD,
        LASTASSET,
};

enum {
    AUDIO,
    MIDI,
    PICTURE1BIT,
    PICTURE2BIT,
    PICTURE4BIT,
    PICTURE8BIT,
};

/**
 * A managed asset (binary data)
 */
struct asset {
    unsigned char assetId; /**< number (enum) used to reference object */
    unsigned char type;    /**< image/audio/midi/private */
    unsigned char seqNum; /**< \# images in the asset for animation, frame # for font char id; for audio, if you want to loop, 1 + the note index of the note you want to jump back to once completed, or zero if you don't want to loop */
    unsigned short x;	/**< array x; number of notes for audio */
    unsigned short y;	/**< array y; samples_per_step for audio */
    const char *data_cmap; /**< color map lookup table for image data */
    const char *pixdata;   /**< color pixel data */
    void (*datacb)(unsigned char, int); /**< routine that can display or play asset */
};

/** global array of static assets */
extern const struct asset assetList[];

#endif
