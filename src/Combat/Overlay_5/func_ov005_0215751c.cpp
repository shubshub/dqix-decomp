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
    char unk_0[R(0x4f8, 0x4fc)];
    int member_;
    char unknown_500_[R(0x56c - 0x4fc, 0x634 - 0x500)];
    unsigned short flags_;
};

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    char cursor_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 slots_[24];
    char unknown_3030_[0x3db8 - 0x3030];
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
extern "C" int func_ov005_02157190(void* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int GridCursor_GetSelectedIndex(GridCursor* s);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

// USA: func_ov005_0215751c
extern "C" ARM void func_ov005_0215751c(EquipmentMenu* self) {
    int up = 0;
    if (g_keyManager.TestKeysPressed(0x40))
        up = 1;
    if (up) {
        func_ov005_0215792c(self, 2);
        func_ov005_021579ec(self, self->state_, GridCursor_GetSelectedIndex((GridCursor*)self->cursor_));
        return;
    }
    int down = 0;
    if (g_keyManager.TestKeysPressed(0x80))
        down = 1;
    if (!up) {
        GameState::GetInstance();
        MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        if (!func_ov005_02157ae8(self, screen->member_))
            return;
        if (func_ov005_02157190(self)) {
            if (self->slots_[self->kind_].item_ < 0) {
                down = 1;
            } else {
                func_ov005_0215792c(self, 5);
                SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
                screen->flags_ &= ~1;
                screen->flags_ &= ~0x80;
            }
        }
    }
    if (down) {
        func_ov005_0215792c(self, 4);
        self->slot_ = 8;
        GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
        if (g_keyManager.TestKeysPressed(0x80))
            SePlayer_Play((SePlayer*)&g_sePlayer, 2, 0);
        else if (func_ov005_02157190(self))
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        func_ov005_021579ec(self, self->state_, self->slot_);
        return;
    }
    if (!func_ov005_02158560(self, GridCursor_GetSelectedIndex((GridCursor*)self->cursor_), 0))
        return;
    self->slot_ = self->kind_;
    self->flags_ |= 0x100;
    func_ov005_021555c0(self);
}
