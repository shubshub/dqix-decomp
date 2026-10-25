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

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[R(0x4f8,0x4fc)];
    int unknown_4fc_;
    char unknown_500_[R(0x56c - 0x4fc,0x634 - 0x500)];
    unsigned short unknown_634_;
};

struct Struct_ov005_02155d6c_2 {
    char unknown_0_[0x1c];
    Vector3fix unknown_1c_;
    char unknown_28_[0x80 - 0x28];
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[4];
};

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    Struct_ov005_02155d6c_2* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    short unknown_18_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0x196c,0x19f4)];
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    Struct_ov005_02155d6c_2 unknown_3030_[24];
    Struct_ov005_02155d6c_2 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[0x3daa - 0x3d7a];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
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

extern unsigned char data_ov005_0215cd48[8];

MemberScreen* GetField1c_021a193c(int* p);
void CopyThreeFields02157174(Dst02157174* dst, Src02157174* src);
extern "C" void EquipMenu_EquipItem(EquipmentMenu* self, int item, int keep);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
void* GameState_GetParty(GameState* gs);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index);
signed char* GetPointerAt0xbf0_0207c60c(void* obj, unsigned int index);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

// USA: func_ov005_02156ecc
extern "C" ARM void func_ov005_02156ecc(Struct_ov005_02153954* arg0, int arg1, int arg2) {
    if (arg0->unknown_3d78_ < 0)
        return;
    GameState::GetInstance();
    MemberScreen* screen = GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    Vector3fix position = self->dragModel_.position_;
    MenuModel* model = self->slots_[self->dragged_].model_;
    position.z = 0;
    CopyThreeFields02157174((Dst02157174*)model, (Src02157174*)&position);
    model->unk_82 = 0;
    if (self->dragged_ >= 0 && self->dragged_ < 8)
        model->unk_82 = 0x1f;
    if (x < 0x80) {
        if (self->unk_3dc0 == 0)
            EquipMenu_EquipItem(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x15 && y < 0x2e) {
        if (x > 0x83 && self->unk_3dc0 == 0)
            EquipMenu_EquipItem(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x30 && self->unk_3dc0 == 1) {
        EquipMenu_EquipItem(self, 0xffff, 0);
    }
    if (self->unk_3dc0 == 0) {
        int slot = func_ov005_02155670(self, x, y);
        if (slot >= 8 && slot < 24 && self->slot_ != slot) {
            short index = (slot - 8) + self->page_ * 16;
            char* party = (char*)GameState_GetParty(GameState::GetInstance());
            short* items = GetPointerFromArray0xbd0_0207c5f8((unsigned char*)party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            signed char* counts = GetPointerAt0xbf0_0207c60c(party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            short swapped = self->swapped_;
            short item = items[swapped];
            signed char count = counts[swapped];
            items[swapped] = items[index];
            counts[self->swapped_] = counts[index];
            items[index] = item;
            counts[index] = count;
            func_ov005_021555c0(self);
            self->flags_ |= 0x40;
            self->pageStep_ = 0;
            self->swapped_ = -1;
            self->slot_ = slot;
        }
    }
    func_ov005_021579ec(self, self->state_, self->slot_);
    GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
    screen->flags_ |= 0x1 | 0x80;
    self->flags_ |= 0x4 | 0x8;
}
