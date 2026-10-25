#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct SePlayer;
struct GridCursor;

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

extern int g_sePlayer;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
MemberScreen* GetField1c_021a193c(int* p);
void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" int GridCursor_Update(void* cursor, int ticks);
int GridCursor_GetSelectedIndex(GridCursor* s);
extern "C" void func_ov005_0215742c(EquipmentMenu* self);
extern "C" void func_ov005_0215751c(EquipmentMenu* self);
extern "C" void func_ov005_0215771c(EquipmentMenu* self);

// USA: func_ov005_0215730c
extern "C" ARM void func_ov005_0215730c(Struct_ov005_02153954* arg0) {
    if (g_keyManager.TestKeysPressed(2)) {
        func_ov005_0215792c(self, 1);
        MemberScreen* screen = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        screen->flags_ |= 0x800;
        SePlayer_Play((SePlayer*)&g_sePlayer, 0x1b, 0);
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
    GridCursor_Update(self->cursor_, ticks);
    GridCursor_GetSelectedIndex((GridCursor*)self->cursor_);
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
