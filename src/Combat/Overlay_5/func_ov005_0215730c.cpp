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

struct MemberScreen {
    char unk_0[R(0x56c, 0x634)];
    unsigned short flags_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    char cursor_[0x3db8 - 0x19f4];
    unsigned char state_;
    unsigned char unknown_3db9_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_[0x3dcc - 0x3dc1];
    unsigned int flags_;
};

extern int g_sePlayer;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" int GridCursor_Update(void* cursor, int ticks);
extern "C" int GridCursor_GetSelectedIndex(GridCursor* s);
extern "C" void func_ov005_0215742c(EquipmentMenu* self);
extern "C" void func_ov005_0215751c(EquipmentMenu* self);
extern "C" void func_ov005_0215771c(EquipmentMenu* self);

// USA: func_ov005_0215730c
extern "C" ARM void func_ov005_0215730c(EquipmentMenu* self) {
    if (g_keyManager.TestKeysPressed(2)) {
        func_ov005_0215792c(self, 1);
        MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        screen->flags_ |= 0x800;
        SePlayer_Play((SePlayer*)&g_sePlayer, 0x1b, 0);
        return;
    }
    if (g_keyManager.TestKeysPressed(4)) {
        if (self->state_ == 2 || self->state_ == 3 || self->state_ == 4) {
            func_ov005_0215792c(self, 7);
            self->flags_ |= 0x80000;
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
        func_ov005_0215742c(self);
        return;
    case 3:
        func_ov005_0215751c(self);
        return;
    case 4:
        func_ov005_0215771c(self);
        return;
    }
}
