#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct ResetStruct_39ee8;
void NumberPopup_Clear(struct ResetStruct_39ee8* s);

// One number popup: value drawn digit by digit over its anchor (a world position), offset on screen, for timer frames;
// its frame sprite's scale springs from frameScale towards 1.0 (0x1000).
struct NumberPopup {
    unsigned short value;
    short offsetY;
    signed char offsetX;
    signed char timer;
    unsigned char digitCount;
    unsigned char style;
    short frameVelocity;
    short frameScale;
    Vector3fix anchor;
};

// data_02104b6c: the battle's number popups (damage, recovery, tension). Each style has a number sprite and a frame
// sprite (damage_num.spr / damage_waku.spr ...), and the popups are a ring of 16 from head to tail.
struct NumberPopups {
    Foo02048004 numberSprites[5];
    Foo02048004 frameSprites[5];
    NumberPopup popups[16];
    int head;
    int tail;
};

// Main, originally ResetBattleArrays02039e7c (USA 0x02039e7c, EUR 0x02039e8c, JPN 0x020398d4)
ARM void NumberPopups_Init(void* popupsRaw) {
    NumberPopups* numberPopups = (NumberPopups*)popupsRaw;
    int i;
    for (i = 0; i < 0x10; i++) {
        NumberPopup_Clear((struct ResetStruct_39ee8*)&numberPopups->popups[i]);
    }
    for (i = 0; i < 5; i++) {
        SprSprite_Init(&numberPopups->numberSprites[i]);
        SprSprite_Init(&numberPopups->frameSprites[i]);
    }
    numberPopups->head = 0;
    numberPopups->tail = 0;
}
