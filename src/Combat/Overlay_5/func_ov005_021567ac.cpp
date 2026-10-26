#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_021567ac_1276 = 0x4f8 };
enum { Enum_ov005_021567ac_1588 = 0x56c, Enum_ov005_021567ac_6644 = 0x196c };
#else
enum { Enum_ov005_021567ac_1276 = 0x4fc };
enum { Enum_ov005_021567ac_1588 = 0x634, Enum_ov005_021567ac_6644 = 0x19f4 };
#endif

#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct SePlayer;

struct MemberScreen {
    char unk_0[Enum_ov005_021567ac_1276];
    int member_;
    char unknown_500_[Enum_ov005_021567ac_1588 - Enum_ov005_021567ac_1276 - 4];
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
    char unk_0[Enum_ov005_021567ac_6644];
    char cursor_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 slots_[24];
    char slotModels_[0x3d78 - 0x3030];
    short dragged_;
    char unknown_3d7a_[0x3db8 - 0x3d7a];
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
    char unknown_3dd0_[0x3de0 - 0x3dd0];
    short unknown_3de0_;
};

extern int g_sePlayer;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);

// USA: func_ov005_021567ac
extern "C" ARM void func_ov005_021567ac(EquipmentMenu* self, int x, int y) {
    GameState::GetInstance();
    MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    if (!func_ov005_02157ae8(self, screen->member_))
        return;
    self->dragged_ = func_ov005_02155670(self, x, y);
    if (self->dragged_ >= 8 && self->dragged_ < 24) {
        if (self->slots_[self->dragged_].item_ == -1) {
            self->dragged_ = -1;
            self->unknown_3dc0_ = -1;
            return;
        }
        func_ov005_0215792c(self, 4);
        self->slot_ = self->dragged_;
        func_ov005_021579ec(self, self->state_, self->slot_);
        GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
        self->unknown_3de0_ = (self->slot_ - 8) + self->page_ * 16;
        self->unknown_3dc0_ = 0;
        self->flags_ |= 0x80;
        SePlayer_Play((SePlayer*)&g_sePlayer, 2, 0);
        screen->flags_ &= ~1;
        screen->flags_ &= ~0x80;
        self->flags_ &= ~4;
        self->flags_ &= ~8;
        return;
    }
    self->dragged_ = -1;
    self->unknown_3dc0_ = -1;
}
