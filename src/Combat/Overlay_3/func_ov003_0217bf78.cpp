#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameObject;

struct Struct_ov003_0217bf78 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x70 - 0x1c];
    Vector3i unknown_70_;
    char unknown_7c_[0x21e - 0x7c];
    short unknown_21e_;
};

struct Struct_ov003_0217bf78_2 {
    char unknown_0_[0x80];
    char unknown_80_[0x130 - 0x80];
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    int unknown_13c_;
    unsigned char unknown_140_;
    signed char unknown_141_;
    char unknown_142_[2];
    Vector3i unknown_144_;
    Vector3i unknown_150_;
    char unknown_15c_[0x160 - 0x15c];
    int unknown_160_;
};

extern "C" void func_020a27a0(void *arg0);
extern "C" void func_020a27ac(void *arg0);
extern "C" int func_0202e7f0(void *arg0);
extern "C" int func_020421a0();
extern "C" void func_02043204(char *arg0);
extern "C" void func_ov003_0217c974(Struct_ov003_0217bf78_2 *arg0);
extern "C" void func_0202e694(void *arg0, int *arg1);
extern "C" void func_0200fd38(GameState *arg0, int arg1, GameObject *arg2);
extern "C" void func_ov003_0217ca84(Struct_ov003_0217bf78_2 *arg0, unsigned short arg1);
extern "C" void func_020a64e8(void);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_ov003_0217c2a0(int arg0);
extern "C" void func_ov003_0217cb3c(Struct_ov003_0217bf78_2 *arg0, int arg1, int arg2);
extern "C" void func_0205ebc0(void *arg0, int arg1, int arg2);

extern char data_ov003_02180bef[];
extern char data_ov003_02180cf8[];
extern char data_ov003_02180d08[];
extern char data_ov003_02180c07[];
extern Vector3i data_ov003_02180ce0;
extern int data_ov003_02180cec[3];
extern int g_sePlayer;

// USA: func_ov003_0217bf78
extern "C" ARM void func_ov003_0217bf78(Struct_ov003_0217bf78_2 *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();
    GameResources *var1 = GetGameResources();

    if (arg0->unknown_141_ == 0) {
        GameState *var2          = GameState::GetInstance();
        arg0->unknown_130_            = var0->QueueLoadFileInGP2(data_ov003_02180bef, data_ov003_02180cf8, 0);
        arg0->unknown_138_            = var0->QueueLoadFile(data_ov003_02180d08, 0);
        arg0->unknown_134_            = var0->QueueLoadFile(data_ov003_02180c07, 0);
        Struct_ov003_0217bf78 *var3 = (Struct_ov003_0217bf78*)func_020100bc(var2);
        func_020a27a0(var3);
        func_020a27ac(var3);
        var3->unknown_21e_ = func_0202e7f0(var3);
        var0->RemoveTask(arg0->unknown_13c_);
        arg0->unknown_13c_ = -1;
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 1) {
        if (!var0->GetTaskStatus(arg0->unknown_130_)) return;
        if (IsBrightnessTransitionActive(var1)) return;
        if (var0->GetDetailedTaskStatus(arg0->unknown_130_) != 2) {
            var0->RemoveTask(arg0->unknown_130_);
            arg0->unknown_140_  = 4;
            arg0->unknown_141_ = 0;
        }
        GameState *var4 = GameState::GetInstance();
        func_02043204((char *) func_020421a0());
        func_ov003_0217c974(arg0);
        Struct_ov003_0217bf78 *var5 = (Struct_ov003_0217bf78*)func_020100bc(var4);
        arg0->unknown_144_   = var5->unknown_10_;
        arg0->unknown_150_       = var5->unknown_70_;
        var5->unknown_10_       = data_ov003_02180ce0;
        func_0202e694(var5, data_ov003_02180cec);
        func_0200fd38(var4, 0xa0, (GameObject *) arg0->unknown_80_);
        func_ov003_0217ca84(arg0, 0);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 2) {
        if (!var0->GetTaskStatus(arg0->unknown_134_)) return;
        if (var0->GetDetailedTaskStatus(arg0->unknown_134_) != 2) {
            var0->RemoveTask(arg0->unknown_134_);
            arg0->unknown_140_  = 4;
            arg0->unknown_141_ = 0;
        }
        if (arg0->unknown_160_ != 0) func_020a64e8();
        ((Object3D*)arg0->unknown_80_)->MakeHidden();
        func_020c5588(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        func_ov003_0217c2a0(1);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 3) {
        if (!var0->GetTaskStatus(arg0->unknown_138_)) return;
        if (var0->GetDetailedTaskStatus(arg0->unknown_138_) != 2) {
            var0->RemoveTask(arg0->unknown_138_);
            arg0->unknown_140_  = 4;
            arg0->unknown_141_ = 0;
        }
        func_ov003_0217cb3c(arg0, 0, 0);
        unsigned short *var6 = (unsigned short *) GetSubBG0ScreenBase();
        for (int var7 = 0; var7 < 0x800; var7++)
            *var6++ = 0;
        *(volatile unsigned int *) 0x4001000 &= ~0x1f00;
        self->mode  = 2;
        self->state = 0;
        SetForwardAndStore0205ebc0(&g_sePlayer, 0x8b, 0x8b);
    }
}
