#include <globaldefs.h>

// The head of one of the battle's number popups (data_02104b6c +0x550, 0x18 bytes each).
struct ResetStruct_39ee8 {
    unsigned short value;
    short offsetY;
    signed char offsetX;
    unsigned char timer;
    unsigned char digitCount;
    unsigned char style;
    unsigned short frameVelocity;
};

// Main, originally ResetFields39ee8_02039ee8 (USA 0x02039ee8, EUR 0x02039ef8, JPN 0x02039940)
ARM void NumberPopup_Clear(struct ResetStruct_39ee8* popup) {
    popup->value = 0;
    popup->timer = 0;
    popup->digitCount = 0;
    popup->frameVelocity = 0;
    popup->style = 0;
}
