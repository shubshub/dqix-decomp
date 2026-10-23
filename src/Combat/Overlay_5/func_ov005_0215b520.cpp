#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020c51a4 func_020c6c70
#endif

#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov005_0215cbec data_ov005_0215dfcc
#define data_ov005_0215cbdc data_ov005_0215dfbc
#else
#define REGION(j,u) (u)
#endif

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[REGION(0x4f8,0x4fc)];
    int unknown_4fc_;
};

extern "C" void func_020c51a4(int arg0);

struct Struct_02000c9c_91;
struct Struct_0204b8d0 {
    char unknown_0_[0x10];
    Struct_02000c9c_91* unknown_10_;
    unsigned short* unknown_14_;
    char unknown_18_[5];
    unsigned char unknown_1d_;
};
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct Obj0204b010;
void Background_ClearMap(struct Obj0204b010* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void func_02047554(void* obj, int val, int param1);
extern "C" void func_ov005_0215792c(void* obj, unsigned char mode);
extern "C" void func_ov005_021579ec(void* obj, unsigned int a, unsigned char b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
MemberScreen* GetField1c_021a193c(int* p);
struct GameState;
struct Struct_02052e14;
extern "C" short* func_02052e14(Struct_02052e14*);

extern const unsigned char data_ov005_0215cbec[];
extern const unsigned char data_ov005_0215cbdc[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_0215b520 {
    char unknown_0_[0x88];
};

struct Struct_0201099c_10;
struct Struct_0201099c_9;
struct Struct_ov003_02178910 {
    char unknown_0_[0x48];
    Struct_0201099c_10* unknown_48_;
    Struct_0201099c_9* unknown_4c_;
    char unknown_50_[REGION(0x680,0x704)];
    int unknown_754_;
    char unknown_758_[0x18];
    short unknown_770_;
    unsigned short unknown_772_;
    unsigned short unknown_774_;
    unsigned char unknown_776_;
};
struct Struct_ov005_02153ba4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    Struct_ov005_0215b520* unknown_8_;
    int unknown_c_, unknown_10_, unknown_14_;
    short unknown_18_;
};
extern "C" void func_ov023_021dcba4(void*, short);

struct Struct_ov005_0215b520_2 {
    char unknown_0_[REGION(0xea0,0xea4)];
    Struct_0204b8d0 unknown_ea4_;
    char unknown_ec4_[0x1244 - 0xec4];
    Struct_ov003_02178910 unknown_1244_;
    char unknown_19bc_[REGION(0x19ac - 0x1240,0x1a34 - 0x1244) - sizeof(Struct_ov003_02178910)];
    char unknown_1a34_[0x3c];
    Struct_ov005_0215b520 unknown_1a70_[36];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    Struct_ov005_0215b520 unknown_3030_[24];
    Struct_ov005_0215b520 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[0x3db8 - 0x3d7a];
    unsigned char unknown_3db8_;
    char unknown_3db9_;
    unsigned char unknown_3dba_;
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    char unknown_3dbd_[0x3dcc - 0x3dbd];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3de2 - 0x3dd0];
    short unknown_3de2_;
    int unknown_3de4_;
    int unknown_3de8_;
    int unknown_3dec_;
};

// USA: func_ov005_0215b520
extern "C" ARM void func_ov005_0215b520(Struct_ov005_0215b520_2* arg0) {
    unsigned char var0 = arg0->unknown_3dba_;
    if (var0 == 0 && arg0->unknown_3dec_ == 0) {
        func_ov005_0215792c(arg0, 1);
        arg0->unknown_3dcc_ |= 0x100;
        void* var1 = (void*)GameState::GetInstance();
        GameResources* var2 = GetGameResources();
        Struct_ov005_02153ba4_2* var3 = func_ov017_021a193c((int*)var2->unknown_ptr_array_36fc[3]);
        short* var4 = func_02052e14((Struct_02052e14*)func_0200ff1c((GameState*)var1, var3->unknown_4fc_));
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 0x29;
            if (arg0->unknown_3de2_ >= 0x7b) {
                arg0->unknown_3de2_ = 0x7b;
                arg0->unknown_3dec_ = 1;
            }
        }
        if (arg0->unknown_3db8_ == 1) {
            for (int var5 = 0; var5 < 8; var5++) {
                int var6 = 0;
                if (var5 == arg0->unknown_3dbc_) var6 = 1;
                int var7 = var6 * 11;
                int var8 = (var5 * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x7f) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                func_02047554(&arg0->unknown_1a70_[var7 + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x100) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 var9;
                var9 = RotationMatrixY(0x3244);
                func_020c51a4((int)&var9);
                func_02047554(&arg0->unknown_1a70_[var7 + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x70) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&arg0->unknown_1a70_[var7 + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* var10 = &arg0->unknown_1a70_[var7 + 7 + var5];
                if (var4[data_ov005_0215cbec[var5]] > 0) {
                    var10 = &arg0->unknown_1a70_[var7 + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (arg0->unknown_3de2_ + 0x85) << 12;
                G3_MTX_TRANS = var8;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(var10, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (arg0->unknown_3dec_ == 1) {
            arg0->unknown_3dba_++;
            arg0->unknown_3de2_ = 0;
            arg0->unknown_3de8_ = 0;
            arg0->unknown_3dec_ = 0;
        }
    } else if (var0 == 1 && arg0->unknown_3dec_ == 0) {
        arg0->unknown_3dcc_ |= 0x100;
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 6;
            if (arg0->unknown_3de2_ >= 0x10) {
                arg0->unknown_3de2_ = 0x10;
                arg0->unknown_3dec_ = 1;
            }
        }
        Background_ClearMap((struct Obj0204b010*)&self->list, 0);
        Background_DrawScreen(&self->list, 0, 0, 0, 0x20 - self->level, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        Background_DrawScreen(&self->list, (unsigned char)(cursor + 1), 0, 0, y + 0x10 - self->level, 0, 4, 3, 0xffff);
        Background_FlushMap(&self->list, 0);
        if (self->phase == 1) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (var0 == 2 && arg0->unknown_3dec_ == 1) {
        func_ov005_0215792c(arg0, 3);
        arg0->unknown_3dcc_ |= 0x100;
        func_ov005_021579ec(arg0, arg0->unknown_3db8_, arg0->unknown_3dbb_);
        func_ov005_02154d34(arg0->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d7c(arg0->unknown_1a34_, 0x76000, 0x16000);
        arg0->unknown_3dcc_ |= 0x800;
    } else if (var0 == 0 && arg0->unknown_3dec_ == 1) {
        arg0->unknown_3dcc_ |= 0x800;
        func_ov005_0215792c(arg0, 1);
        arg0->unknown_3dcc_ |= 0x100;
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 6;
            if (arg0->unknown_3de2_ >= 0x10) {
                arg0->unknown_3de2_ = 0x10;
                arg0->unknown_3dec_ = 2;
            }
        }
        Background_ClearMap((struct Obj0204b010*)&self->list, 0);
        Background_DrawScreen(&self->list, 0, 0, 0, self->level + 0x10, 0, 0x10, 0x16, 0xffff);
        unsigned char cursor = self->cursor;
        short y = cursor * 2 + 0xf;
        Background_DrawScreen(&self->list, (unsigned char)(cursor + 1), 0, 0, y + self->level, 0, 4, 3, 0xffff);
        Background_FlushMap(&self->list, 0);
        if (self->phase == 2) {
            self->state++;
            self->level = 0;
            self->accum = 0;
        }
    } else if (var0 == 1 && arg0->unknown_3dec_ == 2) {
        void* var15 = (void*)GameState::GetInstance();
        GameResources* var16 = GetGameResources();
        Struct_ov005_02153ba4_2* var17 = func_ov017_021a193c((int*)var16->unknown_ptr_array_36fc[3]);
        short* var18 = func_02052e14((Struct_02052e14*)func_0200ff1c((GameState*)var15, var17->unknown_4fc_));
        arg0->unknown_3de8_ += arg0->unknown_3de4_;
        if (arg0->unknown_3de8_ >= 3) {
            arg0->unknown_3de8_ -= 3;
            arg0->unknown_3de2_ += 0x29;
            if (arg0->unknown_3de2_ >= 0x7b) {
                arg0->unknown_3de2_ = 0x7b;
                arg0->unknown_3dec_ = 1;
            }
        }
        if (arg0->unknown_3db8_ == 1) {
            for (int var19 = 0; var19 < 8; var19++) {
                int var20 = 0;
                if (var19 == arg0->unknown_3dbc_) var20 = 1;
                int var21 = var20 * 11;
                int var22 = (var19 * 0x18) << 12;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xfa - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                func_02047554(&arg0->unknown_1a70_[var21 + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x17b - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                Matrix4x3 var23;
                var23 = RotationMatrixY(0x3244);
                func_020c51a4((int)&var23);
                func_02047554(&arg0->unknown_1a70_[var21 + 4], 0, 1);
                G3_MTX_POP = 1;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0xeb - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x200000;
                G3_MTX_SCALE = 0x14000;
                G3_MTX_SCALE = 0x1000;
                G3_MTX_SCALE = 0x1000;
                func_02047554(&arg0->unknown_1a70_[var21 + 5], 0, 1);
                G3_MTX_POP = 1;
                Struct_ov005_0215b520* var24 = &arg0->unknown_1a70_[var21 + 7 + var19];
                if (var18[data_ov005_0215cbdc[var19]] > 0) {
                    var24 = &arg0->unknown_1a70_[var21 + 6];
                }
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = (0x100 - arg0->unknown_3de2_) << 12;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = -0x1ff000;
                func_02047554(var24, 0, 1);
                G3_MTX_POP = 1;
            }
        }
        if (arg0->unknown_3dec_ == 1) {
            arg0->unknown_3dba_ = 0;
            arg0->unknown_3de2_ = 0;
            arg0->unknown_3de8_ = 0;
            arg0->unknown_3dec_ = 0;
            func_ov005_0215792c(arg0, 0);
            arg0->unknown_3dcc_ |= 0x100;
        }
    }
#if defined(jpn)
    func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3]);
    short var25 = arg0->unknown_2d90_[arg0->unknown_3dbb_].unknown_0_;
    arg0->unknown_1244_.unknown_774_ |= 0x80;
    func_ov023_021dcba4(&arg0->unknown_1244_, var25);
#endif

}
