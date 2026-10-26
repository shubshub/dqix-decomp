#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Resource/GameResources.h"

struct Struct_0207df50 {
    unsigned int v[10];
};

struct Struct_0207df50_2 {
    unsigned int v[2];
};

struct Foo0207df50 {
    struct Struct_0207df50 a;
    struct Struct_0207df50 b;
    unsigned int c;
    unsigned int d;
    struct Struct_0207df50_2 p1;
    struct Struct_0207df50_2 p2;
    unsigned int e;
    unsigned int f;
};

struct Struct_ov000_02161e30_6 {
#if defined(jpn)
    char pad0[0x27c];
#else
    char pad0[0x2cc];
#endif
    struct Foo0207df50 pairTables[28];
};

struct Struct_ov000_02164280 {
#if defined(jpn)
    char pad0[0x138];
#else
    char pad0[0x14c];
#endif
    struct Foo0207df50 pairTables;
#if defined(jpn)
    char unknown_1a8_[0x36ac - 0x1a8];
#else
    char unknown_1bc_[0x36f0 - 0x1bc];
#endif
    char workBuf[0x800];
};

extern "C" char* OamManager_GetInstance(void);
extern "C" int* CachedTextTable_GetInstance();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int mode, int arg1);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int value);
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void OamManager_Init(char* context);
extern "C" void CachedTextTable_LoadPalettes(int* ptr);
extern "C" void func_ov017_02195540(unsigned char* obj);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);
extern "C" void VramState_Save(char* obj);

// USA: func_ov000_02164280
extern "C" ARM void func_ov000_02164280(Struct_ov000_02164280* screen) {
    Struct_ov000_02161e30_6* res = (Struct_ov000_02161e30_6*)GetGameResources();
    char* context = OamManager_GetInstance();
    int* global = CachedTextTable_GetInstance();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(7);
    func_020bb48c(3, 1);
    MapVRAMBanksToSubObj(8);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10 | 0x200000;
    MapVRAMBanksToSubBG(0x180);

    screen->pairTables.a = res->pairTables[27].a;
    screen->pairTables.b = res->pairTables[27].b;
    screen->pairTables.c = res->pairTables[27].c;
    screen->pairTables.d = res->pairTables[27].d;
    screen->pairTables.p1 = res->pairTables[27].p1;
    screen->pairTables.p2 = res->pairTables[27].p2;
    screen->pairTables.e = res->pairTables[27].e;
    screen->pairTables.f = res->pairTables[27].f;
    VramState_Rewind(&screen->pairTables);

    OamManager_Init(context);
    CachedTextTable_LoadPalettes(global);
    func_ov017_02195540((unsigned char*)res);
    VramState_Rewind(res->pairTables);
    VramState_Restore((char*)res->pairTables);
    VramState_Reserve(screen->workBuf, 0x18000, 0x800);
    VramState_Save((char*)res->pairTables);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
