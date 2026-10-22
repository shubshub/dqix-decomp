#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int func_02053604(signed char* arg0);
extern "C" void func_0205eabc(void* arg0, void* arg1, int arg2);
extern "C" int func_02039d7c(char* arg0);
extern "C" int func_020100b0(GameState* arg0);
extern "C" int func_020100f8(char* arg0);
extern "C" void func_020a2c8c(unsigned char* arg0);
extern "C" void* func_020421a0(void);

struct Struct_02010604;
extern "C" void func_02033b88(struct Struct_02010604* arg0, int arg1);

extern "C" void func_ov017_021cc1f8(int arg0, const char* arg1, int arg2, int arg3);

extern char g_sePlayer;

struct Struct_020531f0 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

struct Struct_020531f0_2 {
    Object3D unknown_0_;
    char unknown_ac_[0xb2 - 0xac];
    unsigned short unknown_b2_;
    char unknown_b4_[0xc1 - 0xb4];
    struct Struct_020531f0 unknown_c1_;
#if defined(jpn)
    char unknown_c2_[0x16c - 0xc2];
#else
    char unknown1_c2_[0x178 - 0xc2];
#endif
    signed char unknown_178_[4];
    signed char unknown_17c_;
    signed char unknown_17d_;
    signed char unknown_17e_;
    signed char unknown_17f_;
    int unknown_180_;
    signed char unknown_184_;
    signed char unknown_185_;
    signed char unknown_186_;
    char unknown_187_[0x190 - 0x187];
    int unknown_190_;
    int unknown_194_;
};

// USA: func_020531f0
extern "C" ARM void func_020531f0(struct Struct_020531f0_2* arg0) {
#if defined(jpn)
    enum { Enum_020531f0_408 = 0x18c, Enum_020531f0_6577 = 0x17e1 };
#else
    enum { Enum_020531f0_408 = 0x198, Enum_020531f0_6577 = 0x19b1 };
#endif
    BackgroundLoader* var0;
    GameState* var1;
    signed char var2[4];
    int var3;
    int var4;

    var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_180_ > -1) {
        var0->RemoveTask(arg0->unknown_180_);
        arg0->unknown_180_ = -1;
    }

    if (GetIndexedEntryField0x178_02053604((signed char*)obj) == 0x19) {
        ForwardToTargetOrDefault0205eabc((void*)&g_sePlayer, (char*)obj + targetOffset, 0);
    }

    memset(arg0->unknown_178_, 0, 4);
    arg0->unknown_17c_ = 0;
    arg0->unknown_17d_ = 0;
    arg0->unknown_180_ = -1;
    arg0->unknown_17e_ = 0;
    arg0->unknown_17f_ = 0;
    arg0->unknown_184_ = 0;

    if (arg0->unknown_194_ > -1) {
        var0->RemoveTask(arg0->unknown_194_);
        arg0->unknown_194_ = -1;
    }

    arg0->unknown_190_ = 0;
    arg0->unknown_194_ = -1;
    arg0->unknown_185_ = 0;
    arg0->unknown_186_ = 0;

    if ((arg0->unknown_0_.unknown_0_ & 0x200) != 0) {
        if (func_02039d7c((char*)arg0) != 0) {
            return;
        }
    }

    arg0->unknown_c1_.unknown_0_0_ &= ~2;
    arg0->unknown_0_.RemoveAnimationPackageByID(2);
    arg0->unknown_b2_ = 0;
    func_02033b88((struct Struct_02010604*)arg0, 0);

    var1 = GameState::GetInstance();
    var4 = arg0->unknown_0_.unknown_4_;
    int var5 = func_020100b0(var1);
    if (var5 == var4) {
        var3 = func_020100f8((char*)var1);
        if (var3 != 0) {
            if (g_keyManager.TestKeysHeld(2) == 0
                || ((unsigned char*)func_020421a0())[Enum_020531f0_6577] != 0) {
                func_020a2c8c((unsigned char*)var3);
            }
        }
    }

    func_ov017_021cc1f8(arg0->unknown_0_.unknown_4_, (const char*)var2, 0, 1);
}
