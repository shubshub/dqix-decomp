#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_ov002_021665b0_3 {
    int unknown_0_;
    unsigned short unknown_4_;
    short unknown_6_;
};

struct Struct_ov002_021665b0_5 {
    char unknown_0_[0x30];
    unsigned short unknown_30_;
};

struct Struct_ov002_021665b0_7 {
#if defined(jpn)
    char unknown_0_[0x8b8];
#else
    char unknown1_0_[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov002_021665b0_8 {
    char unknown_0_[0x130];
    Struct_ov002_021665b0_3* unknown_130_;
    Struct_ov002_021665b0_5* unknown_134_;
#if defined(jpn)
    char unknown_138_[0x144 - 0x138];
#else
    char unknown1_138_[0x150 - 0x138];
#endif
    Struct_ov002_021665b0_7* unknown_150_;
};

struct Struct_ov002_021665b0_9 {
    char unknown_0_[0x78];
    unsigned int : 30;
    unsigned int unknown_7b_6_ : 1;
    unsigned int : 1;
};

struct Struct_ov002_021665b0_10 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int : 6;
    unsigned int unknown_9_6_ : 8;
    unsigned int : 10;
};

struct Struct_ov002_021665b0_11 {
    short unknown_0_;
    short unknown_2_;
};

struct Struct_ov002_021665b0 {
    signed char unknown_0_;
    signed char unknown_1_;
};

struct Struct_ov002_021665b0_2 {
#if defined(jpn)
    char unknown_0_[0x1a80];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    char unknown_1a8c_[0x1ae8 - 0x1a8c];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    char unknown_1aea_[0x1aee - 0x1aea];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char unknown_1af4_[0x1b14 - 0x1af4];
#else
    char unknown1_0_[0x1bb8];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    char unknown_1bc4_[0x1c20 - 0x1bc4];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    char unknown_1c22_[0x1c26 - 0x1c22];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char unknown_1c2c_[0x1c50 - 0x1c2c];
#endif
    int unknown_1c50_;
    int unknown_1c54_[12];
    char unknown_1c84_[2];
    short unknown_1c86_[4];
    short unknown_1c8e_[4];
    Struct_ov002_021665b0_11 unknown_1c96_[5];
    short unknown_1caa_;
    signed char unknown_1cac_;
    signed char unknown_1cad_;
    signed char unknown_1cae_;
    signed char unknown_1caf_;
    signed char unknown_1cb0_;
    unsigned char unknown_1cb1_;
    Struct_ov002_021665b0 unknown_1cb2_[4];
    signed char unknown_1cba_[4];
    unsigned char unknown_1cbe_[4];
};

struct Struct_ov002_021665b0_4 {
    unsigned short unknown_0_;
    signed char unknown_2_;
    signed char unknown_3_;
    signed char unknown_4_;
    char unknown_5_[0x3c - 5];
};

struct Struct_ov002_021665b0_6 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

void InitStateArray02157ce0(char*);
extern "C" void func_ov002_0215b814(Menu_021665b0* self);
Unit_021665b0* GetCombatantChecked_0200ff94(GameState* gs, int id);
Field_021665b0* GetFieldAt0x150_02053c6c(unsigned char*);
int GetBitInArray0x910_02083bc0(unsigned char*, int);
extern "C" int func_0209ac28(char* obj, Unit_021665b0* unit, int index);
Elem_021665b0* SearchBothTables02079e2c(char*, int);
struct Struct02048448;
int ClampAndCompareThreshold02048448(Struct02048448*, int);
extern "C" void __clear(void* dst, int size);
extern "C" void func_ov002_021536e0(char** obj);
void* LookupElementByKey02079ee0(void*, int);
extern "C" short func_ov002_021538e4(char** obj, Elem_021665b0* elem, void* sub, int target);
extern "C" void func_ov002_021594e8(Menu_021665b0* self, int key, int target, int actor);
char* GetGlobalField0x1c020421a0(void);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(char* obj);
int CheckFlagOrThreshold_02161b48(char*, int);
void ReinitController02043204(char* ctl);
struct Struct_0205def8;
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" void func_ov016_0218b5c0(int arg0, int arg1);
extern "C" void func_ov017_0218b5f8(int arg0);

#if defined(jpn)
#define SPELLS_021665b0 0x227c
#define LIST_021665b0 0xe20
#define CTL_FLAG_021665b0 0x17fb
#define NEXT_IDLE_021665b0 0x18
#define NEXT_BACK_021665b0 0x16
#define NEXT_MENU_021665b0 0x2e
#define FLAG_KEY_021665b0 0x2c
#define NEXT_NONE_021665b0 0x29
#else
#define SPELLS_021665b0 0x2444
#define LIST_021665b0 0xec8
#define CTL_FLAG_021665b0 0x19ca
#define NEXT_IDLE_021665b0 0x17
#define NEXT_BACK_021665b0 0x15
#define NEXT_MENU_021665b0 0x2b
#define FLAG_KEY_021665b0 0x29
#define NEXT_NONE_021665b0 0x26
#endif

// USA: func_ov002_021665b0
extern "C" ARM void func_ov002_021665b0(Struct_ov002_021665b0_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov002_021665b0_4 var1;
    Struct_ov002_021665b0_9* var2;
    Struct_ov002_021665b0_8* var3;
    func_ov002_02157ce0((char*)&var1);
    Struct_02108e10* var4 = func_020797dc();
    signed char var5 = arg0->unknown_1c50_ - 1;
    short* var6 = arg0->unknown_1c86_;
    short* var7 = arg0->unknown_1c8e_;
    signed char* var8 = arg0->unknown_1cba_;
    unsigned char* var9 = arg0->unknown_1cbe_;
    signed char var10 = arg0->unknown_1cae_;
    Struct_ov002_021665b0_8* var11;

    if (var10 == 0) {
        unsigned short var12[4];
        int var13;
        func_ov002_0215b814(arg0);
        arg0->unknown_1cb1_ = 0;
        arg0->unknown_1cae_ = 1;
        arg0->unknown_1c28_ = -1;
        arg0->unknown_1c2a_ = -1;
        for (int var14 = 0; var14 < 4; var14++) {
            var6[var14] = 0;
            var7[var14] = 0;
            var9[var14] = 0;
            var8[var14] = 0;
            arg0->unknown_1cb2_[var14].unknown_0_ = -1;
            var12[var14] = 0;
            arg0->unknown_1cb2_[var14].unknown_1_ = -1;
        }
        memset(arg0->unknown_1c96_, -1, sizeof(arg0->unknown_1c96_));
        int var15 = 0;
        for (int var16 = 0; var16 < var5; var16++) {
            var13 = arg0->unknown_1c54_[var16];
            var3 = func_0200ff94(var0, var13);
            if (var3 == NULL) {
                continue;
            }
            var11 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var13);
            if (var11 == NULL) {
                continue;
            }
            var2 = func_02053c6c((unsigned char*)var11);
            if (var2 == NULL) {
                continue;
            }
            var6[var13] = var11->unknown_134_->unknown_30_;
            var7[var13] = var11->unknown_130_->unknown_4_;
            var12[var13] = var6[var13] - var7[var13];
            if (var3->unknown_130_->unknown_0_ & 2) {
                var9[var13] = 1;
            }
            if (var3->unknown_130_->unknown_0_ & 1) {
                continue;
            }
            for (int var17 = 0x1a; var17 < 0x1f; var17++) {
                if (func_02083bc0((unsigned char*)var2, var17) && func_0209ac28((char*)arg0 + SPELLS_021665b0, var11, var17)) {
                    if (var11->unknown_130_->unknown_6_ >= 2) {
                        var8[var13]++;
                    }
                }
            }
        }
        int var18 = 0;
        for (int var19 = 0; var19 < var5; var19++) {
            var13 = arg0->unknown_1c54_[var19];
            if ((Struct_ov002_021665b0_8*)func_0200ff1c(var0, var13) == NULL) {
                continue;
            }
            var3 = func_0200ff94(var0, var13);
            if (var3 == NULL) {
                continue;
            }
            if (var3->unknown_130_->unknown_0_ & 1) {
                continue;
            }
            if (var12[var13] != 0) {
                for (int var20 = 0; var20 < var5; var20++) {
                    int var21 = arg0->unknown_1c54_[var20];
                    if ((Struct_ov002_021665b0_8*)func_0200ff1c(var0, var21) != NULL && var7[var21] > 0 && var8[var21] > 0) {
                        var18 = 1;
                        break;
                    }
                }
            }
            if (var9[var13] != 0) {
                for (int var22 = 0; var22 < var5; var22++) {
                    int var23 = arg0->unknown_1c54_[var22];
                    Struct_ov002_021665b0_8* var24 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var23);
                    if (var24 == NULL) {
                        continue;
                    }
                    Struct_ov002_021665b0_9* var25 = func_02053c6c((unsigned char*)var24);
                    if (var25 == NULL) {
                        continue;
                    }
                    if (var7[var23] <= 0) {
                        continue;
                    }
                    if (!func_02083bc0((unsigned char*)var25, 0x20)) {
                        continue;
                    }
                    Struct_ov002_021665b0_8* var26 = func_0200ff94(var0, var23);
                    if (func_02048448((Struct_02048448_2*)var26, (unsigned short)func_02079e2c((char*)var4, (short)0x23)->unknown_8_0_)) {
                        var18 = 1;
                        break;
                    }
                }
            }
            if (var18) {
                break;
            }
        }
        if (var18) {
            var15 = 1;
        }
        if (!var15) {
            arg0->unknown_1cae_ = 5;
            arg0->unknown_1caf_ = 2;
        }
    } else if (var10 == 1) {
        Struct_ov002_021665b0_6 var27[4];
        Struct_ov002_021665b0_6 var28[4];
        arg0->unknown_1cae_ = 2;
        __clear(var27, sizeof(var27));
        __clear(var28, sizeof(var28));
        Struct_ov002_021665b0_6* var29;
        for (int var30 = 0; var30 < var5; var30++) {
            int var31 = arg0->unknown_1c54_[var30];
            var29 = &var27[var30];
            var29->unknown_2_ = var31;
            Struct_ov002_021665b0_8* var32 = func_0200ff94(var0, var31);
            if (var32 == NULL) {
                continue;
            }
            var11 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var31);
            if (var11 == NULL) {
                continue;
            }
            var2 = func_02053c6c((unsigned char*)var11);
            if (var2 == NULL) {
                continue;
            }
            unsigned char var33 = var11->unknown_150_->unknown_950_;
            if (var32->unknown_130_->unknown_0_ & 1) {
                continue;
            }
            int var34 = 0;
            switch (var33) {
            case 2:
                var29->unknown_0_ += 10;
                break;
            case 10:
                var29->unknown_0_ += 8;
                break;
            case 6:
            case 9:
            case 11:
                var29->unknown_0_ += 5;
                break;
            case 5:
            case 12:
                var29->unknown_0_ += 3;
                break;
            default:
                var34 = 1;
                break;
            }
            if (var34) {
                continue;
            }
            if ((unsigned short)var2->unknown_7b_6_) {
                var29->unknown_0_ += 5;
            }
            var29->unknown_0_ = var29->unknown_0_ + var8[var31] * 4;
            if (func_02083bc0((unsigned char*)var2, 0x1f)) {
                if (func_0209ac28((char*)arg0 + SPELLS_021665b0, var11, 0x1f)) {
                    var29->unknown_0_ += 200;
                }
            } else if (func_02083bc0((unsigned char*)var2, 0x1e)) {
                if (func_0209ac28((char*)arg0 + SPELLS_021665b0, var11, 0x1e)) {
                    var29->unknown_0_ += 100;
                }
            }
        }
        for (int var35 = 0; var35 < 4; var35++) {
            for (int var36 = 3; var36 > var35; var36--) {
                unsigned short var37 = var27[var36 - 1].unknown_0_;
                unsigned short var38 = var27[var36].unknown_0_;
                if (var38 > var37) {
                    unsigned char var39 = var27[var36].unknown_2_;
                    var27[var36].unknown_0_ = var37;
                    var27[var36].unknown_2_ = var27[var36 - 1].unknown_2_;
                    var27[var36 - 1].unknown_0_ = var38;
                    var27[var36 - 1].unknown_2_ = var39;
                }
            }
        }
        for (int var40 = 0; var40 < 4; var40++) {
            if (var27[var40].unknown_0_ == 0) {
                break;
            }
            unsigned char var41 = var27[var40].unknown_2_;
            arg0->unknown_1cb2_[var40].unknown_0_ = var41;
            arg0->unknown_1cb2_[var40].unknown_1_ = var8[var41];
        }
    } else if (var10 == 2) {
        arg0->unknown_1cae_ = 3;
        for (int var42 = 0; var42 < 5; var42++) {
            arg0->unknown_1c96_[var42].unknown_0_ = -1;
            arg0->unknown_1c96_[var42].unknown_2_ = -1;
        }
        func_ov002_02157ce0((char*)&var1);
        var1.unknown_4_ = arg0->unknown_1c54_[arg0->unknown_1cb0_];
        var1.unknown_2_ = arg0->unknown_1cb2_[arg0->unknown_1cac_].unknown_0_;
        arg0->unknown_1c20_ = arg0->unknown_1cb2_[arg0->unknown_1cac_].unknown_0_;
        int var43 = 0;
        if (var1.unknown_2_ >= 0 && var1.unknown_2_ <= 3) {
            var43 = 1;
        }
        if (!var43) {
            arg0->unknown_1cae_ = 2;
            arg0->unknown_1cac_ = arg0->unknown_1cac_ + 1;
            if (var5 <= arg0->unknown_1cac_) {
                arg0->unknown_1cae_ = 5;
                arg0->unknown_1caf_ = 1;
                arg0->unknown_1c28_ = -1;
            }
            return;
        }
        Struct_ov002_021665b0_8* var44 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var1.unknown_2_);
        if (var44->unknown_130_->unknown_0_ & 1) {
            arg0->unknown_1cae_ = 2;
            arg0->unknown_1cac_ = arg0->unknown_1cac_ + 1;
            if (var5 <= arg0->unknown_1cac_) {
                arg0->unknown_1cae_ = 5;
                arg0->unknown_1caf_ = 2;
                arg0->unknown_1c28_ = -1;
            }
            return;
        }
        char* var45;
        func_ov002_021536e0(&var45);
        var45 = (char*)var4;
        int var46;
        int var47;
        for (var47 = 0, var46 = 0x1a; var47 < 5; var47++, var46++) {
            arg0->unknown_1c96_[var47].unknown_0_ = 0;
            arg0->unknown_1c96_[var47].unknown_2_ = 0;
            if (!func_02083bc0((unsigned char*)(func_02053c6c((unsigned char*)var44)), var46)) {
                continue;
            }
            if (!func_0209ac28((char*)arg0 + SPELLS_021665b0, var44, var46)) {
                continue;
            }
            if (var44->unknown_130_->unknown_6_ < 2) {
                continue;
            }
            var1.unknown_0_ = var47 + 0x1e;
            Struct_ov002_021665b0_10* var48 = func_02079e2c((char*)var4, (short)var1.unknown_0_);
            void* var49 = func_02079ee0((char*)var4, var48->unknown_9_6_);
            arg0->unknown_1c96_[var47].unknown_0_ = func_ov002_021538e4(&var45, var48, var49, var1.unknown_2_);
            arg0->unknown_1c96_[var47].unknown_2_ = var1.unknown_0_;
        }
    } else if (var10 == 3) {
        arg0->unknown_1cae_ = 4;
        arg0->unknown_1c28_ = -1;
        arg0->unknown_1c2a_ = -1;
        arg0->unknown_1caa_ = 0x1e;
        short var50;
        short var51;
        unsigned char var52;
        int var53;
        int var54;
        int var55 = arg0->unknown_1c54_[arg0->unknown_1cb0_];
        arg0->unknown_1c21_ = var55;
        for (int var56 = 0; var56 < var5; var56++) {
            signed char var57 = arg0->unknown_1c54_[var56];
            Struct_ov002_021665b0_8* var58 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var57);
            if (var58 != NULL) {
                var7[var57] = var58->unknown_130_->unknown_4_;
            }
        }
        var54 = (unsigned short)(var6[var55] - var7[var55]);
        int var59 = 0;
        unsigned char var60 = 0;
        if (var9[var55] == 1) {
            while (var60 < var5) {
                Struct_ov002_021665b0_8* var61 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, arg0->unknown_1cb2_[var60].unknown_0_);
                if (var61 == NULL) {
                    var60++;
                    continue;
                }
                Struct_ov002_021665b0_9* var62 = func_02053c6c((unsigned char*)var61);
                if (var62 == NULL) {
                    var60++;
                    continue;
                }
                if (func_0200ff94(var0, arg0->unknown_1cb2_[var60].unknown_0_)->unknown_130_->unknown_0_ & 1) {
                    var60++;
                    continue;
                }
                if (func_02083bc0((unsigned char*)var62, 0x20)) {
                    if (!func_0209ac28((char*)arg0 + SPELLS_021665b0, var61, 0x20)) {
                        var60++;
                        continue;
                    }
                    var1.unknown_0_ = 0x23;
                    Struct_ov002_021665b0_10* var63 = func_02079e2c((char*)var4, (short)var1.unknown_0_);
                    Struct_ov002_021665b0_8* var64 = func_0200ff94(var0, arg0->unknown_1cb2_[var60].unknown_0_);
                    if (!func_02048448((Struct_02048448_2*)var64, (unsigned short)var63->unknown_8_0_)) {
                        var60++;
                        continue;
                    }
                    arg0->unknown_1caa_ = var1.unknown_0_;
                    var59 = 1;
                    arg0->unknown_1cb1_ = 1;
                    break;
                }
                var60++;
            }
        }
        if (var59) {
            arg0->unknown_1cad_ = var60;
            func_ov002_021594e8(arg0, arg0->unknown_1caa_, arg0->unknown_1cb2_[var60].unknown_0_, var55);
            Struct_ov002_021665b0_8* var65 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var55);
            Struct_ov002_021665b0_8* var66 = func_0200ff94(var0, var55);
            var7[var55] = var65->unknown_130_->unknown_4_;
            if (!(var66->unknown_130_->unknown_0_ & 2)) {
                var9[var55] = 0;
            }
            arg0->unknown_1cae_ = 6;
            return;
        }
        var53 = arg0->unknown_1cb2_[arg0->unknown_1cac_].unknown_0_;
        signed char var67 = arg0->unknown_1cb2_[arg0->unknown_1cac_].unknown_1_;
        arg0->unknown_1c20_ = var53;
        Struct_ov002_021665b0_8* var68 = func_0200ff94(var0, var55);
        if (var67 == 0) {
            arg0->unknown_1cac_ = arg0->unknown_1cac_ + 1;
            arg0->unknown_1cae_ = 2;
            if (var5 <= arg0->unknown_1cac_) {
                arg0->unknown_1cae_ = 5;
                if (arg0->unknown_1cb1_ == 0) {
                    arg0->unknown_1caf_ = 2;
                }
            }
            return;
        }
        if (var68->unknown_130_->unknown_0_ & 1) {
            arg0->unknown_1cae_ = 2;
            arg0->unknown_1cb0_ = arg0->unknown_1cb0_ + 1;
            if (var5 <= arg0->unknown_1cb0_) {
                arg0->unknown_1cae_ = 5;
                if (arg0->unknown_1cb1_ == 0) {
                    arg0->unknown_1caf_ = 2;
                }
            }
            return;
        }
        if (var9[var55] == 1 && var5 <= arg0->unknown_1cb0_) {
            arg0->unknown_1cae_ = 5;
            if (arg0->unknown_1cb1_ == 0) {
                arg0->unknown_1caf_ = 2;
            }
            return;
        }
        if (var54 == 0) {
            arg0->unknown_1cae_ = 2;
            arg0->unknown_1cb0_ = arg0->unknown_1cb0_ + 1;
            if (var5 <= arg0->unknown_1cb0_) {
                arg0->unknown_1cae_ = 5;
                if (arg0->unknown_1cb1_ == 0) {
                    arg0->unknown_1caf_ = 2;
                }
            }
            return;
        }
        Struct_ov002_021665b0_8* var69 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var53);
        if (func_02083bc0((unsigned char*)(func_02053c6c((unsigned char*)var69)), 0x1e) && arg0->unknown_1c96_[4].unknown_2_ > 0) {
            var1.unknown_0_ = 0x22;
            if (func_02048448((Struct_02048448_2*)var69, (unsigned short)func_02079e2c((char*)var4, (short)0x22)->unknown_8_0_)) {
                var50 = arg0->unknown_1c96_[0].unknown_0_;
                short var70 = arg0->unknown_1c96_[1].unknown_0_;
                var51 = arg0->unknown_1c96_[2].unknown_0_;
                short var71 = arg0->unknown_1c96_[4].unknown_0_;
                int var72 = arg0->unknown_1c96_[3].unknown_2_;
                signed char var73 = 0;
                signed char var74 = 0;
                signed char var75 = 0;
                for (unsigned char var76 = 0; var76 < var5; var76++) {
                    signed char var77 = arg0->unknown_1c54_[var76];
                    short var78 = var7[var77];
                    if (var78 <= 0) {
                        continue;
                    }
                    unsigned short var79 = var6[var77] - var78;
                    if (var79 == 0) {
                        continue;
                    }
                    if (var79 < var70) {
                        continue;
                    }
                    if (var70 >= var71) {
                        continue;
                    }
                    if (var50 < var79) {
                        var73++;
                    }
                    if (var70 < var79) {
                        var74++;
                    }
                    if (var51 <= 0) {
                        continue;
                    }
                    if (var79 < var71 * 2) {
                        var75++;
                    }
                }
                if (var72 > 0) {
                    for (unsigned char var80 = 0; var80 < var5; var80++) {
                        signed char var81 = arg0->unknown_1c54_[var80];
                        short var82 = var7[var81];
                        if (var82 <= 0) {
                            continue;
                        }
                        unsigned short var83 = var6[var81] - var82;
                        if (var83 == 0) {
                            continue;
                        }
                        if (var71 * 6 >= var83) {
                            continue;
                        }
                        var73--;
                        var74--;
                        var75--;
                    }
                }
                if (var73 == 4 || var74 >= 4 || var75 >= 4) {
                    arg0->unknown_1caa_ = 0x22;
                    var59 = 1;
                }
            }
        }
        if (var59) {
            func_ov002_021594e8(arg0, arg0->unknown_1caa_ = 0x22, var53, 0);
            for (int var84 = 0; var84 < var5; var84++) {
                unsigned char var85 = arg0->unknown_1c54_[var84];
                Struct_ov002_021665b0_8* var86 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var85);
                if (var86 != NULL) {
                    var7[var85] = var86->unknown_130_->unknown_4_;
                }
            }
            arg0->unknown_1cae_ = 6;
            return;
        }
        if (var54 <= arg0->unknown_1c96_[0].unknown_0_) {
            if (!var59) {
                var59 = 1;
                arg0->unknown_1caa_ = arg0->unknown_1c96_[0].unknown_2_;
            }
        }
        if (!var59) {
            if (var54 < arg0->unknown_1c96_[1].unknown_0_) {
                var59 = 1;
                arg0->unknown_1caa_ = arg0->unknown_1c96_[1].unknown_2_;
            }
        }
        if (!var59) {
            if (var54 < arg0->unknown_1c96_[1].unknown_0_ * 2) {
                var59 = 1;
                arg0->unknown_1caa_ = arg0->unknown_1c96_[1].unknown_2_;
            } else if (var54 < arg0->unknown_1c96_[2].unknown_0_) {
                var59 = 1;
                arg0->unknown_1caa_ = arg0->unknown_1c96_[2].unknown_2_;
            }
        }
        if (!var59) {
            if (var54 < arg0->unknown_1c96_[2].unknown_0_ * 3) {
                var59 = 1;
                arg0->unknown_1caa_ = arg0->unknown_1c96_[2].unknown_2_;
            } else if (arg0->unknown_1c96_[3].unknown_2_ != 0) {
                arg0->unknown_1caa_ = arg0->unknown_1c96_[3].unknown_2_;
                var59 = 1;
            }
        }
        if (!var59 && arg0->unknown_1c96_[0].unknown_2_ != 0) {
            for (int var87 = 3; var87 >= 0; var87--) {
                if (arg0->unknown_1c96_[var87].unknown_0_ != 0) {
                    arg0->unknown_1caa_ = arg0->unknown_1c96_[var87].unknown_2_;
                    break;
                }
            }
        }
        var52 = 0;
        while (!var52) {
            Struct_ov002_021665b0_10* var88 = func_02079e2c((char*)var4, (short)arg0->unknown_1caa_);
            Struct_ov002_021665b0_8* var89 = func_0200ff94(var0, var53);
            if (var89 == NULL || var88 == NULL) {
                continue;
            }
            if (func_02048448((Struct_02048448_2*)var89, (unsigned short)var88->unknown_8_0_) == 0) {
                arg0->unknown_1caa_--;
                if (arg0->unknown_1caa_ < 0x1e) {
                    arg0->unknown_1cac_++;
                    arg0->unknown_1cae_ = 2;
                    if (var5 <= arg0->unknown_1cac_) {
                        arg0->unknown_1cae_ = 5;
                        arg0->unknown_1caf_ = 1;
                        arg0->unknown_1c28_ = -1;
                    }
                    var52 = 1;
                }
            } else {
                var52 = 1;
            }
        }
    } else if (var10 == 4) {
        int var90 = arg0->unknown_1c54_[arg0->unknown_1cb0_];
        func_ov002_021594e8(arg0, arg0->unknown_1caa_, arg0->unknown_1cb2_[arg0->unknown_1cac_].unknown_0_, var90);
        Struct_ov002_021665b0_8* var91 = (Struct_ov002_021665b0_8*)func_0200ff1c(var0, var90);
        Struct_ov002_021665b0_8* var92 = func_0200ff94(var0, var90);
        var7[var90] = var91->unknown_130_->unknown_4_;
        if (!(var92->unknown_130_->unknown_0_ & 2)) {
            var9[var90] = 0;
        }
        arg0->unknown_1cb1_ = 1;
        arg0->unknown_1cae_ = 6;
    } else if (var10 == 5) {
        int var93 = 0;
        arg0->unknown_1cac_ = 0;
        arg0->unknown_1cb0_ = 0;
        arg0->unknown_1c26_ = -1;
        arg0->unknown_1bb8_ = NEXT_IDLE_021665b0;
        arg0->unknown_1bbc_ = NEXT_IDLE_021665b0;
        arg0->unknown_1bc0_ = var93;
        char* var94 = func_020421a0();
        if (arg0->unknown_1cb1_ == 0 && arg0->unknown_1caf_ == 1) {
            arg0->unknown_1caf_ = 2;
        }
        signed char result = self->result;
        if (!(result != 0 && result != 1)) {
            ctl[CTL_FLAG_021665b0] = 0;
            int pressed = g_keyManager.TestKeysPressed(0x601);
            int cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)((char*)self + LIST_021665b0), 0x14)) ? 1 : 0;
            int single = func_0205d97c((char*)self + LIST_021665b0) == 1 ? 1 : 0;
            int flagged = CheckFlagOrThreshold_02161b48((char*)self, 1);
            int left = g_keyManager.TestKeysPressed(0xf0);
            if (single | (flagged | (cancel | (left | g_keyManager.TestKeysPressed(0x100))))) {
                ReinitController02043204(ctl);
                self->nextA = NEXT_BACK_021665b0;
                self->nextB = NEXT_MENU_021665b0;
                SetElementFlag0x20ByKey0205def8((Struct_0205def8*)((char*)self + LIST_021665b0), 1, FLAG_KEY_021665b0);
                self->result = 0;
                self->sel28 = -1;
                self->sel2a = -1;
                self->state = 0;
                self->acted = 0;
                changed = 1;
            } else if (g_keyManager.TestKeysPressed(0x800)) {
                func_02043204(var94);
                arg0->unknown_1bb8_ = NEXT_MENU_021665b0;
                arg0->unknown_1bbc_ = NEXT_MENU_021665b0;
                arg0->unknown_1caf_ = 0;
                arg0->unknown_1c28_ = -1;
                arg0->unknown_1c2a_ = -1;
                arg0->unknown_1cae_ = 0;
                arg0->unknown_1cb1_ = 0;
                var93 = 1;
            }
        } else if (var95 == 2) {
            arg0->unknown_1c28_ = 0x232b;
            arg0->unknown_1bb8_ = NEXT_NONE_021665b0;
            arg0->unknown_1bbc_ = NEXT_IDLE_021665b0;
            arg0->unknown_1caf_ = 4;
            var93 = 1;
        }
        if (var93) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
    } else if (var10 == 6) {
        arg0->unknown_1cae_ = 3;
        signed char var101 = arg0->unknown_1cb0_;
        int var102 = arg0->unknown_1c54_[var101];
        if (var7[var102] == var6[var102] && var9[var102] == 0) {
            arg0->unknown_1cb0_ = var101 + 1;
            arg0->unknown_1cac_ = 0;
            arg0->unknown_1cae_ = 2;
            if (var5 <= arg0->unknown_1cb0_) {
                arg0->unknown_1cae_ = 5;
            }
        }
    }
}
