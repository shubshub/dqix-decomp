#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Input/Input.h"

struct Struct_0205d5d0;

struct Struct_ov005_021571d0 {
    char unknown_0_[0x30];
    int unknown_30_;
    int inline_ov005_02158ed0() { return unknown_30_; }
};

struct Struct_ov005_02158ed0 {
    int unknown_0_;
    Struct_ov005_021571d0 unknown_4_;
    char unknown_38_[0xb0 - 0x38];
    unsigned char unknown_b0_;
    Struct_ov005_021571d0* inline_ov005_02158ed0_2() { return &unknown_4_; }
};

struct Struct_ov005_02153954 {
    char unknown_0_[0xe10];
    unsigned short* unknown_e10_;
    char unknown_e14_[LOW_REGION(0xee0, 0xee4) - 0xe14];
    Struct_ov005_02158ed0 unknown_ee4_;
    char unknown_f98_[LOW_REGION(0x3d55, 0x3ddd) - LOW_REGION(0xf94, 0xf98)];
    unsigned char unknown_3ddd_;
    Struct_ov005_02158ed0* inline_ov005_02158e04() { return &unknown_ee4_; }
};

extern "C" void func_ov005_02159a30(Struct_ov005_02153954* arg0, unsigned short* arg1, int arg2);
// USA: func_ov005_02158ed0
extern "C" ARM void func_ov005_02158ed0(Struct_ov005_02153954* arg0) {
    unsigned char var0 = arg0->unknown_3ddd_;
    if (var0 == 0)
        return;
    int var1 = 0;
    if (var0 == 2 && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
        if (arg0->inline_ov005_02158e04()->inline_ov005_02158ed0_2()->inline_ov005_02158ed0() < 0)
            return;
        var1 = 1;
    }
    memset(arg0->unknown_e10_, 0, LOW_REGION(0x800, 0x960));
    unsigned char var2 = arg0->unknown_ee4_.unknown_b0_;
    if (var2 == 1)
        func_ov005_02159a30(arg0, arg0->unknown_e10_, var1);
#if defined(jpn)
    Window_SetPaneText((StructA0205d5d0*)&self->window_, style, (int)self->text_, 1);
#else
    Window_SetPaneText((StructA0205d5d0*)&self->window_, style, (int)self->text_, 1, 0);
#endif
}
