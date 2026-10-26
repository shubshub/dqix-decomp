#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameResources;
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_0209ca2c(void* obj);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(unsigned short*, int, int);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);
extern int g_bgmPlayer;

struct Struct_ov023_021ecaa4 {
    char pad0[0x60];
    unsigned char f60 : 4;
    unsigned char unknown_60_4_ : 4;
    char pad1[0xc0 - 0x61];
    unsigned char fc0 : 4;
    unsigned char unknown_c0_4_ : 4;
    char pad2[0x430 - 0xc1];
    unsigned char unknown_430_;
    char pad3[0x432 - 0x431];
    unsigned char unknown_432_;
    char pad4[0x438 - 0x433];
    unsigned short unknown_438_;
    char pad5[0x44a - 0x43a];
    unsigned char unknown_44a_;
};

// USA: func_ov023_021ecaa4
extern "C" ARM void func_ov023_021ecaa4(Struct_ov023_021ecaa4* obj) {
    GameResources* result = GetGameResources();
    unsigned char state = obj->unknown_432_;
    if (state == 0) {
        if (obj->f60 == 0)
            SetMainBrightness(result, -16, 15);
        else
            SetSubBrightness(result, -16, 15);
        obj->unknown_432_++;
    }
    if (state != 1) return;
    if (IsBrightnessTransitionActive(result)) return;
    if (obj->unknown_44a_ != 0) {
        if (!(obj->unknown_430_ == 0 || obj->unknown_430_ == 1)) {
            if (func_0209ca2c((void*)&g_bgmPlayer)) return;
        }
        if (!(obj->unknown_438_ & 0x20)) {
            if (obj->fc0 == 0)
                ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4000050, 0x17, 0);
            else
                ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4001050, 0x17, 0);
        }
    }
    Window_ClosePane((struct Entry_0205d6a0*)((char*)obj + 0xc4), 1);
    obj->unknown_438_ |= 4;
    if (obj->unknown_438_ & 0x10)
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    obj->unknown_432_++;
}
