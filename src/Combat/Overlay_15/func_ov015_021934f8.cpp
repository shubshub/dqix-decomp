#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/FontBankLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif

#if defined(jpn)
#define func_020c39c8 func_020c5494
#endif

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

struct Struct_ov015_0218b810;
struct Struct_ov015_02192600_3;
struct Struct_0204a120_2;
struct Struct_0203d028;
struct Struct_0200f3a4_9;
struct Struct_0203bdb0;

struct Struct_ov015_021934f8 {
    char unknown_0_[0x2c8];
};

struct Struct_ov015_021934f8_2 {
    char unknown_0_[0x195a];
    unsigned char unknown_195a_;
};

struct Struct_ov015_021934f8_3 {
    char unknown_0_[0x3c];
    int unknown_3c_[4];
    int unknown_4c_[6];
    char unknown_64_[0x70 - 0x64];
    char unknown_70_[0x84 - 0x70];
    void* unknown_84_;
    SafeAllocator unknown_88_;
    SafeAllocator unknown_9c_;
    SafeAllocator unknown_b0_;
    char unknown_c4_[0x124 - 0xc4];
    char unknown_124_[0x194 - 0x124];
    int unknown_194_;
    int unknown_198_;
    char unknown_19c_[0x1a4 - 0x19c];
    int unknown_1a4_;
    char unknown_1a8_[0x22c - 0x1a8];
    unsigned long long unknown_230_;
    unsigned long long unknown_238_;
    unsigned long long unknown_240_;
    unsigned long long unknown_248_;
    float unknown_250_;
    char unknown_254_[0x268 - 0x250];
    char unknown_26c_[0x52];
};

