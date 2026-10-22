#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct_02109bf4_2;

struct Struct_ov003_0217c2bc {
    SafeAllocator *unknown_0_;
    SafeAllocator unknown_4_;
    char unknown_18_[0x80 - 4 - sizeof(SafeAllocator)];
    char unknown_80_[0x140 - 0x80];
    unsigned char unknown_140_;
    signed char unknown_141_;
    unsigned char unknown_142_;
};

extern "C" void func_0205ebfc(void *arg0, int arg1, int arg2);
extern "C" void func_ov003_0217cb3c(Struct_ov003_0217c2bc *arg0, int arg1, int arg2);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov003_0217c974(Struct_ov003_0217c2bc *arg0);
extern "C" void func_0209c830(Struct_02109bf4_2*, int);

extern int g_sePlayer;
extern struct Struct0209c830 data_02109bf4;

// USA: func_ov003_0217c2bc
extern "C" ARM void func_ov003_0217c2bc(Struct_ov003_0217c2bc *arg0) {
    GameResources *var0 = GetGameResources();

    if (self->state == 0) {
        self->timer = 0x4b;
        self->state++;
    } else if (self->state == 1) {
        if (--self->timer != 0) return;
        DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
        func_ov003_0217cb3c(self, 1, 0);
        ((Object3D*)self->object)->MakeVisible();
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x300;
        SetBrightness(var0, 0x10, 0xa);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 2) {
        if (IsBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, 7, 0x14);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 3) {
        if (IsBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, 0x10, 0xf);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 4) {
        if (IsBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, -16, 0x46);
        arg0->unknown_142_ = 0x3c;
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 5) {
        if (--arg0->unknown_142_ != 0) return;
        SetBrightness(var0, 0x10, 7);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 6) {
        if (IsBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, -16, 0x1e);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 7) {
        if (IsBrightnessTransitionActive(var0)) return;
        func_020c5588(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        arg0->unknown_4_.Reset();
        ((Object3D*)arg0->unknown_80_)->Initialize();
        func_ov003_0217c974(arg0);
        arg0->unknown_142_ = 0x3c;
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 8) {
        if (--arg0->unknown_142_ != 0) return;
        func_ov003_0217cb3c(arg0, 0, 0);
        SetMainBrightness(var0, 0, 0x5a);
        arg0->unknown_142_ = 0x28;
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 9) {
        if (--arg0->unknown_142_ != 0) return;
        SetSubBrightness(var0, 0, 2);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 10) {
        if (IsSubBrightnessTransitionActive(var0)) return;
        SetSubBrightness(var0, -16, 5);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 11) {
        if (IsMainBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, 0x10, 0xa);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 12) {
        if (IsBrightnessTransitionActive(var0)) return;
        func_0209c830(&data_02109bf4, 0x43);
        SetBrightness(var0, 0, 0x3c);
        func_ov003_0217cb3c(arg0, 0, 1);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 13) {
        if (IsBrightnessTransitionActive(var0)) return;
        arg0->unknown_142_ = 0xf;
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 14) {
        if (--arg0->unknown_142_ != 0) return;
        SetBrightness(var0, 0x10, 0xa);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 15) {
        if (IsBrightnessTransitionActive(var0)) return;
        SetBrightness(var0, 0, 0x1e);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 16) {
        if (!IsBrightnessTransitionActive(var0)) {
            arg0->unknown_140_  = 3;
            arg0->unknown_141_ = 0;
        }
    }
}
