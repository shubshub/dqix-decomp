#include <globaldefs.h>

enum {
    GameObjectFlagsE0_WallHit = 0x40,        // GameObject_SetWallHit sets it with the wall polygon at +0xe4
    GameObjectFlagsE0_WallAttribute = 0x80,  // SetFlag0x80AndCopyToField0x11c sets it with the wall's attribute at +0x11c
};

struct ByteFlags02033f2c {
    char unknown0[0xe0];
    unsigned char flagsE0;
};

// Main, originally ClearFlags0x40And0x80At0xe0 (USA 0x02033f2c, EUR 0x02033f3c, JPN 0x02033a64)
extern "C" ARM void GameObject_ClearWallHit(struct ByteFlags02033f2c* object) {
    object->flagsE0 &= ~GameObjectFlagsE0_WallHit;
    object->flagsE0 &= ~GameObjectFlagsE0_WallAttribute;
}
