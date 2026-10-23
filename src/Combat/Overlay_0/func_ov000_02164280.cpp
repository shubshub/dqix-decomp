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

extern "C" char* func_0203bd08(void);
extern "C" int* func_0203bd14();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int value);
void CopyInternalFields0207df50(struct Foo0207df50* p);
void InitBattleContext0203bd24(char* context);
extern "C" void func_0203c35c(int* ptr);
void ClearFlag320_02195540(unsigned char* obj);
void VramState_Restore(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);
void VramState_Save(char* obj);

// USA: func_ov000_02164280
extern "C" ARM void func_ov000_02164280(Struct_ov000_02164280* arg0) {
    Struct_ov000_02161e30_6* var0 = (Struct_ov000_02161e30_6*)GetGameResources();
    char* var1 = func_0203bd08();
    int* var2 = func_0203bd14();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(7);
    func_020bb48c(3, 1);
    MapVRAMBanksToSubObj(8);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10 | 0x200000;
    MapVRAMBanksToSubBG(0x180);

    arg0->unknown_14c_.unknown_0_ = var0->unknown_2cc_[27].unknown_0_;
    arg0->unknown_14c_.unknown_28_ = var0->unknown_2cc_[27].unknown_28_;
    arg0->unknown_14c_.unknown_50_ = var0->unknown_2cc_[27].unknown_50_;
    arg0->unknown_14c_.unknown_54_ = var0->unknown_2cc_[27].unknown_54_;
    arg0->unknown_14c_.unknown_58_ = var0->unknown_2cc_[27].unknown_58_;
    arg0->unknown_14c_.unknown_60_ = var0->unknown_2cc_[27].unknown_60_;
    arg0->unknown_14c_.unknown_68_ = var0->unknown_2cc_[27].unknown_68_;
    arg0->unknown_14c_.unknown_6c_ = var0->unknown_2cc_[27].unknown_6c_;
    func_0207df50(&arg0->unknown_14c_);

    InitBattleContext0203bd24(context);
    func_0203c35c(global);
    ClearFlag320_02195540((unsigned char*)res);
    CopyInternalFields0207df50(res->pairTables);
    VramState_Restore((char*)res->pairTables);
    VramState_Reserve(screen->workBuf, 0x18000, 0x800);
    VramState_Save((char*)res->pairTables);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
