#pragma once

#include "NitroSDK/Matrix.h"
#include "NitroSDK/Memory.h"
#include <globaldefs.h>

struct Struct_020236dc {
    Vector3i unknown_0_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    signed char unknown_f_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    unsigned char unknown_14_;
    unsigned char unknown_15_[3];

    inline Struct_020236dc() {
        VectorizedMemset(this, 0, sizeof(Struct_020236dc));
        unknown_f_     = -1;
        unknown_14_ = 0xff;
    }
};

static inline int inline_02024518(unsigned char arg0) {
    return arg0 >= 0x74;
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
