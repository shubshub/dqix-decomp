#pragma once

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_0204719c
{
    int count;
    void* entries;
};

struct Foo02048004
{
    unsigned int word0;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned int w8;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    Struct_0204719c nameTable;
    Vector3fix position;            // where it's drawn: a pot's world position (Zone3D_SetUpLootables), an icon's screen
                                    // x and y << 12 (ZoneChest_UpdateOpening, SearchPotTask_DrawSprite)
    unsigned int words28[3];
    Vector3fix scale;               // 1.0 on each axis after SprSprite_Init; a pot's 0x80 (Zone3D_SetUpLootables)
    unsigned int words40[16];
    unsigned short color;           // 0x7fff after SprSprite_Init; a pot's or barrel's diffuse colour
    unsigned short alpha;           // 0x1f after SprSprite_Init; icons fade by it (ZoneChest_UpdateOpening)
    unsigned char bit0 : 1;
    unsigned char unknown_84_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

// ZoneLootableRecord::state
enum ZoneLootableState {
    ZoneLootableState_Searched = -1,    // ZoneLootable_Init, and searched ones on zone entry (Zone3D_SetSearchedLootables)
    ZoneLootableState_Searchable = 0,   // Zone3D_SetUpLootables; func_ov017_0218dfd8 only considers these
    ZoneLootableState_Breaking = 3,     // Zone3D_BreakLootable
};

struct ZoneLootableRecord
{
    unsigned short id;
    short state;                    // ZoneLootableState
    short field4;
    unsigned char reserved6[2];
    Foo02048004 primary[2];
    Foo02048004 fragments[4];
    unsigned char unknown_338_[0x30];
};

extern "C" void func_02048004(Foo02048004* src, Foo02048004* dst);
extern "C" void SprSprite_Unload(Foo02048004* obj);
extern "C" void func_02048080(Struct_0204719c* table);
extern "C" void SprSprite_Init(void* obj);

