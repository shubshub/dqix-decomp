#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd48 data_ov005_0215e128
#define func_ov005_02157b74 func_ov005_0215916c
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
extern "C" void func_ov005_02157b74(EquipmentMenu* self, int item, int keep);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
void* GetPtrField0x2a04_02010828(GameState* gs);
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
    Struct_ov005_02153ba4_2* var0 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
    Vector3fix var1 = arg0->unknown_3cf0_.unknown_1c_;
    Struct_ov005_02155d6c_2* var2 = arg0->unknown_2d90_[arg0->unknown_3d78_].unknown_8_;
    var1.z = 0;
    func_ov005_02157174((Struct_ov005_02156ecc*)var2, (Struct_ov005_02156ecc_2*)&var1);
    var2->unknown_82_ = 0;
    if (arg0->unknown_3d78_ >= 0 && arg0->unknown_3d78_ < 8)
        var2->unknown_82_ = 0x1f;
    if (arg1 < 0x80) {
        if (arg0->unknown_3dc0_ == 0)
            func_ov005_02157b74(arg0, arg0->unknown_2d90_[arg0->unknown_3d78_].unknown_0_, 0);
    } else if (arg2 > 0x15 && arg2 < 0x2e) {
        if (arg1 > 0x83 && arg0->unknown_3dc0_ == 0)
            func_ov005_02157b74(arg0, arg0->unknown_2d90_[arg0->unknown_3d78_].unknown_0_, 0);
    } else if (arg2 > 0x30 && arg0->unknown_3dc0_ == 1) {
        func_ov005_02157b74(arg0, 0xffff, 0);
    }
    if (arg0->unknown_3dc0_ == 0) {
        int var3 = func_ov005_02155670(arg0, arg1, arg2);
        if (var3 >= 8 && var3 < 24 && arg0->unknown_3dbb_ != var3) {
            short var4 = (var3 - 8) + arg0->unknown_3dbd_ * 16;
            char* var5 = (char*)func_02010828(GameState::GetInstance());
            short* var6 = func_0207c5f8((unsigned char*)var5 + 0x1d4, data_ov005_0215cd48[arg0->unknown_3dbc_]);
            signed char* var7 = func_0207c60c(var5 + 0x1d4, data_ov005_0215cd48[arg0->unknown_3dbc_]);
            short var8 = arg0->unknown_3de0_;
            short var9 = var6[var8];
            signed char var10 = var7[var8];
            var6[var8] = var6[var4];
            var7[arg0->unknown_3de0_] = var7[var4];
            var6[var4] = var9;
            var7[var4] = var10;
            func_ov005_021555c0(arg0);
            arg0->unknown_3dcc_ |= 0x40;
            arg0->unknown_3daa_ = 0;
            arg0->unknown_3de0_ = -1;
            arg0->unknown_3dbb_ = var3;
        }
    }
    func_ov005_021579ec(self, self->state_, self->slot_);
    GridCursor_SetSelectedIndex(self->cursor_, self->slot_ - 8);
    screen->flags_ |= 0x1 | 0x80;
    self->flags_ |= 0x4 | 0x8;
}
