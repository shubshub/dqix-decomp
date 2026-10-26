#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd48 data_ov005_0215e128
#define func_ov013_02185990 func_ov013_02186b88
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct Struct_ov005_02156ecc;
struct Struct_ov005_02156ecc_2;

struct MemberScreen {
    char unk_0[R(0x4f8,0x4fc)];
    int member_;
    char unknown_500_[R(0x56c - 0x4fc,0x634 - 0x500)];
    unsigned short flags_;
};

struct MenuModel {
    char unk_0[0x1c];
    Vector3fix position_;
    char unk_28[0x80 - 0x28];
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[4];
};

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c,0x19f4)];
    char cursor_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
    short dragged_;
    char unknown_3d7a_[0x3daa - 0x3d7a];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
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

extern unsigned char data_ov005_0215cd48[8];

extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" void func_ov005_02157174(Struct_ov005_02156ecc* dst, Struct_ov005_02156ecc_2* src);
extern "C" void EquipMenu_EquipItem(EquipmentMenu* self, int item, int keep);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" short* func_0207c5f8(unsigned char* obj, unsigned int index);
extern "C" signed char* func_0207c60c(void* obj, unsigned int index);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

// USA: func_ov005_02156ecc
extern "C" ARM void func_ov005_02156ecc(EquipmentMenu* self, int x, int y) {
    if (self->dragged_ < 0)
        return;
    GameState::GetInstance();
    MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    Vector3fix position = self->dragModel_.position_;
    MenuModel* model = self->slots_[self->dragged_].model_;
    position.z = 0;
    func_ov005_02157174((Struct_ov005_02156ecc*)model, (Struct_ov005_02156ecc_2*)&position);
    model->unknown_82_ = 0;
    if (self->dragged_ >= 0 && self->dragged_ < 8)
        model->unknown_82_ = 0x1f;
    if (x < 0x80) {
        if (self->unknown_3dc0_ == 0)
            EquipMenu_EquipItem(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x15 && y < 0x2e) {
        if (x > 0x83 && self->unknown_3dc0_ == 0)
            EquipMenu_EquipItem(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x30 && self->unknown_3dc0_ == 1) {
        EquipMenu_EquipItem(self, 0xffff, 0);
    }
    if (self->unknown_3dc0_ == 0) {
        int slot = func_ov005_02155670(self, x, y);
        if (slot >= 8 && slot < 24 && self->slot_ != slot) {
            short index = (slot - 8) + self->page_ * 16;
            char* party = (char*)GameState_GetParty(GameState::GetInstance());
            short* items = func_0207c5f8((unsigned char*)party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            signed char* counts = func_0207c60c(party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            short swapped = self->unknown_3de0_;
            short item = items[swapped];
            signed char count = counts[swapped];
            items[swapped] = items[index];
            counts[self->unknown_3de0_] = counts[index];
            items[index] = item;
            counts[index] = count;
            func_ov005_021555c0(self);
            self->flags_ |= 0x40;
            self->unknown_3daa_ = 0;
            self->unknown_3de0_ = -1;
            self->slot_ = slot;
        }
    }
    func_ov005_021579ec(self, self->state_, self->slot_);
    GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
    screen->flags_ |= 0x1 | 0x80;
    self->flags_ |= 0x4 | 0x8;
}
