#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#define func_ov016_0218d2f4 func_ov016_0218d9f8
#define data_ov016_0219cfc0 data_ov016_0219cee0
#define data_ov016_0219cfc6 data_ov016_0219cee9
#define data_ov016_0219d022 data_ov016_0219ceef
#endif

struct Struct_02013fb4;
struct Struct_020e57e0 { int unknown_0_[3]; };
struct Struct_02000c9c_12;
struct Struct_02109bf4_4;
struct Struct_02000c9c_16;
struct Struct_02000c9c_17;

struct Struct_ov016_0218b5c4_7 { char unknown_0_[0x40]; };

struct Struct_ov016_0218b5c4_8 {
    char unknown_0_[0x4c];
    int unknown_4c_;
    char unknown_50_[0x5c - 0x50];
    short unknown_5c_;
    short unknown_5e_;
    short unknown_60_;
    char unknown_62_[0x6d - 0x62];
    unsigned char unknown_6d_;
    char unknown_6e_[0x70 - 0x6e];
    unsigned char unknown_70_;
    char unknown_71_;
    unsigned char unknown_72_;
};

struct Struct_ov016_0218b5c4 {
    SafeAllocator unknown_0_;
    Struct_ov016_0218b5c4_8 unknown_14_;
    char unknown_88_[0x94 - 0x88];
    int unknown_94_;
};

struct Struct_ov016_0218b5c4_2 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    int unknown_4_;
    const char* unknown_8_;
    const char* unknown_c_;
    char unknown_10_;
    unsigned char unknown_11_;
};