extern "C" void func_0200fb84(int*, int);
extern "C" void func_020c39a0(short*, int);
extern "C" void* func_0203bd08();
extern "C" void func_0203bd24(char*);
void LockStagedTextureVRAMCopying();
extern "C" void func_020ca458(unsigned int, unsigned int, unsigned int);
extern "C" void func_020c391c(int, int, int);
extern "C" void func_020c3984(unsigned int);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_02028ddc(void*);
extern "C" void func_02028d68(int);
extern "C" void func_02028dec(int);
extern "C" void func_020bb48c(unsigned int, int);
extern "C" void func_020bb780(void*, int);
extern "C" void func_ov015_02192600(struct Struct_ov015_02192600_3*);
extern "C" void func_020c5588(int, int, int, int, int);
extern "C" void func_ov015_0218b810(struct Struct_ov015_0218b810*);
extern "C" void func_ov015_0218ba44(void*, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_020de848(void*);
extern "C" void* ExtractFileFromGP2(const char*, const char*, unsigned int*);
extern "C" void func_020dea64(void*, SafeAllocator*, void*, unsigned int, const void*, int);
extern "C" void func_0206efc4(void*);
extern "C" void func_0206efd8(void*, void*);
extern "C" void func_020709d8(void*);
extern "C" void func_020709ec(void*, void*);
extern "C" void func_0202df68(void*);
extern "C" void func_020a2cf0(struct Struct_0204a120_2*);
extern "C" void func_020a2010(void*);
extern "C" void func_020a27a0(void*);
extern "C" void func_020100c4(GameState*, int);
extern "C" void func_ov015_02192544(void*);
extern "C" void func_0205ea20(void*, int);
extern "C" void func_020c9820();
extern "C" void func_020c38d4();
extern "C" void func_02010124(Struct_0200f3a4_9*);
extern "C" void func_020c3a0c(int);
unsigned long long GetCurrentTimestamp();
extern "C" void* func_020421a0();
extern "C" void func_02042b30(void*, void*);
extern "C" void func_0207df50(struct Struct_0203d028*);
extern "C" void func_0207df90(char*);
extern "C" void func_020432c4(void*);
extern "C" void func_0207dfac(char*);
extern "C" void func_0204500c(void*, const void*, int, int);
extern "C" void func_0204359c(void*, int);
extern "C" void func_020439b0(void*, int);
extern "C" void func_ov015_02192700(void*);
extern "C" void func_02012de4(AllocatorUnion*);
extern "C" void func_02012efc();
extern "C" void func_020bc028(int);
extern "C" void func_ov015_02190e88(void*);
extern "C" void func_ov015_02191294(void*);
extern "C" void func_ov015_02191668(void*);
extern "C" void func_ov015_02190d7c(void*);
extern "C" void func_ov015_021901c8(void*);
extern "C" void func_0203bd88(void* arg0);
extern "C" void func_0203aa08(void*);
extern "C" void func_020bbd9c();
extern "C" unsigned long long _ll_udiv(unsigned long long, unsigned long long);
extern "C" float func_0200c76c(unsigned long long);
extern "C" int func_020c39c8(unsigned short volatile*);
extern "C" void func_0203bdb0(Struct_0203bdb0*);
extern "C" void func_020290ac(int);

extern AllocatorUnion data_02114e20;
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern int data_ov015_02193cdc[];
extern char g_sePlayer;
extern int data_ov015_02194528[];

#define POWCNT1 (*(volatile unsigned short*)0x04000304)
#define MASTER_BRIGHT ((short*)0x0400006c)
#define MASTER_BRIGHT_SUB ((short*)0x0400106c)
#define BG0HOFS_SUB (*(volatile int*)0x04001010)

// USA: func_ov015_021934f8
extern "C" ARM void func_ov015_021934f8(Struct_ov015_021934f8_3* arg0)
{
    GameState* var0 = GameState::GetInstance();
    if (var0 == NULL)
        return;
    func_0200fb84((int*)var0, (int)arg0);
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    var1->MaybeReset();
    Struct_0208cb08* var2 = func_02094a00();
    func_02094b3c(var2, 10);
    func_02094b3c(var2, 12);
    func_02094b34(var2, 0x69, 0, 0, 0);
    func_02094b38(var2, 0x69);
    func_02094b38(var2, 0);
    while (!func_02094b4c(var2))
        var1->RemoveAllLocks();

    func_020c39a0(MASTER_BRIGHT, -16);
    func_020c39a0(MASTER_BRIGHT_SUB, -16);
    char* var3 = (char*)func_0203bd08();
    func_0203bd24(var3);
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToLCDC(0x1ff);
    func_020ca458(0, 0x6800000, 0xa4000);
    DisableLCDCMappedVRAMBanks();
    ReleaseTextureImageVRAMBanks();
    MapVRAMBanksToTextureImage(0xb);
    ReleaseTexturePaletteVRAMBanks();
    MapVRAMBanksToTexturePalette(0x60);
    DISPCNT = DISPCNT & ~DISPCNT_MASK_CHARACTER_BASE_64K;
    DISPCNT = DISPCNT & ~DISPCNT_MASK_SCREEN_BASE_64K;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    func_020c391c(1, 0, 1);
    func_020c3984(0);
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1100;
    ReleaseSubBGVRAMBanks();
    MapVRAMBanksToSubBG(4);
    ReleaseSubObjVRAMBanks();
    MapVRAMBanksToSubObj(0x100);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    func_020c39a0(MASTER_BRIGHT, 0);
    func_020c39a0(MASTER_BRIGHT_SUB, 0);
    POWCNT1 &= ~0x8000;
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    BG1CNT = BG1CNT & ~3;
    BG0CNT = (BG0CNT & ~3) | 1;
    BG0CNTSUB = BG0CNTSUB & ~3;
    BG0HOFS_SUB = 0;
    arg0->unknown_84_ = func_02012d88(&data_02114e20, 0x6000);
    func_02028ddc(arg0->unknown_84_);
    func_02028d68(4);
    func_02028dec(1);
    func_020bb48c(3, 1);
    func_020bb780((void*)0x8000, 1);
    func_ov015_02192600((struct Struct_ov015_02192600_3*)arg0);
    func_020c5588(0x594a, 0x10, 0x7fff, 0, 0);
    func_ov015_0218b810((struct Struct_ov015_0218b810*)&arg0->unknown_3c_);
    func_ov015_0218ba44(&arg0->unknown_3c_, 0);
    memset(arg0->unknown_26c_, 0, 0x52);

    arg0->unknown_88_.ResetAllocatorPointer();
    arg0->unknown_88_.CreateTypeA(func_02012d88(&data_02114e20, 0x17600), 0x17600);
    arg0->unknown_88_.Reset();
    func_020de848(arg0->unknown_4c_);
    BackgroundLoader::AddLockGlobal();
    unsigned int var4;
    void* var5;
    var4 = 0;
    var5 = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &var4);
    if (var5 != NULL)
        func_020dea64(arg0->unknown_4c_, &arg0->unknown_88_, var5, var4, data_ov015_02193cdc, 9);
    BackgroundLoader::RemoveLockGlobal();

    arg0->unknown_9c_.ResetAllocatorPointer();
    arg0->unknown_9c_.CreateTypeA(func_02012d88(&data_02114e20, 0x20000), 0x20000);
    arg0->unknown_9c_.Reset();
    func_0206efc4(arg0->unknown_64_);
    func_0206efd8(arg0->unknown_64_, &arg0->unknown_9c_);

    arg0->unknown_b0_.ResetAllocatorPointer();
    arg0->unknown_b0_.CreateTypeA(func_02012d88(&data_02114e20, 0x20000), 0x20000);
    arg0->unknown_b0_.Reset();
    func_020709d8(arg0->unknown_70_);
    func_020709ec(arg0->unknown_70_, &arg0->unknown_b0_);

    CombatController021934f8 combat;
    func_0202df68(&combat);
    ResetState020a2cf0((struct Struct020A2CF0*)&combat);
    InitCombatController020a2010(&combat);
    SetField0x238False_020a27a0(&combat);
    SetField0x3b0Value_020100c4(gs, (int)&combat);
    func_ov015_02192544(self);
    SetupContextForMode0205ea20(&g_sePlayer, 0x65);
    DelayThenSyncBit0_020c9820();
    RestoreDisplayMode_020c38d4();
    DISPCNTSUB = DISPCNTSUB | 0x10000;
    func_02010124((Struct_0200f3a4_9*)var0);
    func_020c3a0c(0);
    GetCurrentTimestamp();
    Struct_ov015_021934f8_2* var7 = (Struct_ov015_021934f8_2*)func_020421a0();
    func_02042b30(var7, arg0->unknown_124_);
    func_0207df50((struct Struct_0203d028*)arg0->unknown_124_);
    func_0207df90(arg0->unknown_124_);
    func_020432c4(var7);
    func_0207dfac(arg0->unknown_124_);
    func_0204500c(var7, data_ov015_02194528, 0, 0xe3);
    var7->unknown_195a_ = 8;
    for (unsigned int var8 = 0; var8 < 0x10; var8++)
    {
        func_0204359c(var7, 0x10);
        func_020439b0(var7, 0);
    }
    arg0->unknown_194_ = 0;
    arg0->unknown_198_ = 2;
    arg0->unknown_1a4_ = 0;
    func_ov015_02192700(arg0);
    func_02012de4(&data_02114e20);
    unsigned long long var9 = GetCurrentTimestamp();

    for (;;)
    {
        func_02012efc();
        int var10;
        if (g_keyManager.TestKeysHeld(4) && g_keyManager.TestKeysHeld(8))
            var10 = 1;
        else if (arg0->unknown_1a4_ == 0 && g_keyManager.TestKeysPressed(2))
            var10 = 1;
        else
            var10 = 0;
        if (var10)
        {
            func_020bc028(0);
            break;
        }
        if (g_keyManager.TestKeysPressed(8))
            func_ov015_02192544(arg0);
        switch (arg0->unknown_194_)
        {
        case 0:
            func_ov015_02190e88(arg0);
            break;
        case 1:
            func_ov015_02191294(arg0);
            break;
        case 2:
            func_ov015_02191668(arg0);
            break;
        }
        func_ov015_02190d7c(self);
        func_ov015_021901c8(self);
        CleanInvalidateOamBuffers0203bd88(context);
        ResetXYField0203aa08(&g_sePlayer);
        func_020bbd9c();

        unsigned long long var11 = arg0->unknown_240_;
        arg0->unknown_240_ = _ll_udiv(GetCurrentTimestamp() * 64000, 33514);
        if (arg0->unknown_238_ < arg0->unknown_240_)
        {
            unsigned long long var12 = arg0->unknown_240_ - arg0->unknown_238_;
            arg0->unknown_248_ = (var12 + arg0->unknown_248_) >> 1;
        }
        if (var11 < arg0->unknown_240_)
        {
            arg0->unknown_230_ += _ll_udiv(arg0->unknown_240_ - var11, 1000);
            if (arg0->unknown_230_ > 1000)
            {
                arg0->unknown_230_ = 0;
                arg0->unknown_250_ = 1000000.0f / func_0200c76c(arg0->unknown_248_);
            }
        }
        var1->RemoveAllLocks();
        arg0->unknown_238_ = _ll_udiv(GetCurrentTimestamp() * 64000, 33514);
        if (func_020c39c8((unsigned short volatile*)MASTER_BRIGHT) > -16)
            func_020c9820();
        GetCurrentTimestamp();
        func_0203bdb0((Struct_0203bdb0*)var3);
        func_020290ac(1);
        var0->CalculateDeltaTime(_ll_udiv((GetCurrentTimestamp() - var9) * 64000, 33514));
        var9 = GetCurrentTimestamp();
    }

    BlankFunction02094b38(global, 0x69);
    func_02094ab0(global);
    SetupContextForMode0205ea20(&g_sePlayer, 0x64);
    InitCombatController020a2010(&combat);
    ResetState020a2cf0((struct Struct020A2CF0*)&combat);
    func_0202df68(&combat);
}
