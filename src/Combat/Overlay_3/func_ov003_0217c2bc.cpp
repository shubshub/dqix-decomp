#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct0209c830;

struct Struct_ov003_0217c2bc {
    SafeAllocator *allocator;
    SafeAllocator allocA;
    char unknown_18_[0x80 - 4 - sizeof(SafeAllocator)];
    char object[0x140 - 0x80];
    unsigned char mode;
    signed char state;
    unsigned char timer;
};

extern "C" void SePlayer_PlayExtra(void *obj, int a, int b);
extern "C" void func_ov003_0217cb3c(Struct_ov003_0217c2bc *self, int arg1, int alternate);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" void func_ov003_0217c974(Struct_ov003_0217c2bc *self);
extern "C" void func_0209c830(Struct0209c830*, int);

extern int g_sePlayer;
extern struct Struct0209c830 g_bgmPlayer;

// USA: func_ov003_0217c2bc
extern "C" ARM void func_ov003_0217c2bc(Struct_ov003_0217c2bc *self) {
    GameResources *resources = GetGameResources();

    if (self->state == 0) {
        self->timer = 0x4b;
        self->state++;
    } else if (self->state == 1) {
        if (--self->timer != 0) return;
        SePlayer_PlayExtra(&g_sePlayer, 0, 0);
        func_ov003_0217cb3c(self, 1, 0);
        ((Object3D*)self->object)->MakeVisible();
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x300;
        SetBrightness(resources, 0x10, 0xa);
        self->state++;
    } else if (self->state == 2) {
        if (IsBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, 7, 0x14);
        self->state++;
    } else if (self->state == 3) {
        if (IsBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, 0x10, 0xf);
        self->state++;
    } else if (self->state == 4) {
        if (IsBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, -16, 0x46);
        self->timer = 0x3c;
        self->state++;
    } else if (self->state == 5) {
        if (--self->timer != 0) return;
        SetBrightness(resources, 0x10, 7);
        self->state++;
    } else if (self->state == 6) {
        if (IsBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, -16, 0x1e);
        self->state++;
    } else if (self->state == 7) {
        if (IsBrightnessTransitionActive(resources)) return;
        Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        self->allocA.Reset();
        ((Object3D*)self->object)->Initialize();
        func_ov003_0217c974(self);
        self->timer = 0x3c;
        self->state++;
    } else if (self->state == 8) {
        if (--self->timer != 0) return;
        func_ov003_0217cb3c(self, 0, 0);
        SetMainBrightness(resources, 0, 0x5a);
        self->timer = 0x28;
        self->state++;
    } else if (self->state == 9) {
        if (--self->timer != 0) return;
        SetSubBrightness(resources, 0, 2);
        self->state++;
    } else if (self->state == 10) {
        if (IsSubBrightnessTransitionActive(resources)) return;
        SetSubBrightness(resources, -16, 5);
        self->state++;
    } else if (self->state == 11) {
        if (IsMainBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, 0x10, 0xa);
        self->state++;
    } else if (self->state == 12) {
        if (IsBrightnessTransitionActive(resources)) return;
        func_0209c830(&g_bgmPlayer, 0x43);
        SetBrightness(resources, 0, 0x3c);
        func_ov003_0217cb3c(self, 0, 1);
        self->state++;
    } else if (self->state == 13) {
        if (IsBrightnessTransitionActive(resources)) return;
        self->timer = 0xf;
        self->state++;
    } else if (self->state == 14) {
        if (--self->timer != 0) return;
        SetBrightness(resources, 0x10, 0xa);
        self->state++;
    } else if (self->state == 15) {
        if (IsBrightnessTransitionActive(resources)) return;
        SetBrightness(resources, 0, 0x1e);
        self->state++;
    } else if (self->state == 16) {
        if (!IsBrightnessTransitionActive(resources)) {
            self->mode  = 3;
            self->state = 0;
        }
    }
}
