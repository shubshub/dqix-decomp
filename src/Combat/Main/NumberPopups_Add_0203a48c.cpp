#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Vec3Int0203a48c {
    int x;
    int y;
    int z;
};

// One number popup (see NumberPopups_Init).
struct NumberPopup {
    unsigned short value;
    unsigned short offsetY;
    unsigned char offsetX;
    unsigned char timer;
    unsigned char digitCount;
    unsigned char style;
    unsigned short frameVelocity;
    unsigned short frameScale;
    int anchorX;
    int anchorY;
    int anchorZ;
};

// data_02104b6c, the battle's number popups: a ring of 16, added at tail.
struct Obj0203a48c {
    Foo02048004 numberSprites[5];
    Foo02048004 frameSprites[5];
    struct NumberPopup popups[16];
    int head;
    int tail;
};

enum {
    kNumberPopupTimer_Start = 0x25,             // frames; it shows from 34 down (NumberPopups_Draw)
    kNumberPopupFrameScale_Start = 0x1333,      // 1.2, springing back to 1.0 (NumberPopups_Update)
    kNumberPopupFrameVelocity_Start = 0x333,    // 0.2 per frame
};

// Main, originally QueuePopupEntry0203a48c (USA 0x0203a48c, EUR 0x0203a49c, JPN 0x02039ee4)
ARM void NumberPopups_Add(Obj0203a48c* numberPopups, int value, Vec3Int0203a48c* anchor, int style, int offsetX, int offsetY) {
    int remaining;
    int digitCount;
    struct NumberPopup* popup;

    remaining = value;
    digitCount = 0;
    while (remaining > 0) {
        remaining = remaining / 10;
        digitCount++;
    }
    if (digitCount == 0) {
        return;
    }

    popup = &numberPopups->popups[numberPopups->tail];
    popup->timer = kNumberPopupTimer_Start;
    popup->value = value;
    popup->anchorX = anchor->x;
    popup->anchorY = anchor->y;
    popup->anchorZ = anchor->z;
    popup->offsetX = offsetX;
    popup->offsetY = offsetY;
    popup->digitCount = digitCount;
    popup->frameVelocity = kNumberPopupFrameVelocity_Start;
    popup->frameScale = kNumberPopupFrameScale_Start;
    popup->style = style;

    numberPopups->tail = numberPopups->tail + 1;
    if (numberPopups->tail >= 0x10) {
        numberPopups->tail = 0;
    }
}
