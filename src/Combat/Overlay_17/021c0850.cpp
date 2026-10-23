#include <globaldefs.h>
#include "GameState/Field3b0.h"

#if defined(jpn)
enum { Enum_ov017_021c0850_123784 = 0x1e384, Enum_ov017_021c0850_2888 = 0xb44, Enum_ov017_021c0850_108 = 0x8c, Enum_ov017_021c0850_1288 = 0x608, Enum_ov017_021c0850_728 = 0x228, Enum_ov017_021c0850_742 = 0x236 };
#else
enum { Enum_ov017_021c0850_123784 = 0x1e388, Enum_ov017_021c0850_2888 = 0xb48, Enum_ov017_021c0850_108 = 0x6c, Enum_ov017_021c0850_1288 = 0x508, Enum_ov017_021c0850_728 = 0x2d8, Enum_ov017_021c0850_742 = 0x2e6 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/VRAM.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
struct Struct_02018300_3;
struct Struct_ov017_021c0580;
struct Struct_0201e830;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Struct_020469f8;
struct Struct_020469f8_2;

struct Struct_ov003_0217e6b0 {
    unsigned int unknown_0_0_ : 24;
    unsigned int unknown_3_0_ : 3;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov017_021c0850 {
    char unknown_0_[0xb13];
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    union {
        unsigned int unknown_b18_;
        struct {
            unsigned int unknown_0_0_ : 1;
            unsigned int unknown_0_1_ : 17;
            unsigned int unknown_2_2_ : 1;
            unsigned int unknown_2_3_ : 13;
        } unknown1_b18_;
    };
    char unknown_b1c_[0xc];
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
};

struct Struct_ov017_021c0850_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_ov017_021c0850* unknown_1c_;
    int unknown_20_;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
    short unknown_28_;
    short unknown_2a_;
    char unknown_2c_[0x10];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    char unknown_3e_[2];
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    char unknown_50_[8];
    int unknown_58_;
    int unknown_5c_;
    int unknown_60_;
    int unknown_64_;
    int unknown_68_;
    char unknown_6c_[4];
    int unknown_70_[10];
    int unknown_98_[2];
    unsigned int unknown_a0_;
    unsigned int unknown_a4_;
    unsigned short unknown_a8_;
    char unknown_aa_[2];
    int unknown_ac_;
    int unknown_b0_;
    int unknown_b4_;
    void* unknown_b8_;
    unsigned char unknown_bc_;
};

extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void func_020a0c0c(void);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_020a1940(unsigned int arg0);
extern "C" void func_020a1ef0(int arg0);
extern "C" void func_ov008_021843f8(void* arg0);
extern "C" void func_ov008_021842a0(void* arg0, SafeAllocator* arg1);
struct Struct_0209cae8;
extern "C" int func_0209cae8(Struct_0209cae8*);
struct Struct_02109bf4_4;
extern "C" void func_0209c678(Struct_02109bf4_4*, int);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0203cf4c(void);
extern "C" void func_0203e0a0(void* arg0, unsigned short arg1);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* arg0);
extern "C" void func_02074b64(Struct_02074b64* arg0);
extern "C" void func_020bb700(int* arg0);
extern "C" void func_020bb740(int* arg0);
extern "C" void func_020bb910(int* arg0);
extern "C" unsigned short func_0201e830(Struct_0201e830* arg0);
extern "C" void func_020100c4(GameState* arg0, int arg1);
void LockStagedTextureVRAMCopying(void);
void UnlockStagedTextureVRAMCopying(void);
void UpdateVRAMStagingVRAMBanks(void);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020c54a4(int arg0, unsigned int arg1, unsigned int arg2, unsigned short arg3);
extern "C" void* func_0203bd08(void);
extern "C" void func_0203bd24(char* arg0);
extern "C" int* func_0203bd14(void);
extern "C" int func_0203be4c(void* arg0);
extern "C" void func_0203c35c(int* arg0);
extern "C" int func_ov017_021959b4(void);
void SetFlagBit_02184a2c_02184a2c(char*);
extern "C" int func_ov008_02184754(void* obj);
void ClearFlag0x10IfSet(Struct02074bd0* obj);
void ClearFlag0x11IfSet(Struct02074bf4* obj);
extern "C" void* func_ov008_021845ac(void* obj);
void ProcessCombatantsIfFlagged_0218f79c(void* res);
extern "C" void func_ov017_0219b624(GameResources* res);
int GetGlobalField0x1c020421a0(void);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
void InitAllocatorAndClearFields_021c0820(Obj021c0820*);
struct Obj021c0334;
void InitState40_021c0334(Obj021c0334*);
struct Obj021b14a0;
void InitState37_021b14a0(Obj021b14a0*);
void SetByteField49_021b1d3c(void* obj, int v);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov017_021c0580(void* self, int kind, const char* name, void* handler);
extern "C" int func_0209cd50(int id);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
void SetByteField0x253_020397c0(void* obj);
extern "C" void func_ov017_021c07d0(void* self);
int AllocateAndDispatch20_0215502c(SafeAllocator* alloc, int arg);
int AllocateAndDispatch14_021560b0(SafeAllocator* alloc, int arg);
int AllocateAndDispatch8_02156dc8(SafeAllocator* alloc, int arg);
int AllocateAndCopyHandlerTable_021677b4(SafeAllocator* alloc, void* arg);
int AllocateAndCopyBuf76_0216aa70(SafeAllocator* alloc, void* arg);

