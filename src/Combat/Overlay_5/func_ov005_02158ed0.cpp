#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Input/Input.h"

struct StructA0205d5d0;

struct Struct_ov005_021571d0 {
    char unk_0[0x30];
    int cursor_;
    int inline_ov005_02158ed0() { return cursor_; }
};

struct Struct_ov005_02158ed0 {
    int unk_0;
    Struct_ov005_021571d0 list_;
    char unknown_38_[0xb0 - 0x38];
    unsigned char unknown_b0_;
    Struct_ov005_021571d0* inline_ov005_02158ed0_2() { return &list_; }
};

struct EquipmentMenu {
    char unk_0[0xe10];
    unsigned short* text_;
    char unknown_e14_[LOW_REGION(0xee0, 0xee4) - 0xe14];
    Struct_ov005_02158ed0 window_;
    char unknown_f98_[LOW_REGION(0x3d55, 0x3ddd) - LOW_REGION(0xf94, 0xf98)];
    unsigned char unknown_3ddd_;
    Struct_ov005_02158ed0* GetWindow() { return &window_; }
};

extern "C" void func_ov005_02159a30(EquipmentMenu* self, unsigned short* text, int touched);
// USA: func_ov005_02158ed0
extern "C" ARM void func_ov005_02158ed0(EquipmentMenu* self) {
    unsigned char mode = self->unknown_3ddd_;
    if (mode == 0)
        return;
    int touched = 0;
    if (mode == 2 && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
        if (self->GetWindow()->inline_ov005_02158ed0_2()->inline_ov005_02158ed0() < 0)
            return;
        touched = 1;
    }
    memset(self->text_, 0, LOW_REGION(0x800, 0x960));
    unsigned char style = self->window_.unknown_b0_;
    if (style == 1)
        func_ov005_02159a30(self, self->text_, touched);
#if defined(jpn)
    Window_SetPaneText((StructA0205d5d0*)&self->window_, style, (int)self->text_, 1);
#else
    Window_SetPaneText((StructA0205d5d0*)&self->window_, style, (int)self->text_, 1, 0);
#endif
}
