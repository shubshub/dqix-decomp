#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0200b454 func_0200b318
#endif

struct SePlayer;
struct Vec3copy0202ec84;
struct Field150Holder02052df8;

struct Struct_ov005_0215690c_2 {
    char unknown_0_[0x50];
    Vector3fix unknown_50_;
};

struct Struct_ov005_02153ba4_2 {
#if defined(jpn)
    char unknown_0_[0x4f8];
#else
    char unknown1_0_[0x4fc];
#endif
    int unknown_4fc_;
#if defined(jpn)
    char unknown1_4fc_[0x56c - 0x4fc];
#else
    char unknown_500_[0x634 - 0x500];
#endif
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
#if defined(jpn)
    char unknown_0_[0x196c];
#else
    char unknown1_0_[0x19f4];
#endif
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[0x3d78 - 0x3030];
    short unknown_3d78_;
    char unknown_3d7a_[0x3d98 - 0x3d7a];
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
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
    char unknown_3dd0_[0x3dfc - 0x3dd0];
    unsigned char unknown_3dfc_[8];
};

#if defined(jpn)
#define data_ov005_0215cc84 data_ov005_0215e064
#define data_ov005_0215cc14 data_ov005_0215dff4
#define data_ov005_0215cd58 data_ov005_0215e138
#define data_ov005_0215cd50 data_ov005_0215e130
#endif

extern const Vector3fix data_ov005_0215cc84[8];
extern const signed char data_ov005_0215cc14[8];
extern unsigned char data_ov005_0215cd58[8];
extern unsigned char data_ov005_0215cd50[8];
extern int g_sePlayer;

extern "C" Struct_ov005_02153ba4_2* func_ov017_021a193c(int* arg0);
extern "C" int func_ov005_02157ae8(Struct_ov005_02153954* arg0, int arg1);
struct Struct_ov005_0215690c;
extern "C" Struct_ov005_0215690c_2* func_ov023_021e4e20(Struct_ov005_0215690c*);
extern "C" int func_ov005_02155670(Struct_ov005_02153954* arg0, int arg1, int arg2);
extern "C" int func_0202ec84(void* arg0, Struct_02015ef4* arg1, int* arg2, int* arg3);
extern "C" GameObject* func_0200ff1c(GameState* arg0, int arg1);
extern "C" double func_0200b454(double x);
short GetHalfwordEntryFromField150(Field150Holder02052df8* obj, int index);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
void* GetPtrField0x2a04_02010828(GameState* gs);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);
void SePlayer_Play(SePlayer* obj, int a, int b);

