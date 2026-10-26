#include <globaldefs.h>
#include "World/Zone3D.h"

#if defined(jpn)
enum { kNumChestsOffset = 0x497 };
#else
enum { kNumChestsOffset = 0x477 };
#endif

// The Zone3D (this file's copy of the fields it uses)
struct Holder020159c0 {
    unsigned char pad0[kNumChestsOffset];
    unsigned char numChests_;
    unsigned char pad478[4];
    ZoneChestRenderRecord* chests_;
    unsigned char pad480[0x820 - 0x480];
    int lootIconAlpha_;
};

// Main, originally ClearMatchingEntries020159c0 (USA 0x020159c0, EUR 0x020159d0, JPN 0x0201578c)
ARM void Zone3D_ClearChestIconsByOpener(struct Holder020159c0* zone, int opener) {
    int isPlayerIndex;
    int i;
    if (opener >= 0 && opener <= 3) {
        isPlayerIndex = 1;
    } else {
        isPlayerIndex = 0;
    }
    if (isPlayerIndex == 0) {
        return;
    }
    for (i = 0; i < zone->numChests_; i++) {
        ZoneChestRenderRecord* chest = &zone->chests_[i];
        if (chest->icon != NULL && chest->opener == opener) {
            chest->icon = NULL;
            zone->lootIconAlpha_ = 0;
        }
    }
}
