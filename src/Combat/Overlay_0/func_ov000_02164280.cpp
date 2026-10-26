#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Resource/GameResources.h"

struct Struct_0207df50 {
    unsigned int unknown_0_[10];
};

struct Struct_0207df50_2 {
    unsigned int unknown_0_[2];
};

struct Struct_0203d028 {
    struct Struct_0207df50 unknown_0_;
    struct Struct_0207df50 unknown_28_;
    unsigned int unknown_50_;
    unsigned int unknown_54_;
    struct Struct_0207df50_2 unknown_58_;
    struct Struct_0207df50_2 unknown_60_;
    unsigned int unknown_68_;
    unsigned int unknown_6c_;
};

struct Struct_ov000_02161e30_6 {
#if defined(jpn)
    char unknown_0_[0x27c];
#else
    char unknown1_0_[0x2cc];
#endif
    struct Struct_0203d028 unknown_2cc_[28];
};

struct Struct_ov000_02164280 {
#if defined(jpn)
    char unknown_0_[0x138];
#else
    char unknown1_0_[0x14c];
#endif
    struct Struct_0203d028 unknown_14c_;
#if defined(jpn)
    char unknown_1a8_[0x36ac - 0x1a8];
#else
    char unknown_1bc_[0x36f0 - 0x1bc];
#endif
    char unknown_36f0_[0x800];
};

extern "C" char* OamManager_GetInstance(void);
int* CachedTextTable_GetInstance();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int value);
void VramState_Rewind(struct Foo0207df50* p);
void OamManager_Init(char* context);
extern "C" void CachedTextTable_LoadPalettes(int* ptr);
void ClearFlag320_02195540(unsigned char* obj);
void VramState_Restore(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);
void VramState_Save(char* obj);

// USA: func_ov000_02164280
extern "C" ARM void func_ov000_02164280(BattleScreen* screen) {
    BattleResources* res = (BattleResources*)GetGameResources();
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
    ClearFlag320_02195540((unsigned char*)res);
    VramState_Rewind(res->pairTables);
    VramState_Restore((char*)res->pairTables);
    VramState_Reserve(screen->workBuf, 0x18000, 0x800);
    VramState_Save((char*)res->pairTables);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