struct Struct_ov016_0218b5c4_3 {
    Struct_ov016_0218b5c4_2* unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern "C" int func_020c39a0(short* arg0, int arg1);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_02028d68(int arg0);
extern "C" void func_02028ddc(void* arg0);
extern "C" void func_02028dec(int);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020c5770(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, void* arg8);
extern "C" int func_ov016_0218bc70(int arg0);
extern "C" void func_ov016_0218e00c(Struct_ov016_0218b5c4_3* arg0);
struct Struct_ov016_0218b5c4_4;
extern "C" void func_ov016_0218e098(Struct_ov016_0218b5c4_4*, int);
extern "C" void func_02029568(Struct_ov016_0218b5c4_8* arg0);
extern "C" void func_020294cc(void* arg0, const char* arg1);
extern "C" int func_ov016_0218e174(int*);
extern "C" void func_0202949c(char*);
struct Struct_ov016_0218b5c4_5;
extern "C" Struct_ov016_0218b5c4_2* func_ov016_0218e14c(Struct_ov016_0218b5c4_5**, int);
struct Struct_0202a944_2;
struct Struct_0202a944;
extern "C" void func_0202a944(Struct_0202a944_2*, Struct_0202a944*);
extern "C" void func_0202a6c4(Struct_ov016_0218b5c4_8* arg0);
extern "C" void func_0202a8cc(char*, int);
extern "C" void func_020c9820();
extern "C" void func_020c38d4();
extern "C" int func_020115a8(Struct_02000c9c_12* arg0);
extern "C" void func_02012efc();
extern "C" void func_020c52e8();
extern "C" void func_020c5414();
extern "C" void func_02029060();
extern "C" void func_02029988(void* arg0, int arg1);
extern "C" void func_02029088();
extern "C" void func_020d86d0(int arg0, int arg1);
extern "C" void func_020bbcb4();
extern "C" void func_020290ac(int arg0);
extern "C" void func_020e57e0(Struct_020e57e0* arg0);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
extern "C" void func_020e57f4(int, int, Struct_02013fb4*, int);
extern "C" int func_0201201c(void* arg0);
struct Struct_ov016_0218b5c4_6;
extern "C" Struct_ov016_0218b5c4_2* func_ov016_0218e124(Struct_ov016_0218b5c4_6**, int);
extern "C" void func_0209c678(Struct_02109bf4_4* arg0, int arg1);
extern "C" void func_0203ad88(void* arg0, void* arg1, int arg2);
extern "C" void func_020bbd9c();
extern "C" void func_0205e8d4(void* arg0);
extern "C" void func_0203a950(void* arg0);
extern "C" void func_0205e88c(Struct_02000c9c_17* arg0);
extern "C" void func_0209c174(Struct_02000c9c_16* arg0);
extern "C" void func_0209c2b8(void* arg0);
extern "C" void func_0205ea20(void* arg0, int arg1);
extern "C" void func_0209c290(void* arg0);
extern "C" void func_02012da4(AllocatorUnion* arg0, void* arg1);
extern "C" void func_020a0c0c();
#if defined(jpn)
extern "C" void func_ov016_0218d2f4(char* arg0, char* arg1, Struct_ov016_0218b5c4* arg2, Struct_ov016_0218b5c4_2* arg3, int arg4);
extern "C" void func_ov016_0218caa8(char* arg0, Struct_ov016_0218b5c4* arg1, Struct_ov016_0218b5c4_2* arg2, int arg3);
#define SCRIPT_ARG_0218b5c4
#else
extern "C" void func_ov016_0218d2f4(char* arg0, char* arg1, Struct_ov016_0218b5c4* arg2, Struct_ov016_0218b5c4_2* arg3, int arg4, Struct_020e57e0* arg5);
extern "C" void func_ov016_0218caa8(char* arg0, Struct_ov016_0218b5c4* arg1, Struct_ov016_0218b5c4_2* arg2, int arg3, Struct_020e57e0* arg4);
#define SCRIPT_ARG_0218b5c4 , &var4
#endif

extern AllocatorUnion data_02114e20;
extern char data_02109bf4;
extern char g_sePlayer;
extern const char data_ov016_0219cfc0[];
extern const char data_ov016_0219cfc6[];
extern const char data_ov016_0219cfcc[];
extern const char data_ov016_0219cfe6[];
extern const char data_ov016_0219cff7[];
extern const char data_ov016_0219d011[];
extern const char data_ov016_0219d022[];

static inline void inline_ov016_0218b5c4(int arg0) { DISPCNT = (DISPCNT & ~0x7000000) | (arg0 << 24); }
static inline void inline_ov016_0218b5c4_2(int arg0) { DISPCNT = (DISPCNT & ~0x38000000) | (arg0 << 27); }
// USA: func_ov016_0218b5c4
extern "C" ARM void func_ov016_0218b5c4(Struct_ov016_0218b5c4* arg0) {
    char var0[0x50];
    char var1[0x50];
    Struct_ov016_0218b5c4_3 var2;
    char var3[0x30];
#if !defined(jpn)
    Struct_020e57e0 var4;
#endif
    char var5[0x28];
    char var6[0x28];
#if !defined(jpn)
    unsigned int var7;
#endif

    GameState* var8 = GameState::GetInstance();
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(1);
    inline_ov016_0218b5c4(0);
    inline_ov016_0218b5c4_2(0);
    func_020c391c(1, 0, 1);
    volatile unsigned short* var9 = (volatile unsigned short*)0x4000008;
    var9[0] = (var9[0] & ~0x3) | 0x1;
    var9[1] = var9[1] & ~0x3;
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG0, BLEND_TARGET_BACKDROP, 0x1f, 0x1f);
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG1, BLEND_TARGET_BG0, 0x1f, 0);
    func_020a0cc4(0x100000);
    arg0->unknown_0_.CreateTypeB(func_02012d88(&data_02114e20, 0x100000), 0x100000, 4);
    void* var10 = arg0->unknown_0_.Allocate(0x6000);
    func_02028d68(3);
    func_02028ddc(var10);
    func_02028dec(0);
    func_020c5588(0, 0x10, 0x7fff, 0x3f, 0);
    func_020c5770(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);
    *(volatile unsigned int*)0x400044c = 0;
    func_ov016_0218bc70(0);

    func_ov016_0218e00c(&var2);
    func_ov016_0218e098((Struct_ov016_0218b5c4_4*)&var2, (int)arg0);
    func_02029568(&arg0->unknown_14_);
    func_020294cc(&arg0->unknown_14_, data_ov016_0219cfc0);
    Struct_ov016_0218b5c4_7* var11 = (Struct_ov016_0218b5c4_7*)arg0->unknown_0_.Allocate(func_ov016_0218e174((int*)&var2) * sizeof(Struct_ov016_0218b5c4_7));
    if (var11 != 0) {
        for (unsigned int var12 = 0; var12 < func_ov016_0218e174((int*)&var2); var12++) {
            func_0202949c((char*)&var11[var12]);
            Struct_ov016_0218b5c4_2* var13 = func_ov016_0218e14c((Struct_ov016_0218b5c4_5**)&var2, var12);
            if (var13 != 0) {
                sprintf(var3, data_ov016_0219cfc6, var13->unknown_0_, var13->unknown_4_);
                func_020294cc(&var11[var12], var3);
                func_0202a944((Struct_0202a944_2*)&arg0->unknown_14_, (Struct_0202a944*)&var11[var12]);
            }
        }
    }
    func_0202a6c4(&arg0->unknown_14_);
    int var14 = func_ov016_0218e174((int*)&var2);
    arg0->unknown_14_.unknown_5c_ = 0;
    arg0->unknown_14_.unknown_60_ = 0;
    arg0->unknown_14_.unknown_5e_ = var14 - 1;
    arg0->unknown_14_.unknown_6d_ |= 6;
    arg0->unknown_14_.unknown_72_ = 1;
    arg0->unknown_14_.unknown_70_ = 1;
    arg0->unknown_14_.unknown_4c_ = 8;
    func_0202a8cc((char*)&arg0->unknown_14_, 1);
    func_020c9820();
    func_020c38d4();
    DISPCNTSUB |= 0x10000;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);

    int var15 = -1;
    if (func_020115a8((Struct_02000c9c_12*)var8) != 0) {
        var15 = func_020115a8((Struct_02000c9c_12*)var8);
        arg0->unknown_94_ = 0;
    }
    func_02012efc();
    while (var15 < 0) {
        func_02012efc();
        func_020c52e8();
        func_020c5414();
        DISP3DCNT &= (unsigned short)~0x3020;
        if (g_keyManager.TestKeysPressed(1)) {
            Struct_ov016_0218b5c4_2* var16 = func_ov016_0218e14c((Struct_ov016_0218b5c4_5**)&var2, arg0->unknown_14_.unknown_60_);
            if (var16 != 0) {
                var15 = var16->unknown_0_;
            }
        } else if (g_keyManager.TestKeysPressed(2)) {
            arg0->unknown_94_ = 0;
            break;
        }
        func_02029060();
        func_02029988(&arg0->unknown_14_, 1);
        func_02029088();
        func_020d86d0(0, 1);
        func_020c9820();
        func_020bbcb4();
        func_020290ac(0);
        func_020c39a0((short*)0x400006c, 0);
        func_020c39a0((short*)0x400106c, -16);
    }

