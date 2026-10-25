#if defined(jpn)
#define data_ov000_02183674 data_ov000_02184730
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct_0203c1c8  {
#if defined(jpn)
    char unknown_0_[0x14];
#endif
    int unknown1_0_;
    int unknown_4_;
#if defined(jpn)
    char unknown_1c_[8];
#endif
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    short unknown_14_;
#if defined(jpn)
    char unknown_32_[0x38 - 0x32];
#endif
};
struct Struct_ov000_02180ca8_4  {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[6];
    unsigned char unknown_22_;
    char unknown_23_[3];
    unsigned char unknown_26_;
    char unknown_27_;
};
struct Struct_ov000_02180ca8_5  {
    int unknown_0_[3];
    short unknown_c_;
    char unknown_e_[2];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[3];
    signed char unknown_1c_;
    signed char unknown_1d_;
    char unknown_1e_[6];
    unsigned char unknown_24_;
    char unknown_25_[9];
    signed char unknown_2e_;
    char unknown_2f_[0x44 - 0x2f];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char unknown_87_;
#if defined(jpn)
    char unknown_c8_[0x483 - 0xc8];
#else
    char unknown_88_[0x443 - 0x88];
#endif
    signed char unknown_443_;
    char unknown_444_[4];
};
struct Struct_ov000_02180ca8  {
    char unknown_0_[0x3b];
    unsigned char : 3;
    unsigned char unknown_3b_3_ : 1;
    unsigned char : 4;
};
struct Struct_ov000_02180ca8_2  {
    char unknown_0_[0x138];
    Struct_ov000_02180ca8* unknown_138_;
};
struct BackgroundGraphics;
struct Obj0204b878;
struct State02180ca8  {
    char padding0[0x11c];
    char display[0x54];
    DisplayEntry02180ca8* displayEntries;
    char padding174[0x8c4 - 0x174];
    char entryList[0x930 - 0x8c4];
    char padding930[0x940 - 0x930];
    int xOffset;
    int yOffset;
    char padding948[8];
    int selected;
    unsigned char mode;
#if defined(jpn)
    char unknown_955_[0x1b64 - 0x955];
#else
    char unknown1_955_[0x1b0c - 0x955];
#endif
    Struct_0203c1c8 unknown_1b0c_[3];
    Struct_0203c1c8 unknown_1b54_;
    Struct_0203c1c8 unknown_1b6c_;
#if defined(jpn)
    char unknown_1c7c_[0x1d94 - 0x1c7c];
#else
    char unknown_1b84_[0x1c5c - 0x1b84];
#endif
    Struct_0203c1c8 unknown_1c5c_[8];
    int unknown_1d1c_[16];
    unsigned char unknown_1d5c_;
};
extern "C" int func_ov000_0217fe30(State02180ca8*);
extern "C" void SpriteContext_DrawSprite(void*, void*);
int HasAnyFlags_021719f8_021719f8(int*);
int GetHPCategory02174e34(int, int);
Struct0203c1c8* GetSlotSubField0x68_ov000_02174e1c(void*, int);
extern "C" int func_ov000_02171ffc(Action02180ca8*);
#if defined(jpn)
extern "C" void func_0203c1c8(Struct_0203c1c8*, int);
#else
extern "C" void func_0203c1c8(Struct_0203c1c8*);
#endif
void* Background_GetScreen(BackgroundGraphics*, unsigned int);
void CallFunc0204b620IfField0x14_0204b878(Obj0204b878*, int, int, int, short, short, short, short, unsigned short);
extern const int data_ov000_02183674[11];
static inline int inline_ov000_02180ca8(int arg0)  { return arg0 >= 0 && arg0 <= 3; }
// USA: func_ov000_02180ca8
extern "C" ARM void func_ov000_02180ca8(Struct_ov000_02180ca8_3* arg0, Struct_ov000_02180ca8_5* arg1, Struct_0204b878* arg2)  {
    if (!arg1)  {
        return;
    }
    int var0 = 0;
    int var1 = 0;
    if (arg1->unknown_24_ & 8)  {
        var1 = arg0->unknown_944_;
        var0 = arg0->unknown_940_;
    }
    int var2 = arg1->unknown_44_;
    int var3 = arg1->unknown_48_;
    int var4;
    int var5;
    int var6;
    int var7 = arg1->unknown_4c_;
    var4 = var2 >> 3;
    var5 = var3 >> 3;
    GameObject* var8 = func_0200ff1c(GameState::GetInstance(), var7);
    if (func_ov000_0217fe30(arg0) && var8 && arg1->unknown_c_ && ((Struct_ov000_02180ca8_2*)var8)->unknown_138_->unknown_3b_3_)  {
        Struct_ov000_02180ca8_4* var9 = &arg0->unknown_170_[30];
        var9->unknown_14_ = 0;
        var9->unknown_18_ = (var3 + 7) << 12;
#if defined(jpn)
        var9->unknown_22_ = arg1->unknown_4c_ + 0x40;
#else
        var9->unknown_22_ = arg1->unknown_4c_ + 0x44;
#endif
        display->active = 0;
        SpriteContext_DrawSprite(self->display, display);
    }
    signed char var10 = arg1->unknown_10_[arg1->unknown_18_];
    if (var10 == 0x67)  {
        return;
    }
    if (var10 >= 0x64)  {
        if (var10 != 0x66 && func_ov000_0217fe30(arg0) && arg1->unknown_c_)  {
            Struct_ov000_02180ca8_4* var11 = &arg0->unknown_170_[6];
            var11->unknown_14_ = 0xe0000;
            var11->unknown_18_ = (var3 + 7) << 12;
#if defined(jpn)
            var11->unknown_22_ = arg1->unknown_4c_ + 0x78;
#else
            var11->unknown_22_ = arg1->unknown_4c_;
#endif
            display->active = 1;
            SpriteContext_DrawSprite(self->display, display);
        }
        if (arg1->unknown_1c_ == 6 || arg1->unknown_c_ == 0 || func_ov000_021719f8(arg1->unknown_0_) || arg1->unknown_1c_ == 2 || arg1->unknown_443_ != 5)  {
            return;
        }
        int var12;
        Struct_0203c1c8* var13;
        int var14;
        var14 = arg1->unknown_1d_;
        var12 = arg1->unknown_2e_;
        var6 = 3;
        if (arg1->unknown_10_[arg1->unknown_18_] != 0x66)  {
            var6 = 0;
            int var15 = func_ov000_02174e34((int)arg0, var12);
            if (var15 != -1)  {
                var6 = var15;
            }
        }
        var13 = 0;
        if (var14 >= 0 && var14 < arg0->unknown_1d5c_)  {
            var13 = &arg0->unknown_1c5c_[var14];
        }
        if (inline_ov000_02180ca8(var12))  {
            var13 = func_ov000_02174e1c(arg0, var12);
        }
        switch (func_ov000_02171ffc(arg1))  {
            case 3:
            var13 = &arg0->unknown_1b6c_;
            break;
            case 4:             if (inline_ov000_02180ca8(var12))  {
                var13 = &arg0->unknown_1b6c_;
            }
#if !defined(jpn)
            else  {
                Struct_0203c1c8* var16 = arg0->unknown_1b0c_;
                int var17 = arg0->unknown_1d1c_[0];
                for (int var18 = 1; var18 < var14 + 1; ++var18)  {
                    int var19 = arg0->unknown_1d1c_[var18];
                    if (var17 != var19)  {
                        ++var16;
                    }
                    var17 = var19;
                }
                int var20 = 0;
                for (int var21 = 0; var21 < arg0->unknown_1d5c_; ++var21)  {
                    if (var17 == arg0->unknown_1d1c_[var21])  {
                        ++var20;
                    }
                }
                if (var20 > 1)  {
                    var13 = var16;
                }
            }
#endif
            break;
            case 2:
            break;
            default:
            break;
        }
        if (!var13)  {
            return;
        }
        int var22[2];
        int var23[2];
        int var24[2];
        var22[0] = var2 + 0xb3 + var0;
        var22[1] = var2 + 0xb4 + var0;
        var23[0] = var3 + 0x17 + var1;
        var23[1] = var3 + 0x17 + var1;
        var24[1] = data_ov000_02183674[8];
        var24[0] = var6;
        int* var25 = var24;
#if defined(jpn)
        for (int var26 = 0; var26 < 2; ++var26)  {
#else
        for (int var26 = 0; var26 < 1; ++var26)  {
#endif
            int var27 = var25[var26];
            int var28 = var22[var26];
            var13->unknown_8_ = var27;
            var13->unknown_c_ = 2;
            var13->unknown1_0_ = var28;
            var13->unknown_4_ = var23[var26];
#if defined(jpn)
            func_0203c1c8(var13, 0xa);
#else
            func_0203c1c8(var13);
#endif
            var13->unknown_10_ = 1;
        }
        entry->category = 0;
        void* selectedEntry = Background_GetScreen((BackgroundGraphics*)self->entryList, 3);
        CallFunc0204b620IfField0x14_0204b878(list, (int)selectedEntry, 0, 0,
#if defined(jpn)
            var4 + 16,
#else
            var4 + 15,
#endif
            var5 + 2, 0x20, 0x19, var7 + 2);
    }
    else  {
        Struct_0203c1c8* var30 = &arg0->unknown_1b54_;
        if (func_ov000_021719f8(arg1->unknown_0_) || arg1->unknown_87_)  {
            return;
        }
        if (arg0->unknown_950_ == 0 && arg0->unknown_954_ == 2)  {
            return;
        }
        int var31[2] =  {
            var2 + 0xb3, var2 + 0xb4
        };
        int var32[2] =  {
            var3 + 15, var3 + 15
        };
        int var33[2] =  {
            data_ov000_02183674[9], data_ov000_02183674[10]
        };
        var30->unknown_c_ = 2;
        int* var34;
        int* var35;
        int* var36;
#if defined(jpn)
        var36 = var33;
        int var37 = 0;
        var35 = var31;
        var34 = var32;
        for (; var37 < 2; ++var37)  {
#else
        var36 = var33;
        var35 = var31;
        var34 = var32;
        for (int var37 = 1; var37 < 2; ++var37)  {
#endif
            var30->unknown1_0_ = var35[var37];
            var30->unknown_4_ = var34[var37];
#if defined(jpn)
            func_0203c1c8(var30, 0xa);
#else
            func_0203c1c8(var30);
#endif
            var30->unknown_8_ = var36[var37];
            var30->unknown_10_ = 1;
        }
    }
}
