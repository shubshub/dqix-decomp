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

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[Enum_ov005_021567ac_1276];
    int unknown_4fc_;
    char unknown_500_[Enum_ov005_021567ac_1588 - Enum_ov005_021567ac_1276 - 4];
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
    char unknown_0_[Enum_ov005_021567ac_6644];
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3d78 - 0x3030];
    short unknown_3d78_;
    char unknown_3d7a_[0x3db8 - 0x3d7a];
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
    char unknown_3dd0_[0x3de0 - 0x3dd0];
    short unknown_3de0_;
};

extern int g_sePlayer;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
MemberScreen* GetField1c_021a193c(int* p);
void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);

// USA: func_ov005_021567ac
extern "C" ARM void func_ov005_021567ac(Struct_ov005_02153954* arg0, int arg1, int arg2) {
    GameState::GetInstance();
    MemberScreen* screen = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    if (!func_ov005_02157ae8(self, screen->member_))
        return;
    arg0->unknown_3d78_ = func_ov005_02155670(arg0, arg1, arg2);
    if (arg0->unknown_3d78_ >= 8 && arg0->unknown_3d78_ < 24) {
        if (arg0->unknown_2d90_[arg0->unknown_3d78_].unknown_0_ == -1) {
            arg0->unknown_3d78_ = -1;
            arg0->unknown_3dc0_ = -1;
            return;
        }
        func_ov005_0215792c(self, 4);
        self->slot_ = self->dragged_;
        func_ov005_021579ec(self, self->state_, self->slot_);
        GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
        self->swapped_ = (self->slot_ - 8) + self->page_ * 16;
        self->unk_3dc0 = 0;
        self->flags_ |= 0x80;
        SePlayer_Play((SePlayer*)&g_sePlayer, 2, 0);
        screen->flags_ &= ~1;
        screen->flags_ &= ~0x80;
        self->flags_ &= ~4;
        self->flags_ &= ~8;
        return;
    }
    arg0->unknown_3d78_ = -1;
    arg0->unknown_3dc0_ = -1;
}
