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
    char unknown_0_[R(0x56c, 0x634)];
    unsigned short unknown_634_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0x196c, 0x19f4)];
    char unknown_19f4_[0x3db8 - 0x19f4];
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
extern "C" int func_0205bf58(void* cursor, int ticks);
int GridCursor_GetSelectedIndex(Struct_0205bb84* s);
extern "C" void func_ov005_0215742c(EquipmentMenu* self);
extern "C" void func_ov005_0215751c(EquipmentMenu* self);
extern "C" void func_ov005_0215771c(EquipmentMenu* self);

// USA: func_ov005_0215730c
extern "C" ARM void func_ov005_0215730c(Struct_ov005_02153954* arg0) {
    if (g_keyManager.TestKeysPressed(2)) {
        func_ov005_0215792c(arg0, 1);
        Struct_ov005_02153ba4_2* var0 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
        var0->unknown_634_ |= 0x800;
        func_0205eaa0((Struct_02108760*)&data_02108760, 0x1b, 0);
        return;
    }
    if (g_keyManager.TestKeysPressed(4)) {
        if (arg0->unknown_3db8_ == 2 || arg0->unknown_3db8_ == 3 || arg0->unknown_3db8_ == 4) {
            func_ov005_0215792c(arg0, 7);
            arg0->unknown_3dcc_ |= 0x80000;
            return;
        }
    }
    int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_0205bf58(self->cursor_, ticks);
    GridCursor_GetSelectedIndex((Struct_0205bb84*)self->cursor_);
    switch (self->state_) {
    case 2:
        func_ov005_0215742c(arg0);
        return;
    case 3:
        func_ov005_0215751c(arg0);
        return;
    case 4:
        func_ov005_0215771c(arg0);
        return;
    }
}
