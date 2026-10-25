#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov005_02153954 {
    char unknown_0_[R(0xee0, 0xee4)];
    char unknown_ee4_[R(0x3d33 - 0xee0, 0x3dbb - 0xee4)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[0x3dcc - 0x3dbc];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3ddc - 0x3dd0];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[R(0x56c, 0x634)];
    unsigned short unknown_634_;
};

struct Struct_ov005_02159850 {
    char unknown_0_[R(0x34f8, 0x3708)];
    int* unknown_3708_;
};

struct Struct_0205d6a0;

MemberScreen* GetField1c_021a193c(int* p);
void Window_ClosePane(Entry_0205d6a0* window, int unk);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);

// USA: func_ov005_02159850
extern "C" ARM void func_ov005_02159850(Struct_ov005_02153954* arg0) {
    if (arg0->unknown_3ddc_ != 0)
        return;
    Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
    if (self->slot_ >= 0 && self->slot_ < 8)
        func_ov005_0215792c(self, 3);
    else if (self->slot_ >= 8 && self->slot_ < 24)
        func_ov005_0215792c(self, 4);
    self->menuStep_ = 0;
    self->menuChoice_ = 0;
    self->menuState_ = 0;
    MemberScreen* screen = GetField1c_021a193c(((MenuContext*)GetGameResources())->unknown_ptr_3708);
    screen->flags_ |= 0x81;
    self->flags_ |= 0xc;
}
