#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// Main, originally StoreVec3At0x34_0203a47c (USA 0x0203a47c, EUR 0x0203a48c, JPN 0x02039ed4)
extern "C" ARM void SprSprite_SetScale(unsigned int* spriteWords, unsigned int x, unsigned int y, unsigned int z) {
    Foo02048004* sprite = (Foo02048004*)spriteWords;
    sprite->scale.x = x;
    sprite->scale.y = y;
    sprite->scale.z = z;
}
