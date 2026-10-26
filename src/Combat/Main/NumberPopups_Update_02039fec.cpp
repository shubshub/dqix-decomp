#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// One number popup (see NumberPopups_Init): its frame sprite's scale springs from frameScale towards 1.0.
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

// data_02104b6c, the battle's number popups: a ring of 16 from head to tail.
struct Obj02039fec {
    Foo02048004 numberSprites[5];
    Foo02048004 frameSprites[5];
    struct NumberPopup popups[16];
    int head;
    int tail;
};

enum { kNumberPopupTimer_Placed = 0x22 };   // the frame NumberPopups_AvoidOverlap moves a new popup clear of the others

extern "C" void NumberPopups_AvoidOverlap(struct Obj02039fec* numberPopups, int index);

// Main, originally ProcessSlotDamping02039fec (USA 0x02039fec, EUR 0x02039ffc, JPN 0x02039a44)
ARM void NumberPopups_Update(struct Obj02039fec* numberPopups) {
    int i = numberPopups->head;
    while (i != numberPopups->tail) {
        struct NumberPopup* popup = &numberPopups->popups[i];
        popup->frameScale += popup->frameVelocity;
        popup->frameVelocity = popup->frameVelocity + ((0x1000 - popup->frameScale) >> 1);
        popup->frameVelocity = (short)(0.8f * popup->frameVelocity);
        popup->timer--;
        if (popup->timer <= 0) {
            int next = i + 1;
            numberPopups->head = next;
            if (next >= 16) numberPopups->head = 0;
        } else if (popup->timer == kNumberPopupTimer_Placed) {
            NumberPopups_AvoidOverlap(numberPopups, i);
        }
        i++;
        if (i >= 16) i = 0;
    }
}
