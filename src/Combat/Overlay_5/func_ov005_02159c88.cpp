#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct Struct_ov005_02153ba4_2 {
    char unknown_0_[REGION(0x4f8,0x4fc)];
    int unknown_4fc_;
};

extern "C" long labs(long);
struct Dst02157174;
struct Src02157174;
void CopyThreeFields02157174(Dst02157174*, Src02157174*);
struct StructAt020473c8;
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern "C" void func_02047554(void* obj, int val, int param1);
struct ItemTable;
void* ItemTable_Find(ItemTable*, int);
MemberScreen* GetField1c_021a193c(int* p);
extern "C" int func_020dd4c4(char a, void* b);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_02159c88 { int unknown_0_; int unknown_4_; int unknown_8_; };

struct Struct_ov005_02159c88_2 {
    char unknown_0_[0x1c];
    Struct_ov005_02159c88 unknown_1c_;
    char unknown_28_[0x80 - 0x28];
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[4];
};

struct Struct_ov005_02159c88_3 {
    short unknown_0_;
    char unknown_2_[6];
    Struct_ov005_02159c88_2* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_[2];
};

struct Struct_ov005_02159c88_4 {
    char unknown_0_[0xdf4];
    void* unknown_df4_;
    char unknown_df8_[REGION(0x19ac,0x1a34) - 0xdf8];
    char unknown_1a34_;
    char unknown_1a35_[0x2c80 - 0x1a35];
    char unknown_2c80_[0x80];
    short unknown_2d00_;
    char unknown_2d02_[0x2d08 - 0x2d02];
    char unknown_2d08_[0x80];
    short unknown_2d88_;
    char unknown_2d8a_[0x2d90 - 0x2d8a];
    Struct_ov005_02159c88_3 unknown_2d90_[0x18];
    Struct_ov005_02159c88_2 unknown_3030_[24];
    Struct_ov005_02159c88_2 unknown_3cf0_;
    short unknown_3d78_;
    char unknown_3d7a_[0x3da8 - 0x3d7a];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    char unknown_3daa_[1];
    unsigned char unknown_3dab_;
    char unknown_3dac_[0x3db8 - 0x3dac];
    unsigned char unknown_3db8_;
    char unknown_3db9_[2];
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
};

