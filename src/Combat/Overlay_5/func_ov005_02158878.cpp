#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_02158878 func_ov005_02159e70
#endif
#include <std_library_functions.h>
#include "Input/Input.h"

struct StructA0205d5d0;
struct Struct_0205d81c;
struct Entry_0205d6a0;
struct MenuElement;
struct SePlayer;

struct Struct_ov005_02158ed0 {
    int unk_0;
    char list_[0x38 - 4];
    char unknown_38_[0xb0 - 0x38];
    unsigned char unknown_b0_;
};

struct EquipmentMenu {
    char unk_0[0xe10];
    unsigned short* text_;
    char unknown_e14_[LOW_REGION(0xee0, 0xee4) - 0xe14];
    Struct_ov005_02158ed0 window_;
    char unknown_f98_[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0xf94, 0xf98)];
    unsigned int flags_;
    unsigned char step_;
    unsigned char kind_;
    unsigned char unknown_3dd2_;
    char unknown_3dd3_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d4b, 0x3dd3)];
};

extern "C" char g_sePlayer[];

extern "C" void Window_Update(void* window);
extern "C" void func_ov005_021589f4(EquipmentMenu* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
extern "C" MenuElement* func_0205d81c(Struct_0205d81c* s, int key);
extern "C" int WindowPane_IsReady(unsigned char*);
extern "C" int func_ov005_02157190(void* self);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int unk);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int unk);
// USA: func_ov005_02158878
extern "C" ARM void func_ov005_02158878(EquipmentMenu* self) {
    Window_Update(&self->window_);
    if (self->step_ == 0) {
        func_ov005_021589f4(self);
        self->step_++;
        return;
    }
    if (self->step_ == 1) {
        if (WindowPane_IsReady((unsigned char*)(func_0205d81c((Struct_0205d81c*)&self->window_, 0)))) {
            if (self->kind_ == 0xc || self->kind_ == 0xd)
                self->flags_ |= 0x10000;
        }
        self->step_++;
        return;
    }
    if (self->step_ != 2)
        return;
    int clear;
    unsigned char touch;
    touch = g_touchInput.pressed_;
    clear = 0;
    int flag = func_ov005_02157190(self);
    if (flag | touch) {
        SePlayer_Play((SePlayer*)g_sePlayer, 1, clear);
        if (self->unknown_3dd2_ != 0) {
            self->kind_ = self->unknown_3dd2_;
            self->unknown_3dd2_ = 0;
            memset(self->text_, clear, LOW_REGION(0x800, 0x960));
            func_ov005_02158b3c(self, self->text_);
#if defined(jpn)
            Window_SetPaneText((StructA0205d5d0*)&self->window_, clear, (int)self->text_, 1);
#else
            Window_SetPaneText((StructA0205d5d0*)&self->window_, clear, (int)self->text_, 1, clear);
#endif
            return;
        }
        clear = 1;
    } else if (g_keyManager.TestKeysPressed(2)) {
        clear = 1;
    }
    if (clear) {
        Window_ClosePane((Entry_0205d6a0*)&self->window_, 0);
        self->step_ = 0;
        self->kind_ = 0;
    }
}