// USA: func_ov005_0215690c
extern "C" ARM void func_ov005_0215690c(Struct_ov005_02153954* arg0, int arg1, int arg2) {
    GameState* var0;
    Struct_ov005_0215690c_2* var1;
    var0 = GameState::GetInstance();
    unsigned char var2;
    Struct_ov005_02153ba4_2* var3 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
    unsigned int var4 = var3->unknown_4fc_;
    if (!func_ov005_02157ae8(arg0, var4))
        return;
    var1 = func_ov023_021e4e20((Struct_ov005_0215690c*)var3);
    func_ov005_02155670(arg0, arg1, arg2);
    short var5 = -1;
    unsigned char var6 = 0xff;
    if (arg1 > 0 && arg1 < 0x80) {
        int var7[8];
        void* var8;
        int var9;
        int var10[8];
        var8 = func_020100bc(var0);
        int var11;
        Matrix4x3 var12;
        Vector3fix var13[8];
        var12 = RotationMatrixY(var1->unknown_50_.y);
        for (int var14 = 0; var14 < 8; var14++) {
            Mat4x3_ApplyToVector(&data_ov005_0215cc84[var14], &var12, &var13[var14]);
            func_0202ec84(var8, (Struct_02015ef4*)&var13[var14], &var7[var14], &var10[var14]);
        }
        GameObject* var15 = func_0200ff1c(var0, var4);
        var11 = 0;
        float var16[8];
        int var17[8];
        for (int var18 = 0; var18 < 8; var18++) {
            var16[var18] = 20.0f;
            int var19 = arg2 - var10[var18];
            int var20 = arg1 - var7[var18];
            if ((float)func_0200b454(var20 * var20 + var19 * var19) < var16[var18])
                var17[var11++] = var18;
        }
        if (var11 > 0) {
            int var21 = 0;
            int var22 = 0;
            int var23[8];
            for (int var24 = 0; var24 < var11; var24++) {
                int var25 = var17[var24];
                if (func_02052df8((Struct_02052df8*)var15, data_ov005_0215cc14[var25]) > 0) {
                    var23[var21] = var25;
                    var22 = 1;
                    var21++;
                }
            }
            if (var22) {
                int var26 = var23[0];
                int var27 = var13[var26].z;
                for (int var28 = 1; var28 < var21; var28++) {
                    int var29 = var23[var28];
                    if (var27 < var13[var29].z) {
                        var26 = var29;
                        var27 = var13[var29].z;
                    }
                }
                var6 = data_ov005_0215cd58[var26];
                var5 = func_02052df8((Struct_02052df8*)var15, data_ov005_0215cc14[var26]);
            } else {
                int var30 = var17[0];
                int var31 = var13[var30].z;
                for (int var32 = 1; var32 < var11; var32++) {
                    int var33 = var17[var32];
                    if (var31 < var13[var33].z) {
                        var30 = var33;
                        var31 = var13[var33].z;
                    }
                }
                var6 = data_ov005_0215cd58[var30];
                if (arg0->unknown_3dbc_ != var6) {
                    func_ov005_02158560(arg0, var6, 1);
                    arg0->unknown_3dbb_ = 8;
                    func_ov005_0215792c(arg0, 4);
                    func_ov005_021579ec(arg0, arg0->unknown_3db8_, arg0->unknown_3dbb_);
                    arg0->unknown_3dcc_ |= 0x100;
                    func_ov005_021555c0(arg0);
                    return;
                }
            }
        }
    } else if (arg1 > 0x84 && arg1 < 0x9d && arg2 > 0x16 && arg2 < 0x2d) {
        var6 = arg0->unknown_3dbc_;
        var5 = arg0->unknown_2d90_[var6].unknown_0_;
    }
    if (var5 <= 0)
        return;
    int var34 = 0;
    if (arg0->unknown_3dbc_ != var6) {
        var34 = 1;
        func_ov005_02158560(arg0, var6, 1);
        arg0->unknown_3dcc_ |= 0x100;
    }
    short* var35 = func_0207c5f8((unsigned char*)func_02010828(var0) + 0x1d4, data_ov005_0215cd50[arg0->unknown_3dbc_]);
    int var36 = -1;
    int var37 = -1;
    for (short var38 = 0; var38 < arg0->unknown_3d98_[arg0->unknown_3dbc_]; var38++) {
        short var39 = var35[var38];
        if (var5 == var39) {
            var37 = var38;
            break;
        }
        if (var36 < 0 && var39 == -1)
            var36 = var38;
    }
    if (var37 < 0)
        var37 = var36;
    var2 = var37 / 16;
    if (arg0->unknown_3dbd_ != var2) {
        arg0->unknown_3dbf_ = arg0->unknown_3dbd_;
        arg0->unknown_3dbd_ = var2;
        var34 = 1;
        arg0->unknown_3dfc_[arg0->unknown_3dbc_] = arg0->unknown_3dbd_;
    }
    if (var34) {
        func_ov005_021555c0(arg0);
        arg0->unknown_3dcc_ |= 0x40;
        arg0->unknown_3daa_ = 0;
    }
    func_ov005_0215792c(self, 3);
    self->dragged_ = self->kind_;
    self->slot_ = self->dragged_;
    GridCursor_SetSelectedIndex(self->cursor_, self->dragged_);
    self->unk_3dc0 = 1;
    self->flags_ |= 0x80;
    SePlayer_Play((SePlayer*)&g_sePlayer, 2, 0);
    screen->flags_ &= ~1;
    screen->flags_ &= ~0x80;
    self->flags_ &= ~4;
    self->flags_ &= ~8;
}
