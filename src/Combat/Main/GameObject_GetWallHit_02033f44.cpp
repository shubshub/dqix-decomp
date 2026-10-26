#include <globaldefs.h>

struct BitFlag02033f44 {
    char unknown0[0xe0];
    unsigned char unknownBits0To5 : 6;
    unsigned char wallHit : 1;           // set with the wall polygon by GameObject_SetWallHit
    unsigned char wallAttributeSet : 1;  // set with the wall's attribute by SetFlag0x80AndCopyToField0x11c
    char unknownE1[3];
    int wall;                            // the wall polygon's three corners, then its normal (callers read +0x24)
};

// Main, originally GetField0xe4IfFlag0x40 (USA 0x02033f44, EUR 0x02033f54, JPN 0x02033a7c)
ARM int* GameObject_GetWallHit(struct BitFlag02033f44* object) {
    return object->wallHit ? &object->wall : 0;
}
