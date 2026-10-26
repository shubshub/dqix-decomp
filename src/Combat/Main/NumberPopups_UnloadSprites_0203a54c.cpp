#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// data_02104b6c, the battle's number popups, up to its sprites.
struct Container0203a54c {
    struct Foo02048004 numberSprites[5];
    struct Foo02048004 frameSprites[5];
};

void SprSprite_Unload(struct Foo02048004* obj);

// Main, originally ProcessAllSubObjects0203a54c (USA 0x0203a54c, EUR 0x0203a55c, JPN 0x02039fa4)
ARM void NumberPopups_UnloadSprites(struct Container0203a54c* numberPopups) {
    int i;
    for (i = 0; i < 5; i++) {
        SprSprite_Unload(&numberPopups->numberSprites[i]);
        SprSprite_Unload(&numberPopups->frameSprites[i]);
    }
}
