#pragma once

#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Background.h"

struct Entry02021578 {
    int field0;
    char* name;
    char pad8[0x1c];
};

struct Struct0205a198 {
    unsigned short count, flags;
    void* cells;
    void* copy;
    unsigned int field0c, field10, field14, field18;
    unsigned short field1c, index, field20;
    unsigned char firstCell, field23, field24, field25;
    signed char field26;
    char unknown_27_;
};

struct MapEntryList {
    unsigned char unknown0[0x40];
    Struct0205a198* records;
    unsigned char unknown44[8];
    unsigned short count;
    unsigned short unknown_4e_;
    unsigned char active;
    unsigned char unknown_51_[3];
};

struct ForwardingRecord02024518;
struct Node02021f88;

struct MapDisplay {
    char* GetMapNameText() { return (char*)unknown_5b4_; }
    char* GetLevelLabelText() { return (char*)&unknown_5b4_[0x40]; }
    unsigned char state;
    unsigned char unknown_1_;
    char unknown_2_[0x10];
    unsigned char field12;
    unsigned char unknown_13_;
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
    unsigned char unknown_55f_;
    int slots[4];
    unsigned char slotFlags[4];
    unsigned char unknown_574_[0x5a4 - 0x574];
    int flags;
    unsigned char field5a8;
    unsigned char unknown_5a9_[3];
    fix32_t cameraX;
    fix32_t cameraZ;
#if defined(jpn)
    unsigned char unknown_5b4_[0x6a8 - 0x5b4];
#else
    unsigned char unknown_5b4_[0x754 - 0x5b4];
#endif
    Node02021f88* field754;
    unsigned char flags758[4];
    unsigned char field75c;
    unsigned char field75d;
    unsigned char unknown_75e_[2];
    int field760;
    unsigned char field764;
    unsigned char field765;
    short field766;
    unsigned char field768;
    unsigned char unknown_769_[3];
    int field76c;
    int field770;
    int field774;
    unsigned char field778;
    unsigned char refreshRecords;
    unsigned char field77a;
    unsigned char unknown_77b_;
    int field77c;
    unsigned char field780;
    unsigned char unknown_781_[0x9b4 - 0x781];
    int field9b4;
    unsigned char field9b8;
    unsigned char field9b9;
    unsigned char field9ba;
    unsigned char unknown_9bb_;
    int field9bc;
    unsigned char actionState;
    unsigned char field9c1;
    signed char loadStage;
    unsigned char field9c3;
    unsigned char field9c4;
    unsigned char field9c5;
    unsigned char field9c6;
    unsigned char failed;
    unsigned char field9c8;
    unsigned char unknown_9c9_[3];
    int fileTask920;
    int namesTask;
    int fileTask928;
    int nameTasks[8];
    int scriptTask;
    int task9fc;
    int taska00;
    int taska04;
    int taska08;
    int taska0c;
    int taska10;
    int taska14;
    int taska18;
    int taska1c;
    int taska20;
    int taska24;
    int taska28;
    int taska2c;
    int fileTask984;
    unsigned char fielda34;
    unsigned char bytesa35[0x10];
    unsigned char bytesa45[0x10];
    unsigned char bytesa55[0x20];
#if !defined(jpn)
    unsigned char unknown_a75_[0x20];
#endif
    unsigned char fielda95;
    unsigned char fielda96;
    unsigned char fielda97;
    unsigned char unknown_a98_[4];
    int fielda9c;
    short fieldaa0;
    unsigned char bytesaa2[0x100];
#if !defined(jpn)
    char scriptName[0x40];
    unsigned char unknown_be2_[2];
    int scriptNameWidth;
    int fieldb3c;
    short fieldb40;
    short fieldb42;
    unsigned char savedTiles[0x40];
#endif
};

#if defined(jpn)
typedef int MapDisplayTaskHandle;
#else
typedef int* MapDisplayTaskHandle;
#endif

extern "C" void MapDisplay_ResetMap(MapDisplay* self);
// The caller supplies its display context; this global screen setup does not read it.
extern "C" void MapDisplay_SetUpLocalMapScreen(MapDisplay* unusedContext);
extern "C" void MapDisplay_LoadSpriteArchive(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator);
extern "C" void MapDisplay_RunMapScript(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator);
