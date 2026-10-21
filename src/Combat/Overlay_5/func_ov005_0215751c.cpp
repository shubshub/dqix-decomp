#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_02108760;
struct Struct_0205bb84;

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[R(0x4f8, 0x4fc)];
    int unknown_4fc_;
    char unknown_500_[R(0x56c - 0x4fc, 0x634 - 0x500)];
    unsigned short unknown_634_;
};

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0x196c, 0x19f4)];
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3db8 - 0x3030];
    unsigned char unknown_3db8_;
    unsigned char unknown_3db9_;
    unsigned char unknown_3dba_;
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_[0x3dcc - 0x3dc1];
    unsigned int unknown_3dcc_;
};

extern int data_02108760;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
MemberScreen* GetField1c_021a193c(int* p);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
int CheckFlag30Or401_02157190(void* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
int GridCursor_GetSelectedIndex(Struct_0205bb84* s);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void func_0205bb04(void* cursor, int index);

// USA: func_ov005_0215751c
extern "C" ARM void func_ov005_0215751c(Struct_ov005_02153954* arg0) {
    int var0 = 0;
    if (g_keyManager.TestKeysPressed(0x40))
        up = 1;
    if (up) {
        func_ov005_0215792c(self, 2);
        func_ov005_021579ec(self, self->state_, GridCursor_GetSelectedIndex((Struct_0205bb84*)self->cursor_));
        return;
    }
    int var1 = 0;
    if (g_keyManager.TestKeysPressed(0x80))
        var1 = 1;
    if (!var0) {
        GameState::GetInstance();
        Struct_ov005_02153ba4_2* var2 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
        if (!func_ov005_02157ae8(arg0, var2->unknown_4fc_))
            return;
        if (func_ov005_02157190(arg0)) {
            if (arg0->unknown_2d90_[arg0->unknown_3dbc_].unknown_0_ < 0) {
                var1 = 1;
            } else {
                func_ov005_0215792c(arg0, 5);
                func_0205eaa0((Struct_02108760*)&data_02108760, 1, 0);
                var2->unknown_634_ &= ~1;
                var2->unknown_634_ &= ~0x80;
            }
        }
    }
    if (var1) {
        func_ov005_0215792c(arg0, 4);
        arg0->unknown_3dbb_ = 8;
        func_0205bb04(arg0->unknown_19f4_, arg0->unknown_3dbb_ - 8);
        if (g_keyManager.TestKeysPressed(0x80))
            func_0205eaa0((Struct_02108760*)&data_02108760, 2, 0);
        else if (func_ov005_02157190(arg0))
            func_0205eaa0((Struct_02108760*)&data_02108760, 1, 0);
        func_ov005_021579ec(arg0, arg0->unknown_3db8_, arg0->unknown_3dbb_);
        return;
    }
    if (!func_ov005_02158560(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)self->cursor_), 0))
        return;
    arg0->unknown_3dbb_ = arg0->unknown_3dbc_;
    arg0->unknown_3dcc_ |= 0x100;
    func_ov005_021555c0(arg0);
}
