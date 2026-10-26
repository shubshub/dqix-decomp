#pragma once

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Background.h"

struct Struct_020210f8 {
    int unknown_0_;
    char* unknown_4_;
    char unknown_8_[0x1c];
};

struct Struct_02043368_2 {
    unsigned short unknown_0_, unknown_2_;
    void* unknown_4_;
    void* unknown_8_;
    unsigned int unknown_c_, unknown_10_, unknown_14_, unknown_18_;
    unsigned short unknown_1c_, unknown_1e_, unknown_20_;
    unsigned char unknown_22_, unknown_23_, unknown_24_, unknown_25_;
    signed char unknown_26_;
    char unknown_27_;
};

struct Struct_02021578 {
    unsigned char unknown_0_[0x40];
    Struct_02043368_2* unknown_40_;
    unsigned char unknown_44_[8];
    unsigned short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    unsigned char unknown_51_[3];
};

struct ForwardingRecord02024518;
struct Node02021f88;

struct MapDisplay {
    char* GetMapNameText() { return (char*)unknown5b4; }
    char* GetLevelLabelText() { return (char*)&unknown5b4[0x40]; }
    unsigned char state;
    unsigned char unknown1;
    char headerName[0x10];
    unsigned char field12;
    unsigned char unknown13;
    int displayMode;
    int forwardingX;
    int forwardingY;
    Entry02021578* names;
    int nameCount;
    int field28;
    ForwardingRecord02024518* forwarding;
    int forwardingCount;
    int field34;
    fix32_t scale;
    fix32_t cameraBiasX;
    fix32_t cameraBiasZ;
    int screenX;
    int screenY;
    BackgroundGraphics list4c;
    void* mapState;
    int mapPalette;
    int forwardingFill;
    unsigned char unknown78[0x94 - 0x78];
    MapEntryList entryList;
    Struct0205a198 records[28];
    char name[0x10];
    unsigned char recordVisible[4];
    unsigned char forwardingPending;
    unsigned char mask55d;
    unsigned char field55e;
    unsigned char unknown55f;
    int slots[4];
    unsigned char slotFlags[4];
    unsigned char unknown574[0x5a4 - 0x574];
    int flags;
    unsigned char field5a8;
    unsigned char unknown5a9[3];
    fix32_t cameraX;
    fix32_t cameraZ;
#if defined(jpn)
    unsigned char unknown_5b4_[0x6a8 - 0x5b4];
#else
    unsigned char unknown_5b4_[0x754 - 0x5b4];
#endif
    Struct_02021f88* unknown_754_;
    unsigned char unknown_758_[4];
    unsigned char unknown_75c_;
    unsigned char unknown_75d_;
    unsigned char unknown_75e_[2];
    int unknown_760_;
    unsigned char unknown_764_;
    unsigned char unknown_765_;
    short unknown_766_;
    unsigned char unknown_768_;
    unsigned char unknown_769_[3];
    int unknown_76c_;
    int unknown_770_;
    int unknown_774_;
    unsigned char unknown_778_;
    unsigned char unknown_779_;
    unsigned char unknown_77a_;
    unsigned char unknown_77b_;
    int unknown_77c_;
    unsigned char unknown_780_;
    unsigned char unknown_781_[0x9b4 - 0x781];
    int unknown_9b4_;
    unsigned char unknown_9b8_;
    unsigned char unknown_9b9_;
    unsigned char unknown_9ba_;
    unsigned char unknown_9bb_;
    int unknown_9bc_;
    unsigned char unknown_9c0_;
    unsigned char unknown_9c1_;
    signed char unknown_9c2_;
    unsigned char unknown_9c3_;
    unsigned char unknown_9c4_;
    unsigned char unknown_9c5_;
    unsigned char unknown_9c6_;
    unsigned char unknown_9c7_;
    unsigned char unknown_9c8_;
    unsigned char unknown_9c9_[3];
    int unknown_9cc_;
    int unknown_9d0_;
    int unknown_9d4_;
    int unknown_9d8_[8];
    int unknown_9f8_;
    int unknown_9fc_;
    int unknown_a00_;
    int unknown_a04_;
    int unknown_a08_;
    int unknown_a0c_;
    int unknown_a10_;
    int unknown_a14_;
    int unknown_a18_;
    int unknown_a1c_;
    int unknown_a20_;
    int unknown_a24_;
    int unknown_a28_;
    int unknown_a2c_;
    int unknown_a30_;
    unsigned char unknown_a34_;
    unsigned char unknown_a35_[0x10];
    unsigned char unknown_a45_[0x10];
    unsigned char unknown_a55_[0x20];
#if !defined(jpn)
    unsigned char unknown_a75_[0x20];
#endif
    unsigned char unknown_a95_;
    unsigned char unknown_a96_;
    unsigned char unknown_a97_;
    unsigned char unknown_a98_[4];
    int unknown_a9c_;
    short unknown_aa0_;
    unsigned char unknown_aa2_[0x100];
#if !defined(jpn)
    char unknown_ba2_[0x40];
    unsigned char unknown_be2_[2];
    int unknown_be4_;
    int unknown_be8_;
    short unknown_bec_;
    short unknown_bee_;
    unsigned char unknown_bf0_[0x40];
#endif
};

#if defined(jpn)
typedef int Type_02020aec;
#else
typedef int* Type_02020aec;
#endif

extern "C" void MapDisplay_ResetMap(MapDisplay* self);
// The caller supplies its display context; this global screen setup does not read it.
extern "C" void MapDisplay_SetUpLocalMapScreen(MapDisplay* unusedContext);
extern "C" void MapDisplay_LoadSpriteArchive(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator);
extern "C" void MapDisplay_RunMapScript(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator);
