#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/ColorEffects.h"
#include "Util/Random.h"
#include "std_library_functions.h"
#include "Input/Input.h"

struct Struct_ov009_0218742c_7 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
    void inline_ov009_0218742c_3(int arg0) { unknown_0_0_ = arg0; }
};
struct Struct_01ff8b48_28 { char unknown_0_[32]; };
struct Struct_ov009_0218742c_9 {
    Struct_ov009_0218742c_7 unknown_0_[4];
    char unknown_10_[0x5c];
    unsigned short unknown_6c_;
    unsigned short unknown_6e_;
    unsigned short unknown_70_;
    unsigned short unknown_72_;
    char unknown_74_[0xc4];
    int unknown_138_[13];
    unsigned short unknown_16c_[20];
    Struct_01ff8b48_28 unknown_194_[7];
    char unknown_274_[0x214];
    short unknown_488_[0x71];
    unsigned char unknown_56a_;
#if defined(jpn)
    char unknown_56b_[0x34d];
#else
    char unknown1_56b_[0x3e5];
#endif
    int unknown_950_;
};
struct Struct_ov009_0218742c { char unknown_0_[0x14c]; Struct_ov009_0218742c_7 unknown_14c_[5]; char unknown_160_[0xdc]; };
struct Struct_ov009_0218742c_2 { char unknown_0_[0x3c]; char unknown_3c_[0x18]; };
struct Struct_ov009_0218742c_3 { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_ov009_0218742c_4 { char unknown_0_[0x10c]; Struct_ov009_0218742c_3 unknown_10c_[13][20]; char unknown_51c_[0x34]; };
struct Struct_ov009_0218742c_5 {
    void* unknown_0_;
    char unknown_4_[0x1a];
    unsigned char unknown_1e_;
    char unknown_1f_;
    unsigned char unknown_20_;
    void inline_ov009_0218742c(unsigned char arg0) { unknown_1e_ = arg0; }
    void inline_ov009_0218742c_2(unsigned char arg0) { unknown_20_ = arg0; }
};
struct Struct_ov009_0218742c_6 {
#if defined(jpn)
    char unknown_0_[0xa0]; Struct_ov009_0218742c_5* unknown_a0_;
    char unknown_a4_[4]; char unknown_a8_[0xd4];
    char unknown_1b8_[0xfc]; char unknown_2b4_[0x9a5];
    unsigned char unknown_c59_;
    char unknown_c1e_[0x12a];
#else
    char unknown1_0_[0xc0]; Struct_ov009_0218742c_5* unknown_c0_;
    char unknown_c4_[4]; char unknown_c8_[0xf0];
    char unknown_1b8_[0xfc]; char unknown_2b4_[0x9a5];
    unsigned char unknown_c59_;
    char unknown_c5a_[0x12a];
#endif
    signed char unknown_d84_;
    char unknown_d85_[3]; Struct_ov009_0218742c_9* unknown_d88_;
    char unknown_d8c_[9]; unsigned char unknown_d95_;
    char unknown_d96_[6]; unsigned int unknown_d9c_;
    char unknown_da0_[2]; unsigned char unknown_da2_; unsigned char unknown_da3_;
    char unknown_da4_[4]; unsigned char unknown_da8_[1];
};
#if defined(jpn)
struct GameFlag0218742c { char field_0[0x6174]; unsigned char changed; };
void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
struct Struct_ov009_0218742c_8 { char unknown_0_[0x63d4]; unsigned char unknown_63d4_; };
#endif
struct Struct_ov009_0218aac8 { unsigned char unknown_0_; unsigned char unknown_1_; unsigned char unknown_2_[5]; };
struct Struct_0205d81c; struct Struct_02108760; struct Struct_0205c570; struct Struct_0205da38;
struct Struct_0205d6a0; struct Struct_0204b010; struct Struct_0205d1e0; struct Struct_0205d228;
struct Struct_0205d274; struct Struct_0205d2bc; struct Struct_0201099c_10; struct Struct_0201099c_18;
extern "C" void* func_020d6c00();
extern "C" void func_ov023_021d9f88(Struct_ov009_0218742c_6*);
extern "C" void func_0205deb4(Struct_0205d81c*, int, int);
extern "C" void func_0205eaa0(Struct_02108760*, int, int);
extern "C" int func_0205d794(Struct_0205c570*);
extern "C" int func_0205da38(Struct_0205da38*, int);
extern "C" void func_0205d6a0(Struct_0205d6a0*, int);
extern "C" void func_0204b010(Struct_0204b010*, void*);
extern "C" void func_0204bc74(void*, int, int, int, int, int, int);
extern "C" void func_0204b04c(void*, int);
extern "C" void func_0204b088(void*, int);
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
void InitEntries0205d2bc(Obj0205d2bc*);
void CharacterCreationUI_SwitchTab(unsigned char*, int);
extern "C" void func_02086404(Snapshot0218742c*);
void SetBit0x954StoreIndex0x950_02083ca0(unsigned char*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_0208247c(void*);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_02082490(void*, void*, unsigned int, int, int);
extern "C" void func_02083cbc(void*, void*, void*);
extern "C" void* func_020dedd0(Struct_0201099c_10*, int);
extern "C" void func_02083e28(void*, int);
extern "C" void func_020863c4(unsigned char*);
extern "C" void func_0209a804(int*);
extern "C" void func_0209a810(Struct_0201099c_18*, void*);
extern "C" void func_02083b60(unsigned char*, int);
extern "C" void func_020830cc(void*, Struct_ov009_0218742c*);
extern "C" void func_02086778(void*, Struct_ov009_0218742c*, unsigned char, unsigned char);
extern "C" void* func_ov003_0215f4fc(void*, const char*);
extern Struct_02108760 data_02108760;
extern unsigned char data_ov009_0218a9b4[];
extern char data_ov009_0218ad2c[];
extern char data_0211e33c[] __attribute__((aligned(4)));
extern Struct_ov009_0218aac8 data_ov009_0218aac8[];
extern char data_ov009_0218ad26[];

inline Struct_ov009_0218742c_7* inline_ov009_0218742c_4(Struct_ov009_0218742c* arg0) { return arg0->unknown_14c_; }

// USA: func_ov009_0218742c
extern "C" ARM void func_ov009_0218742c(Struct_ov009_0218742c_6* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_020d6c00();
    unsigned int var1 = arg0->unknown_c59_;
    if (var1 == 0) {
        func_ov023_021d9f88(arg0);
        func_0205deb4((Struct_0205d81c*)arg0->unknown_2b4_, 3, 2);
        func_0205eaa0(&data_02108760, 5, 0);
        ++arg0->unknown_c59_;
    } else if (var1 == 1) {
        arg0->unknown_d9c_ |= 0x2000;
        ColorEffect_ConfigureBrightnessAdjust(0x04001050, 1, -8);
        arg0->unknown_d9c_ &= ~0x1000000;
        ++arg0->unknown_c59_;
    } else if (var1 == 2) {
        arg0->unknown_d84_ = func_0205d794((Struct_0205c570*)arg0->unknown_2b4_);
        int var2 = 0;
        int var3 = func_0205da38((Struct_0205da38*)arg0->unknown_2b4_, 0x14);
        int var4 = g_keyManager.TestKeysPressed(1);
        int var5 = g_keyManager.TestKeysPressed(0x400);
        if (var3 | (var4 | var5)) {
            func_0205eaa0(&data_02108760, 1, 0);
            switch (arg0->unknown_d84_) {
            case 0: ++arg0->unknown_c59_; break;
            case 1: var2 = 1; break;
            }
        } else if (g_keyManager.TestKeysPressed(2)) var2 = 1;
        if (arg0->unknown_c59_ == 3) {
            func_0205d6a0((Struct_0205d6a0*)arg0->unknown_2b4_, 0);
            func_0205deb4((Struct_0205d81c*)arg0->unknown_2b4_, 3, 2);
#if defined(jpn)
            arg0->unknown_d9c_ &= ~0x20;
            arg0->unknown_d9c_ &= ~0x40;
#else
            arg0->unknown_d9c_ &= ~0x60;
#endif
        } else if (var2) {
            func_0205d6a0((Struct_0205d6a0*)arg0->unknown_2b4_, 0);
#if defined(jpn)
            arg0->unknown_d9c_ &= ~0x20;
            arg0->unknown_d9c_ &= ~0x40;
#else
            arg0->unknown_d9c_ &= ~0x60;
#endif
            arg0->unknown_c59_ = 255;
        }
    } else if (var1 == 3) {
        func_0204b010((Struct_0204b010*)arg0->unknown_1b8_, 0);
        func_0204bc74(arg0->unknown_1b8_, 0, 0, 0, 32, 25, 0);
        func_0204b04c(arg0->unknown_1b8_, 0);
        func_0204b088(arg0->unknown_1b8_, 0);
        if (arg0->unknown_d95_ == 0) {
            Struct_ov009_0218742c_9* var6 = arg0->unknown_d88_;
            var6->unknown_56a_ = data_ov009_0218a9b4[arg0->unknown_da8_[arg0->unknown_da3_]];
            ((Struct_ov009_0218742c_8*)var0)->unknown_63d4_ = 1;
            ColorEffect_ConfigureBrightnessAdjust(0x04001050, 1, 0);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)menu->entryList, 3, 0);
            ClearBuffers0204b010OverList0x98((Cont0205d1e0*)menu->entryList);
            CallFunc0204c8f0OverList0x9c((Cont0205d228*)menu->entryList);
            CallFunc0204b04cOverList0x98((Cont0205d274*)menu->entryList);
            InitEntries0205d2bc((Obj0205d2bc*)menu->entryList);
            CharacterCreationUI_SwitchTab((unsigned char*)menu, 10);
#if defined(jpn)
        } else if (arg0->unknown_d95_ == 1) {
            void* var7 = func_02010828(var0);
            Struct_ov009_0218742c var8;
            func_02086404(&var8);
            func_02083ca0((unsigned char*)arg0->unknown_d88_, arg0->unknown_da2_);
            arg0->unknown_d88_->unknown_138_[arg0->unknown_da2_] = 0;
            arg0->unknown_d88_->unknown_16c_[arg0->unknown_da2_] = 1;
            arg0->unknown_d88_->unknown_56a_ = NextRandomMax(GetBTRandom(), 16);
            char var9[32];
            int var10 = arg0->unknown_d88_->unknown_950_;
            sprintf(var9, data_ov009_0218ad2c, var10);
            Struct_ov009_0218742c_2 var11;
            func_0208247c(&var11);
            BackgroundLoader::AddLockGlobal();
            unsigned int var12;
            void* var13 = LoadFileIntoMemory(var9, data_0211e33c, &var12);
            if (var13) func_02082490(&var11, var13, var12, arg0->unknown_d88_->unknown_16c_[arg0->unknown_da2_], 0);
            func_02083cbc(arg0->unknown_d88_, &var11, var11.unknown_3c_);
            BackgroundLoader::RemoveLockGlobal();
            short* var14 = arg0->unknown_d88_->unknown_488_;
            for (int var15 = 0; var15 < 7; ++var15) {
                void* var16 = func_020dedd0((Struct_0201099c_10*)arg0->unknown_a8_, var14[data_ov009_0218aac8[var15].unknown_0_]);
                if (var16) memcpy(&arg0->unknown_d88_->unknown_194_[data_ov009_0218aac8[var15].unknown_1_], var16, 32);
            }
            func_02083e28(arg0->unknown_d88_, 0);
            func_020863c4((unsigned char*)arg0->unknown_d88_);
            Struct_ov009_0218742c_7* var17 = inline_ov009_0218742c_4(&var8);
            Struct_ov009_0218742c_9* var18 = arg0->unknown_d88_;
            var17[0].unknown_0_0_ = var18->unknown_0_[0].unknown_0_0_;
            var17[0].unknown_1_2_ = var18->unknown_0_[0].unknown_1_2_;
            var17[0].unknown_2_4_ = var18->unknown_0_[0].unknown_2_4_;
            var17[1].unknown_0_0_ = var18->unknown_0_[1].unknown_0_0_;
            var17[1].unknown_1_2_ = var18->unknown_0_[1].unknown_1_2_;
            var17[1].unknown_2_4_ = var18->unknown_0_[1].unknown_2_4_;
            var17[2].unknown_0_0_ = var18->unknown_0_[2].unknown_0_0_;
            var17[2].unknown_1_2_ = var18->unknown_6c_;
            var17[2].unknown_2_4_ = var18->unknown_6e_;
            var17[3].inline_ov009_0218742c_3(var18->unknown_6c_);
            var17[3].unknown_1_2_ = var18->unknown_6e_;
            var17[3].unknown_2_4_ = var18->unknown_70_;
            var17[4].unknown_0_0_ = var18->unknown_72_;
            var17[4].unknown_1_2_ = var18->unknown_0_[3].unknown_0_0_;
            int var19;
            func_0209a804(&var19);
            Struct_ov009_0218742c_4 var20;
            func_0209a810((Struct_0201099c_18*)&var19, &var20);
            unsigned char var21 = arg0->unknown_d88_->unknown_950_;
            unsigned char var22 = arg0->unknown_d88_->unknown_16c_[arg0->unknown_d88_->unknown_950_];
            Struct_ov009_0218742c_3* var23 = var20.unknown_10c_[var21];
            for (int var24 = 0; var24 < 20; ++var24) {
                if (var22 >= var23[var24].unknown_2_ && var23[var24].unknown_2_ != 0)
                    func_02083b60((unsigned char*)arg0->unknown_d88_, var23[var24].unknown_0_);
            }
            func_020830cc(menu->character, &snapshot);
            func_02086778(members, &snapshot, 0, 0);
            menu->flags |= 0x400;
            CharacterCreationUI_SwitchTab((unsigned char*)menu, 11);
        }
#else
        } else if (arg0->unknown_d95_ == 1) {
            Struct_ov009_0218742c_9* var25 = arg0->unknown_d88_;
            void* var26 = func_02010828(var0);
            Struct_ov009_0218742c var27;
            func_02086404(&var27);
            func_02083ca0((unsigned char*)var25, arg0->unknown_da2_);
            var25->unknown_138_[arg0->unknown_da2_] = 0;
            var25->unknown_16c_[arg0->unknown_da2_] = 1;
            var25->unknown_56a_ = NextRandomMax(GetBTRandom(), 16);
            char var28[32];
            int var29 = var25->unknown_950_;
            sprintf(var28, data_ov009_0218ad2c, var29);
            Struct_ov009_0218742c_2 var30;
            func_0208247c(&var30);
            BackgroundLoader::AddLockGlobal();
            unsigned int var31;
            void* var32 = LoadFileIntoMemory(var28, data_0211e33c, &var31);
            if (var32) func_02082490(&var30, var32, var31, var25->unknown_16c_[arg0->unknown_da2_], 0);
            func_02083cbc(var25, &var30, var30.unknown_3c_);
            BackgroundLoader::RemoveLockGlobal();
            short* var33 = var25->unknown_488_;
            for (int var34 = 0; var34 < 7; ++var34) {
                void* var35 = func_020dedd0((Struct_0201099c_10*)arg0->unknown_c8_, var33[data_ov009_0218aac8[var34].unknown_0_]);
                if (var35) memcpy(&var25->unknown_194_[data_ov009_0218aac8[var34].unknown_1_], var35, 32);
            }
            func_02083e28(var25, 0);
            func_020863c4((unsigned char*)var25);
            Struct_ov009_0218742c_7* var36 = inline_ov009_0218742c_4(&var27);
            var36[0].unknown_0_0_ = var25->unknown_0_[0].unknown_0_0_;
            var36[0].unknown_1_2_ = var25->unknown_0_[0].unknown_1_2_;
            var36[0].unknown_2_4_ = var25->unknown_0_[0].unknown_2_4_;
            var36[1].unknown_0_0_ = var25->unknown_0_[1].unknown_0_0_;
            var36[1].unknown_1_2_ = var25->unknown_0_[1].unknown_1_2_;
            var36[1].unknown_2_4_ = var25->unknown_0_[1].unknown_2_4_;
            var36[2].unknown_0_0_ = var25->unknown_0_[2].unknown_0_0_;
            var36[2].unknown_1_2_ = var25->unknown_6c_;
            var36[2].unknown_2_4_ = var25->unknown_6e_;
            var36[3].inline_ov009_0218742c_3(var25->unknown_6c_);
            var36[3].unknown_1_2_ = var25->unknown_6e_;
            var36[3].unknown_2_4_ = var25->unknown_70_;
            var36[4].unknown_0_0_ = var25->unknown_72_;
            var36[4].unknown_1_2_ = var25->unknown_0_[3].unknown_0_0_;
            int var37;
            func_0209a804(&var37);
            Struct_ov009_0218742c_4 var38;
            func_0209a810((Struct_0201099c_18*)&var37, &var38);
            unsigned char var39 = var25->unknown_950_;
            unsigned char var40 = var25->unknown_16c_[var25->unknown_950_];
            Struct_ov009_0218742c_3* var41 = var38.unknown_10c_[var39];
            for (int var42 = 0; var42 < 20; ++var42) {
                if (var40 >= var41[var42].unknown_2_ && var41[var42].unknown_2_ != 0)
                    func_02083b60((unsigned char*)var25, var41[var42].unknown_0_);
            }
            func_020830cc(character, &snapshot);
            func_02086778(members, &snapshot, 0, 0);
            menu->flags |= 0x400;
            CharacterCreationUI_SwitchTab((unsigned char*)menu, 11);
        }
#endif
    } else if (var1 == 255) {
        func_0204b010((Struct_0204b010*)arg0->unknown_1b8_, 0);
        func_0204bc74(arg0->unknown_1b8_, 0, 0, 0, 32, 25, 0);
        func_0204b04c(arg0->unknown_1b8_, 0);
        func_0204b088(arg0->unknown_1b8_, 0);
        ColorEffect_ConfigureBrightnessAdjust(0x04001050, 1, 0);
        func_0205deb4((Struct_0205d81c*)arg0->unknown_2b4_, 3, 0);
        func_0205deb4((Struct_0205d81c*)arg0->unknown_2b4_, 2, 0);
#if defined(jpn)
        CharacterCreationUI_SwitchTab((unsigned char*)menu, 8);
#else
        void* script = func_ov003_0215f4fc(menu->script, data_ov009_0218ad26);
        if (script) menu->script->script = script;
        menu->script->SetActive(1);
        menu->script->SetWaiting(0);
        CharacterCreationUI_SwitchTab((unsigned char*)menu, 8);
        menu->step = 1;
#endif
    }
}