// USA: func_ov005_02159c88
extern "C" ARM void func_ov005_02159c88(Struct_ov005_02159c88_4* arg0) {
    for (int var0 = 0; var0 < 0x1f; var0++) {
        for (int var1 = 0; var1 < 0x18; var1++) {
            Struct_ov005_02159c88_3* var2 = &arg0->unknown_2d90_[var1];
            int var3, var4, var5, var6, var7, var8;
            Struct_ov005_02159c88_2* var9;
            var9 = var2->unknown_8_;
            if (var1 != arg0->unknown_3d78_ && var2->unknown_0_ >= 0) {
                var5 = var9->unknown_1c_.unknown_0_;
                var3 = var2->unknown_c_;
                var4 = var2->unknown_10_;
                var6 = var9->unknown_1c_.unknown_4_;
                var7 = var3 - var5;
                var8 = var4 - var6;
                if (var7 != 0 || var8 != 0) {
                    Struct_ov005_02159c88 var10;
                    var10.unknown_0_ = (int)((float)var5 + 0.01f * (float)var7);
                    var10.unknown_4_ = (int)((float)var6 + 0.01f * (float)var8);
                    var10.unknown_8_ = 0;
                    if (labs(var3 - var10.unknown_0_) < 0x800 && labs(var4 - var10.unknown_4_) < 0x800) {
                        var10.unknown_0_ = var3;
                        var10.unknown_4_ = var4;
                        var10.unknown_8_ = 0;
                    }
                    func_ov005_02157174((Struct_ov005_02156ecc*)var9, (Struct_ov005_02156ecc_2*)&var10);
                }
            }
        }
    }
    for (int var11 = 0; var11 < 24; var11++) {
        if (arg0->unknown_3030_[var11].unknown_82_ < 0x1f)
            arg0->unknown_3030_[var11].unknown_82_++;
    }
    if (arg0->unknown_3d78_ >= 0 && arg0->unknown_3cf0_.unknown_82_ < 0x1f)
        arg0->unknown_3cf0_.unknown_82_ = arg0->unknown_3cf0_.unknown_82_ + 1;
    if (arg0->unknown_3db8_ == 0) {
        for (int var12 = 0; var12 < 8; var12++) {
            Struct_ov005_02159c88_3* var13 = &arg0->unknown_2d90_[var12];
            if (var12 != arg0->unknown_3d78_ && var13->unknown_0_ >= 0) {
                Struct_ov005_02159c88_2* var14 = var13->unknown_8_;
                Struct_ov005_02159c88 var15 = var14->unknown_1c_;
                var15.unknown_4_ = (var12 * 0x18) << 12;
                func_ov005_02157174((Struct_ov005_02156ecc*)var14, (Struct_ov005_02156ecc_2*)&var15);
                G3_MTX_PUSH = 0;
                func_020473c8((Struct_02015ef4_2*)var14, 1);
                G3_MTX_POP = 1;
                if (arg0->unknown_3da8_ == 0 && arg0->unknown_3da9_ == 0) {
                    int var16 = var15.unknown_0_ + REGION(0x11000,0x8000);
                    int var17 = var15.unknown_4_ + REGION(0x10000,0x8000);
                    int var18 = var15.unknown_8_ + 0x1000;
                    G3_MTX_PUSH = 0;
                    G3_MTX_TRANS = var16;
                    G3_MTX_TRANS = var17;
                    G3_MTX_TRANS = var18;
                    arg0->unknown_2d88_ = 0xf0a;
                    func_02047554(arg0->unknown_2d08_, 0, 1);
                    G3_MTX_POP = 1;
                }
            }
        }
    } else {
        for (int var19 = 0; var19 < 0x18; var19++) {
            Struct_ov005_02159c88_3* var20 = &arg0->unknown_2d90_[var19];
            int var21 = arg0->unknown_3dbb_;
            if (var19 == var21 && var21 >= 8 && var21 < 0x18) {
                int var22 = var20->unknown_c_;
                int var23 = var20->unknown_10_;
                Struct_ov005_02159c88 var24 = var20->unknown_8_->unknown_1c_;
                G3_MTX_PUSH = 0;
                G3_MTX_TRANS = var22;
                G3_MTX_TRANS = var23;
                G3_MTX_TRANS = var24.unknown_8_ - 0x1000;
                arg0->unknown_2d00_ = 0x25f;
                func_020473c8((Struct_02015ef4_2*)arg0->unknown_2c80_, 1);
                G3_MTX_POP = 1;
            }
            int id = s->id;
            if (id >= 0) {
                void* elem = ItemTable_Find((ItemTable*)self->container, (short)id);
                if (elem != 0) {
                    Obj02159c88* o = s->obj;
                    GameResources* res = GetGameResources();
                    MemberScreen* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_3700[2]);
                    if (func_020dd4c4(holder->member, elem) != 0) {
                        int px = s->x;
                        int py = s->y;
                        Vec3_02159c88 p = o->pos;
                        if (i >= 8 && i < 0x18) {
                            G3_MTX_PUSH = 0;
                            G3_MTX_TRANS = var30;
                            G3_MTX_TRANS = var31;
                            G3_MTX_TRANS = var32.unknown_8_ - 0x1000;
                            arg0->unknown_2d00_ = 0x1ce7;
                            func_020473c8((Struct_02015ef4_2*)arg0->unknown_2c80_, 1);
                            G3_MTX_POP = 1;
                        }
                        var27->unknown_80_ = 0x3def;
                    } else {
                        var27->unknown_80_ = 0x7fff;
                    }
                }
                if (var19 != arg0->unknown_3d78_) {
                    Struct_ov005_02159c88_2* var33 = var20->unknown_8_;
                    if (var19 == arg0->unknown_3dbc_ || var19 >= 8) {
                        G3_MTX_PUSH = 0;
                        func_020473c8((Struct_02015ef4_2*)var33, 1);
                        G3_MTX_POP = 1;
                        if (var19 < 8) {
                            if (arg0->unknown_3da8_ == 0 && arg0->unknown_3da9_ == 0) {
                                Struct_ov005_02159c88 var34 = var33->unknown_1c_;
                                G3_MTX_PUSH = 0;
                                G3_MTX_TRANS = var34.unknown_0_ + REGION(0x11000,0x8000);
                                G3_MTX_TRANS = var34.unknown_4_ + REGION(0x10000,0x8000);
                                G3_MTX_TRANS = var34.unknown_8_ + 0x1000;
                                arg0->unknown_2d88_ = 0xf0a;
                                func_02047554(arg0->unknown_2d08_, 0, 1);
                                G3_MTX_POP = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (arg0->unknown_3d78_ >= 0 && arg0->unknown_3dab_ == 0) {
        G3_MTX_PUSH = 0;
        func_020473c8((Struct_02015ef4_2*)&arg0->unknown_3cf0_, 1);
        G3_MTX_POP = 1;
        Struct_ov005_02159c88 var35 = arg0->unknown_3cf0_.unknown_1c_;
        func_ov005_02154d18(&arg0->unknown_1a34_, var35.unknown_0_, var35.unknown_4_);
        func_ov005_02154d34(&arg0->unknown_1a34_, var35.unknown_0_, var35.unknown_4_);
        func_ov005_02154d50(&arg0->unknown_1a34_, 0x18000, 0x18000);
        func_ov005_02154d7c(&arg0->unknown_1a34_, 0x18000, 0x18000);
        if (arg0->unknown_3d78_ < 8 && arg0->unknown_3dab_ == 0) {
            Struct_ov005_02159c88 var36 = arg0->unknown_3cf0_.unknown_1c_;
            G3_MTX_PUSH = 0;
            G3_MTX_TRANS = var36.unknown_0_ + REGION(0x11000,0x8000);
            G3_MTX_TRANS = var36.unknown_4_ + REGION(0x10000,0x8000);
            G3_MTX_TRANS = var36.unknown_8_ + 0x1000;
            arg0->unknown_2d88_ = 0xf0a;
            func_02047554(arg0->unknown_2d08_, 0, 1);
            G3_MTX_POP = 1;
        }
    }
}
