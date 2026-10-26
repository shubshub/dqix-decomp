#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// Both callers (Zone3D_Reset, Zone3D_Unload) pass a Zone3D's lootIcons_, its four Foo02048004 sprites
enum { kLootIconCount = 4 };

// Main, originally ResetFourSubStructs_02012fa4 (USA 0x02012fa4, EUR 0x02012fb4, JPN 0x02012d6c)
ARM void Zone3D_ResetLootIcons(char* lootIcons) {
    signed char i;
    for (i = 0; i < kLootIconCount; i++) {
        SprSprite_Unload((Foo02048004*)(lootIcons + i * sizeof(Foo02048004)));
        SprSprite_Init((Foo02048004*)(lootIcons + i * sizeof(Foo02048004)));
    }
}
