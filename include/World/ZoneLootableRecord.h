#pragma once

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_0204719c
{
    int unknown_0_;
    void* unknown_4_;
};

struct Struct_02012fa4
{
    unsigned int word0;
    unsigned short f4;
    unsigned short f6;
    unsigned int w8;
    unsigned int wc;
    unsigned int w10;
    NameTable02048080 nameTable;
    Vector3fix position;            // where it's drawn: a pot's world position (Zone3D_SetUpLootables), an icon's screen
                                    // x and y << 12 (ZoneChest_UpdateOpening, SearchPotTask_DrawSprite)
    unsigned int words28[3];
    Vector3fix scale;               // 1.0 on each axis after SprSprite_Init; a pot's 0x80 (Zone3D_SetUpLootables)
    unsigned int words40[16];
    unsigned short color;           // 0x7fff after SprSprite_Init; a pot's or barrel's diffuse colour
    unsigned short alpha;           // 0x1f after SprSprite_Init; icons fade by it (ZoneChest_UpdateOpening)
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
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
    unsigned char tail338[0x30];
};

void CopyFieldsWithFlags02048004(Foo02048004* src, Foo02048004* dst);
void SprSprite_Unload(Foo02048004* obj);
void ClearNameTable(NameTable02048080* table);
extern "C" void SprSprite_Init(void* obj);