#if !defined(jpn)
    func_020e57e0(&var4);
    BackgroundLoader::GetInstance();
    if (var15 > 0) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* var17 = 0;
        switch (var15) {
        case 4:
            var17 = ExtractFileFromGP2(data_ov016_0219cfcc, data_ov016_0219cfe6, &var7);
            break;
        case 8:
            var17 = ExtractFileFromGP2(data_ov016_0219cff7, data_ov016_0219d011, &var7);
            break;
        }
        if (var17 != 0) {
            func_020e57f4((int)&var4, (int)arg0, (Struct_02013fb4*)var17, var7);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
#endif
    func_02029060();
    func_02029088();
    func_020d86d0(0, 1);

    int var18 = 2;
    if (func_0201201c(var8) == 5) {
        var18 = 1;
    } else if (func_020115a8((Struct_02000c9c_12*)var8) != 0) {
        var18 = 0;
    }

    if (var15 >= 0) {
        func_020c39a0((short*)0x400006c, -16);
        func_020c39a0((short*)0x400106c, -16);
        Struct_ov016_0218b5c4_2* var19 = func_ov016_0218e124((Struct_ov016_0218b5c4_6**)&var2, var15);
        if (var19 != 0) {
#if !defined(jpn)
            if (var19->unknown_11_ != 0) {
                func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0);
                func_0203ad88(&data_02109bf4, 0, 0);
                func_020bbd9c();
                ResetObjectState0205e8d4(&g_sePlayer);
                FreeAndReinit0203a950(&data_02109bf4);
                InitDisplayState0205e88c((Obj_0205e88c*)&g_sePlayer);
                ResetActor0209c174((Actor0209c174*)&data_02109bf4);
                Dispatch0203a974With0xA2000_0209c2b8(&data_02109bf4);
            }
#endif
            if (var19->unknown_8_ != 0 && var19->unknown_c_ != 0) {
                func_ov016_0218bc70(1);
                sprintf(var0, data_ov016_0219d022, var19->unknown_8_);
                sprintf(var1, data_ov016_0219d022, var19->unknown_c_);
                func_ov016_0218d2f4(var0, var1, arg0, var19, var18 SCRIPT_ARG_0218b5c4);
            } else if (var19->unknown_8_ != 0 && var19->unknown_c_ == 0) {
                func_ov016_0218bc70(1);
                sprintf(var5, data_ov016_0219d022, var19->unknown_8_);
                func_ov016_0218caa8(var5, arg0, var19, var18 SCRIPT_ARG_0218b5c4);
            } else if (var19->unknown_8_ == 0 && var19->unknown_c_ != 0) {
                func_ov016_0218bc70(0);
                sprintf(var6, data_ov016_0219d022, var19->unknown_c_);
                func_ov016_0218caa8(var6, arg0, var19, var18 SCRIPT_ARG_0218b5c4);
            }
#if !defined(jpn)
            if (node->fade != 0) {
                ResetObjectState0205e8d4(&g_sePlayer);
                FreeAndReinit0203a950(&data_02109bf4);
                InitDisplayState0205e88c((Obj_0205e88c*)&g_sePlayer);
                ResetActor0209c174((Actor0209c174*)&data_02109bf4);
                SetupContextForMode0205ea20(&g_sePlayer, 100);
                Dispatch0203a974With0x57000_0209c290(&data_02109bf4);
            }
#endif
        }
    }

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    SignedAllocatorHeader* var20 = arg0->unknown_0_.GetSignedAllocator();
    arg0->unknown_0_.Destroy();
    func_02012da4(&data_02114e20, var20);
    func_020a0c0c();
    func_02028ddc(0);
}
