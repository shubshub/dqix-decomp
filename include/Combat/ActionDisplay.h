#pragma once

#include "NitroSDK/Matrix.h"
#include "NitroSDK/Memory.h"
#include <globaldefs.h>

struct CombatActionPosition {
    Vector3i position;
    unsigned char elementId;
    unsigned char palette;
    unsigned char type;
    signed char variant;
    unsigned char group;
    unsigned char flag11;
    unsigned char unknown_12_;
    unsigned char flag13;
    unsigned char combatantId;
    unsigned char unknown15[3];

    inline CombatActionPosition() {
        VectorizedMemset(this, 0, sizeof(CombatActionPosition));
        variant     = -1;
        combatantId = 0xff;
    }
};

static inline int inline_02024518(unsigned char type) {
    return type >= 0x74;
}

extern int data_020e70f0[][4][2];
extern int data_020e70f4[][4][2];

extern "C" {
int MapDisplay_CollectIcons(CombatActionPosition *entries, unsigned char *groups, Vector3i *position);
void MapDisplay_DrawRedChestMarkers(void *receiver, int tileX, int tileY, int xOffset, int yOffset, unsigned char flag);
void MapDisplay_DrawBattleMarkers(void *receiver, CombatActionPosition *entries, int count, int tileX, int tileY, int xOffset, int yOffset,
                   int flags);
void func_02024e78(void *receiver);
void func_020251bc(void *receiver);
}
