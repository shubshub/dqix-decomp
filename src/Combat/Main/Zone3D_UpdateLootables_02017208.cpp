#include <globaldefs.h>
#if defined(jpn)
enum { kNumLootablesOffset = 0x496 };
#else
enum { kNumLootablesOffset = 0x476 };
#endif
#include "GameState/GameState.h"
#include "World/ZoneLootableRecord.h"

// A breaking lootable is gone (Searched) after this many ticks; each tick its fragments fall this much faster
enum {
    kBreakTicks = 20,
    kFragmentGravity = 0x40,
};

struct ZoneLootableRecord02017208 {
    short id;
    short state;                // ZoneLootableState
    short breakTimer;
    unsigned char reserved6[2];
    Foo02048004 primary[2];
    Foo02048004 fragments[4];
    Vector3i fragmentVelocities[4];
};

struct Zone3D02017208 {
    char unknown0[kNumLootablesOffset];
    unsigned char numLootables_;
    unsigned char numChests_;
    struct ZoneLootableRecord02017208* lootables_;
};

// Main, originally func_02017208 (USA 0x02017208, EUR 0x02017218, JPN 0x02016fa8)
extern "C" ARM void Zone3D_UpdateLootables(struct Zone3D02017208* zone) {
    unsigned int ticks;
    int i;
    struct ZoneLootableRecord02017208* lootable;
    int tick;
    int j;

    ticks = GameState::GetInstance()->GetTickCount();

    for (i = 0; i < zone->numLootables_; i++) {
        lootable = &zone->lootables_[i];
        if (lootable->state == ZoneLootableState_Searched) continue;
        for (tick = 0; tick < ticks; tick++) {
            if (lootable->state == ZoneLootableState_Breaking) {
                lootable->breakTimer++;
                if (lootable->breakTimer > kBreakTicks) {
                    lootable->state = ZoneLootableState_Searched;
                } else {
                    for (j = 0; j < 4; j++) {
                        Vector3i position;
                        Foo02048004* fragment = &lootable->fragments[j];
                        Vector3fix_Add(&fragment->position, &lootable->fragmentVelocities[j], &position);
                        fragment->position = position;
                        lootable->fragmentVelocities[j].y -= kFragmentGravity;
                    }
                }
            }
        }
    }
}