extern AllocatorUnion data_02114e20;
extern int data_02109bf4;
extern char data_ov017_021d7f00[];
extern char data_ov017_021d7f07[];
extern char data_ov017_021d7f12[];
extern char data_ov017_021d7f19[];
extern char data_ov017_021d7f22[];

#define POWCNT1 (*(volatile unsigned short*)0x04000304)

static inline void inline_ov017_021c0850(int arg0) {
    POWCNT1 = (unsigned short)((POWCNT1 & ~0x8000) | (arg0 << 15));
}

static inline void inline_ov017_021c0850_2(int arg0) {
    BG3CNT = (unsigned short)((BG3CNT & ~3) | arg0);
}

static inline void inline_ov017_021c0850_3(int arg0) {
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (arg0 << 8);
}

static inline Struct_ov003_0217e6b0 inline_ov003_0217e6b0(void) {
    return *(volatile Struct_ov003_0217e6b0*)&DISPCNT;
}

// USA: func_ov017_021c0850
extern "C" ARM void func_ov017_021c0850(Struct_ov017_021c0850_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    GameObject* var2 = var0->GetUnknownGameObject();
    func_020397cc((Struct_02018300_3*)var2, 1);

    if (arg0->unknown_20_ == 0) {
        func_020a0cc4(Enum_ov017_021c0850_123784);
        void* var3 = func_02012d88(&data_02114e20, Enum_ov017_021c0850_123784);
        if (var3 == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var3, Enum_ov017_021c0850_123784);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = (Struct_ov017_021c0850*)arg0->unknown_8_.Allocate(Enum_ov017_021c0850_2888);
        if (arg0->unknown_1c_ == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_020a1940(OVERLAY_ID(8));
        func_020a1ef0(1);
        func_ov008_021843f8(arg0->unknown_1c_);
        func_ov008_021842a0(arg0->unknown_1c_, &arg0->unknown_8_);
        arg0->unknown_1c_->unknown_b28_ = arg0->unknown_24_;
        arg0->unknown_1c_->unknown_b29_ = arg0->unknown_25_;
        arg0->unknown_1c_->unknown_b14_ = arg0->unknown_28_;
        arg0->unknown_1c_->unknown_b16_ = arg0->unknown_2a_;
        Struct_ov017_021c0850* var4 = arg0->unknown_1c_;
        if (arg0->unknown_26_) {
            var4->unknown_b18_ |= 0x40000;
        } else {
            var4->unknown_b18_ &= ~0x40000;
        }
        if (arg0->unknown_bc_) {
            arg0->unknown_1c_->unknown_b18_ |= 1;
            if (func_0209cae8((Struct_0209cae8*)&data_02109bf4) != 0x29) {
                func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0xf);
            }
        }
        unsigned short* id = (unsigned short*)func_02012fe4();
        func_0203e0a0(GetGlobalPtr021075f4_0203cf4c(), *id);
        if (GetBrightness((GameResources*)res, false) != Brightness_Black
            || GetBrightness((GameResources*)res, true) != Brightness_Black) {
            SetBrightness(res, -0x10, 0xf);
        }
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 1) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        if (!arg0->unknown_bc_) {
            arg0->unknown_20_++;
            return;
        }
        arg0->unknown_3c_ = 0;
        arg0->unknown_3d_ = 0;
        func_02074af4(arg0->unknown_2c_);
        arg0->unknown_40_ = (DISPCNT & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)arg0->unknown_2c_);
        arg0->unknown_44_ = (DISPCNTSUB & 0x1f00) >> 8;
        arg0->unknown_48_ = GetMainBGVRAMBanks();
        arg0->unknown_4c_ = GetSubBGVRAMBanks();
        arg0->unknown_58_ = GetTextureImageVRAMBanks();
        arg0->unknown_5c_ = GetTexturePaletteVRAMBanks();
        arg0->unknown_a0_ = GetTextureImageAssignedVRAMSize();
        arg0->unknown_a4_ = GetTexturePaletteAssignedVRAMSize();
        func_020bb700(arg0->unknown_70_);
        func_020bb910(arg0->unknown_98_);
        Struct_ov003_0217e6b0 var6 = inline_ov003_0217e6b0();
        arg0->unknown_60_ = var6.unknown_3_3_;
        arg0->unknown_64_ = var6.unknown_3_0_;
        arg0->unknown_68_ = DISPCNT & 0x300010;
        arg0->unknown_a8_ = func_0201e830((Struct_0201e830*)((char*)func_02012fe4() + Enum_ov017_021c0850_108));
        arg0->unknown_ac_ = GetFlags00(var1);
        arg0->unknown_b0_ = GetFlags04(var1);
        arg0->unknown_b4_ = GetFlags08(var1);
        arg0->unknown_b8_ = func_020100bc(var0);
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 2) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        inline_ov017_021c0850(0);
        MapVRAMBanksToTextureImage(1);
        func_020bb48c(1, 1);
        MapVRAMBanksToSubBG(4);
        MapVRAMBanksToSubObj(0x100);
        DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1300;
        func_020c391c(1, 0, 1);
        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG0CNT = (BG0CNT & ~3) | 1;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 3;
        inline_ov017_021c0850_2(0);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 2, 0xf, 0x1f);
        inline_ov017_021c0850_3(0x13);
        func_020c3984(0);
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xe00;
        BG1CNTSUB = (BG1CNTSUB & 0x43) | 0xf08;
        BG0CNTSUB = (BG0CNTSUB & ~3) | 1;
        BG1CNTSUB = BG1CNTSUB & ~3;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        SetFlags00(var1, 4);
        SetFlags04(var1, 0x8de);
        func_020c5588(0, 0, 0x7fff, 0, 0);
        func_020c54a4(0, 0, 0, 0);
        char* var7 = (char*)func_0203bd08();
        func_0203bd24(var7);
        *(int*)var7 = 0;
        int* var8 = func_0203bd14();
        *var8 = func_0203be4c(var7) + 0x200;
        func_0203c35c(var8);
        var8[Enum_ov017_021c0850_1288 / 4] = 0x7000;
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 3) {
        if (func_ov017_021959b4()) {
            func_ov008_02184a2c((char*)arg0->unknown_1c_);
        }
        if (func_ov008_02184754(arg0->unknown_1c_)) {
            arg0->unknown_20_++;
        }
    } else if (arg0->unknown_20_ == 4) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(arg0->unknown_4c_);
        MapVRAMBanksToTextureImage(arg0->unknown_58_);
        func_020bb48c((unsigned short)(arg0->unknown_a0_ >> 17), 1);
        func_020bb740(arg0->unknown_70_);
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | (arg0->unknown_40_ << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (arg0->unknown_44_ << 8);
        func_02074bd0((Struct_02074bd0*)arg0->unknown_2c_);
        func_02074bf4((Struct_02074bf4*)arg0->unknown_2c_);
        func_020c5588(arg0->unknown_a8_, 0x10, 0x7fff, 0, 0);
        func_ov008_021845ac(arg0->unknown_1c_);
        char var9[0x20];
        memset(var9, 0, 0x20);
        CleanInvalidateCacheRange(var9, 0x20);
        LoadToMainBG1CharacterData(var9, 0, 0x20);
        ClearFlags00(var1, -1);
        ClearFlags04(var1, -1);
        ClearFlags08(var1, -1);
        SetFlags00(var1, arg0->unknown_ac_);
        SetFlags04(var1, arg0->unknown_b0_);
        SetFlags08(var1, arg0->unknown_b4_);
        func_ov017_0218f79c(var1);
        func_020100c4(var0, (int)arg0->unknown_b8_);
        GameState* var10 = GameState::GetInstance();
        int var11 = 0x70;
        for (int var12 = 0; var12 < 0x30; var12++) {
            GameObject* var13 = var10->GetMaybeFieldMonsterByIndex(var11);
            if (var13) {
                var13->obj3D_.StageTextureData();
            }
            var11++;
        }
        func_ov017_0219b624(res);
        char* fields = res->unknown_2cc;
        void* controller = (void*)GetGlobalField0x1c020421a0();
        CopyInternalFields0207df50((Foo0207df50*)(fields + 0x5b0));
        VramState_Restore(fields + 0x5b0);
        func_020432c4(controller);
        VramState_Save(fields + 0x5b0);
        if (self->scene->kind == 0) {
            func_ov017_0219bd1c(1, 0, 0, 0);
        }
        arg0->unknown_20_++;
    } else if (arg0->unknown_20_ == 5) {
        arg0->unknown_3c_ = 0;
        arg0->unknown_3d_ = 0;
        func_02074af4(arg0->unknown_2c_);
        func_02074b64((Struct_02074b64*)arg0->unknown_2c_);
        arg0->unknown_25_ = arg0->unknown_1c_->unknown_b29_;
        arg0->unknown_26_ = (arg0->unknown_1c_->unknown_b18_ & 0x40000) != 0;
        arg0->unknown_28_ = arg0->unknown_1c_->unknown_b14_;
        arg0->unknown_2a_ = arg0->unknown_1c_->unknown_b16_;
        GameResources* var16 = GetGameResources();
        Struct_020469f8* var17 = (Struct_020469f8*)var16->unknown_ptr_array_36fc[0];
        Struct_020469f8_2* var18;
        switch (arg0->unknown_1c_->unknown_b13_) {
        case 1:
            func_ov017_021c0820((Struct_ov017_021c0580*)arg0);
            arg0->unknown_24_ = 0;
            var18 = (Struct_020469f8_2*)var16->unknown_ptr_array_3afc[15];
            func_ov017_021c0334((Struct_ov017_021c0334*)var18);
            func_020469f8(var17, var18);
            return;
        case 2:
            func_ov017_021c0580(arg0, 1, data_ov017_021d7f00, (void*)func_ov004_0215502c);
            return;
        case 3:
            func_ov017_021c0580(arg0, 2, data_ov017_021d7f07, (void*)func_ov004_021560b0);
            return;
        case 4:
            func_ov017_021c0820((Struct_ov017_021c0580*)arg0);
            arg0->unknown_24_ = 3;
            var18 = (Struct_020469f8_2*)var16->unknown_ptr_array_3afc[18];
            func_ov017_021b14a0((Struct_ov017_021b146c*)var18);
            func_ov017_021b1d3c(var18, 1);
            func_020469f8(var17, var18);
            return;
        case 5:
            func_ov017_021c0580(arg0, 4, data_ov017_021d7f12, (void*)func_ov004_02156dc8);
            return;
        case 6:
            func_ov017_021c0580(arg0, 5, data_ov017_021d7f19, (void*)func_ov004_021677b4);
            return;
        case 7:
            func_ov017_021c0580(arg0, 6, data_ov017_021d7f22, (void*)func_ov004_0216aa70);
            return;
        case 0: {
            SetMainBrightness(var1, 0, 0xf);
            func_0209c3b4((Struct_0209c3b4_2*)&data_02109bf4, func_0209cd50(*(unsigned short*)func_02012fe4()));
            char* var19 = (char*)func_020421a0();
            *(int*)(var19 + Enum_ov017_021c0850_728) = 0;
            *(unsigned char*)(var19 + Enum_ov017_021c0850_742) = 1;
            break;
        }
        }
        arg0->unknown_20_++;
    } else {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        if (arg0->unknown_1c_->unknown_b13_ == 0) {
            func_020397c0(var2);
        } else {
            func_020397cc((Struct_02018300_3*)var2, 1);
        }
        func_ov017_021c07d0(arg0);
        func_020a0c0c();
        arg0->unknown_1_ = 1;
    }
}
