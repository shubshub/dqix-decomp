#include <globaldefs.h>
#include "std_library_functions.h"
#include "Input/Input.h"

struct Struct_02029988_3 {
    int unknown_0_;
    char unknown_4_[0x30];
    Struct_02029988_3* unknown_34_;
    int unknown_38_;
    char unknown_3c_[4];
    int unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
};

struct Struct_02029988_2 {
    int unknown_0_;
    char unknown_4_[0x40];
    Struct_02029988_3* unknown_44_;
    char unknown_48_[8];
    short unknown_50_;
    short unknown_52_;
    short unknown_54_;
    short unknown_56_;
    short unknown_58_;
    unsigned short unknown_5a_;
    short unknown_5c_;
    short unknown_5e_;
    short unknown_60_;
    unsigned short unknown_62_;
    unsigned short unknown_64_;
    unsigned short unknown_66_;
    char unknown_68_[4];
    unsigned char unknown_6c_;
    unsigned char unknown_6d_;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    unsigned char unknown_70_;
    unsigned char unknown_71_;
    unsigned char unknown_72_;
    unsigned char unknown_73_;
    unsigned char unknown_74_;
};

struct Struct_020ef74c_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

#if defined(jpn)
#define data_020fe9a4 data_020fe6fc
#define data_020ef75c data_020ef650
#define data_020ef75f data_020ef653
#define data_020ef763 data_020ef655
#define data_020ef767 data_020ef657
#define data_020ef76b data_020ef65b
#define data_020ef76f data_020ef65f
#define data_020ef77d data_020ef66d
#define data_020ef782 data_020ef672
#endif

struct Struct_020fe9a4 {
#if !defined(jpn)
    void* unknown_0_;
#endif
    int unknown_4_;
};

struct Struct_02029634;
struct Struct_02029634_3;
struct Struct_02029988;

extern "C" void func_02029634(DebugMenu* menu, int ticks);
DebugMenuItem* DebugMenu_GetItem(IndexList_0202a9ac*, int);
void SetState0x6cAndInvoke(Callback_0202a91c*);
void DebugMenu_Open(char*, int);
void FormatAndDispatch0202ad98(int a, int b, int c, const char* fmt, ...);
void FormatAndDispatch020290e8(int a, int b, const char* fmt, ...);
void AdjustValueWrapOrClamp(WrapField_0202a678*, int);
extern "C" void DebugMenu_UpdateLayout(DebugMenu* menu);
extern "C" void* __clear(void*, int);
extern "C" int func_02029384(int, int, int, int);
extern "C" void func_02029470(int, int, int, int, int, int);
extern "C" void func_020292ec(int arg0, int arg1, int arg2, int arg3, int arg4);

extern Struct_020ef74c_2 data_020ef74c;
extern Struct_020fe9a4 data_020fe9a4;
extern const char data_020ef75c[];
extern const char data_020ef75f[];
extern const char data_020ef763[];
extern const char data_020ef767[];
extern const char data_020ef76b[];
extern const char data_020ef76f[];
extern const char data_020ef772[];
extern const char data_020ef775[];
extern const char data_020ef778[];
extern const char data_020ef77d[];
extern const char data_020ef782[];

static inline DebugMenuItem* GetItem(DebugMenu* menu, int index) {
    return DebugMenu_GetItem((IndexList_0202a9ac*)menu, index);
}

// USA: func_02029988
extern "C" ARM void func_02029988(Struct_02029988_2* arg0, int arg1) {
    int var0;
    float var1;
    int var2;
    Struct_02029988_2* var3;
    int var4;

    func_02029634(arg0, arg1);
    if (arg0->unknown_6d_ & 8) return;
    var0 = 0;
    var2 = 0;
    var4 = 0;

    if (arg0->unknown_6c_ == 0) {
        var3 = (Struct_02029988_2*)inline_02029988(arg0, arg0->unknown_60_);
        int var5;
        int var6;
        Struct_02029988_3* var7;
        int var8 = arg0->unknown_5c_;
        int var9 = arg0->unknown_5e_ - var8;
        int var10 = arg0->unknown_62_ - (arg0->unknown_5a_ - (arg0->unknown_5e_ - var8));
        var1 = (float)arg0->unknown_56_ / (float)var9;
        var0 = var1 * var10;
        var2 = arg0->unknown_50_ + arg0->unknown_54_ - 9;
        var4 = arg0->unknown_52_ + var1 * (arg0->unknown_64_ - var8);

        if (arg0->unknown_72_) {
            if (g_touchInput.pressed_) {
                int var11, var12;
                arg0->unknown_71_ = 1;
                g_touchInput.GetTouchPoint(&var11, &var12);
                if (arg0->unknown_50_ < var11 && var11 < arg0->unknown_50_ + arg0->unknown_54_ - 12 &&
                    arg0->unknown_52_ < var12 && var12 < arg0->unknown_52_ + arg0->unknown_56_) {
                    arg0->unknown_73_ = 1;
                } else if (arg0->unknown_50_ + arg0->unknown_54_ - 12 < var11 && var11 < arg0->unknown_50_ + arg0->unknown_54_ + 4 &&
                           arg0->unknown_52_ < var12 && var12 < arg0->unknown_52_ + arg0->unknown_56_) {
                    arg0->unknown_74_ = 1;
                }
            } else if (arg0->unknown_71_ && arg0->unknown_73_ && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
                int var13, var14;
                g_touchInput.GetTouchPoint(&var13, &var14);
                if (arg0->unknown_50_ < var13 && var13 < arg0->unknown_50_ + arg0->unknown_54_ - 12 &&
                    arg0->unknown_52_ < var14 && var14 < arg0->unknown_52_ + arg0->unknown_56_) {
                    int var15 = (var14 - arg0->unknown_52_) / data_020ef74c.unknown_4_ - 1;
                    if (var8 <= var15 && var15 <= var8 + var10) {
                        int var16 = arg0->unknown_64_ + (var15 - var8);
                        if (arg0->unknown_5c_ <= var16 && var16 <= arg0->unknown_5e_) {
                            arg0->unknown_60_ = var16;
                        }
                    }
                }
            } else if (arg0->unknown_71_ && arg0->unknown_74_ && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
                int var17, var18;
                g_touchInput.GetTouchPoint(&var17, &var18);
                var4 = var18 - var0 / 2;
                if (var4 < arg0->unknown_52_) {
                    var4 = arg0->unknown_52_;
                } else if (arg0->unknown_52_ + arg0->unknown_54_ < var4 + var0) {
                    var4 = arg0->unknown_52_ + arg0->unknown_56_ - var0;
                }
                arg0->unknown_64_ = var8 + (var4 - arg0->unknown_52_) / var1;
                arg0->unknown_66_ = arg0->unknown_64_ + var10;
                if (arg0->unknown_60_ < arg0->unknown_64_) arg0->unknown_60_ = arg0->unknown_64_;
                if (arg0->unknown_66_ < arg0->unknown_60_) arg0->unknown_60_ = arg0->unknown_66_;
            } else if (arg0->unknown_71_ && g_touchInput.released_) {
                int var19 = g_touchInput.prevX_;
                int var20 = g_touchInput.prevY_;
                if (arg0->unknown_73_ &&
                    arg0->unknown_50_ < var19 && var19 < arg0->unknown_50_ + arg0->unknown_54_ - 12 &&
                    arg0->unknown_52_ < var20 && var20 < arg0->unknown_52_ + arg0->unknown_56_) {
                    int var21 = (var20 - arg0->unknown_52_) / data_020ef74c.unknown_4_ - 1;
                    if (var8 <= var21 && var21 <= var8 + var10) {
                        int var22 = arg0->unknown_64_ + (var21 - var8);
                        if (arg0->unknown_5c_ <= var22 && var22 <= arg0->unknown_5e_) {
                            arg0->unknown_60_ = var22;
                            if (arg0->unknown_60_ < 0 || var3->unknown_0_ != 1) {
                                if (arg0->unknown_6d_ & 2) return;
                                func_0202a91c((Struct_02029634_3*)arg0);
                                arg0->unknown_6e_ = 1;
                                return;
                            }
                            if (cur->type != 1) return;
                            DebugMenu_Open((char*)cur, 1);
                            menu->state = 4;
                            return;
                        }
                    }
                }
                arg0->unknown_71_ = 0;
                arg0->unknown_73_ = 0;
                arg0->unknown_74_ = 0;
            }
        }

        if (arg0->unknown_66_ < arg0->unknown_60_) {
            arg0->unknown_64_ = arg0->unknown_60_ - var10;
            arg0->unknown_66_ = arg0->unknown_60_;
        } else if (arg0->unknown_60_ < arg0->unknown_64_) {
            arg0->unknown_64_ = arg0->unknown_60_;
            arg0->unknown_66_ = arg0->unknown_60_ + var10;
        }

        if (data_020ef74c.unknown_c_ == 0) {
            func_0202ad98(arg0->unknown_50_ / 8 + 1, arg0->unknown_52_ / 8 + 1, 7, arg0->unknown_4_);
        } else if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
            data_020fe9a4.unknown_4_ = 0;
            func_020290e8(arg0->unknown_50_ + data_020ef74c.unknown_8_, arg0->unknown_52_ + data_020ef74c.unknown_4_, arg0->unknown_4_);
        }

        {
            char var23[0x80];
            var7 = inline_02029988(arg0, 0);
            for (var5 = 0; var5 < var8; var5++) {
                if (var7 == NULL) break;
                sprintf(var23, data_020ef75c, var7->unknown_4_);
                data_020fe9a4.unknown_4_ = 0;
                if (var7->unknown_38_) data_020fe9a4.unknown_4_ = 1;
                if (data_020ef74c.unknown_c_ == 0) {
                    func_0202ad98(arg0->unknown_50_ / 8 + 1, arg0->unknown_52_ / 8 + 2 + var5, 7, var23);
                } else if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
                    int var24 = arg0->unknown_50_ + data_020ef74c.unknown_8_;
                    int var25 = data_020ef74c.unknown_4_ * (var5 + 2);
                    func_020290e8(var24, var25 + arg0->unknown_52_, var23);
                }
                var7 = var7->unknown_34_;
            }
        }

        {
            char var26[0x80];
            var7 = inline_02029988(arg0, arg0->unknown_5e_ + 1);
            for (var5 = arg0->unknown_5e_ + 1; var5 < arg0->unknown_5a_; var5++) {
                if (var7 == NULL) break;
                sprintf(var26, data_020ef75c, var7->unknown_4_);
                data_020fe9a4.unknown_4_ = 0;
                if (var7->unknown_38_) data_020fe9a4.unknown_4_ = 1;
                if (data_020ef74c.unknown_c_ == 0) {
                    func_0202ad98(arg0->unknown_50_ / 8 + 1, arg0->unknown_52_ / 8 + 2 + var5, 7, var26);
                } else if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
                    int var27 = arg0->unknown_50_ + data_020ef74c.unknown_8_;
                    int var28 = data_020ef74c.unknown_4_ * (var5 + 2);
                    func_020290e8(var27, var28 + arg0->unknown_52_, var26);
                }
                var7 = var7->unknown_34_;
            }
        }

        {
            char var29[0x80];
            char var30[0x10];
            var7 = inline_02029988(arg0, arg0->unknown_64_);
            for (var5 = arg0->unknown_64_; var5 <= arg0->unknown_66_; var5++) {
                if (var7 == NULL) break;
                data_020fe9a4.unknown_4_ = 0;
                var6 = 0;
                if (var7->unknown_38_) data_020fe9a4.unknown_4_ = 1;
                if (arg0->unknown_5c_ <= var5 && var5 <= arg0->unknown_5e_) {
                    if (arg0->unknown_60_ == var5) {
                        sprintf(var29, data_020ef75f);
                    } else {
                        sprintf(var29, data_020ef763);
                    }
#if defined(jpn)
                    enum { Enum_02029988_3 = 1 };
#else
                    enum { Enum_02029988_3 = 3 };
#endif
                    var6 += Enum_02029988_3;
                }
                {
                    int var31;
                    if (var7->unknown_0_ == 2) {
                        if (arg0->unknown_60_ == var5 && var7->unknown_38_ == 0 &&
                            g_keyManager.TestKeysPressed(0x30)) {
                            var7->unknown_40_ = var7->unknown_40_ == 0;
                        }
                        if (var7->unknown_40_) {
                            sprintf(var29 + var6, data_020ef767);
                        } else {
                            sprintf(var29 + var6, data_020ef76b);
                        }
                        var6 += 3;
                    }
                    __clear(var30, sizeof(var30));
                    var31 = 0;
                    if (var7->unknown_0_ == 3) {
                        var7->unknown_4c_ &= ~2;
                        var7->unknown_4c_ &= ~0xc;
                        if (arg0->unknown_60_ == var5 && var7->unknown_38_ == 0) {
                            int var32 = 0;
                            int var33;
                            int var34;
                            int var35 = var7->unknown_40_;
                            int var36 = 1;
                            if (g_keyManager.TestKeysHeld(8)) var36 = 100;
                            if (g_keyManager.TestKeyRepeat(0x10)) {
                                func_0202a678((Struct_02029988*)var7, var36);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x20)) {
                                func_0202a678((Struct_02029988*)var7, -var36);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x100)) {
                                func_0202a678((Struct_02029988*)var7, var36 * 10);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x200)) {
                                func_0202a678((Struct_02029988*)var7, var36 * -10);
                                var32 = 1;
                            }
                            if (adjusted) {
                                savedFirst = menu->visibleFirst;
                                savedLast = menu->visibleLast;
                                DebugMenu_UpdateLayout(menu);
                                menu->visibleFirst = savedFirst;
                                menu->visibleLast = savedLast;
                                item->flags |= 2;
                                if (old < item->value) item->flags |= 4;
                                if (old > item->value) item->flags |= 8;
                            }
                        }
                        if (!(var7->unknown_4c_ & 0x40)) {
                            if (var7->unknown_4c_ & 0x20) {
                                if (var7->unknown_4c_ & 1) {
                                    sprintf(var30, data_020ef76f, var7->unknown_40_);
                                } else if (var7->unknown_4c_ & 0x80) {
                                    sprintf(var30, data_020ef772, var7->unknown_40_ + 0x40);
                                } else {
                                    sprintf(var30, data_020ef775, var7->unknown_40_);
                                }
                            } else {
                                if (var7->unknown_4c_ & 1) {
                                    sprintf(var30, data_020ef778, var7->unknown_40_);
                                } else if (var7->unknown_4c_ & 0x80) {
                                    sprintf(var30, data_020ef77d, var7->unknown_40_ + 0x40);
                                } else {
                                    sprintf(var30, data_020ef782, var7->unknown_40_);
                                }
                            }
                            var31 = 1;
                            if (var7->unknown_4c_ & 0x10) var31 = 2;
                        }
                    }
                    if (var31 == 1) {
                        sprintf(var29 + var6, data_020ef75c, var30);
                        var6 += strlen(var30);
                    }
                    sprintf(var29 + var6, data_020ef75c, var7->unknown_4_);
                    var6 += strlen(var7->unknown_4_);
                    if (var31 == 2) {
                        sprintf(var29 + var6, data_020ef75c, var30);
                        var6 += strlen(var30);
                    }
                    if (data_020ef74c.unknown_c_ == 0) {
                        func_0202ad98(arg0->unknown_50_ / 8 + 1, arg0->unknown_52_ / 8 + 2 + (var8 + (var5 - arg0->unknown_64_)), 7, var29);
                    } else if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
                        int var37 = arg0->unknown_50_ + data_020ef74c.unknown_8_;
                        int var38 = data_020ef74c.unknown_4_ * (var8 + (var5 - arg0->unknown_64_) + 2);
                        func_020290e8(var37, var38 + arg0->unknown_52_, var29);
                    }
                }
                var7 = var7->unknown_34_;
            }
        }
    }

    if (menu->state == 4) {
        cur = (DebugMenu*)GetItem(menu, menu->selected);
        if (cur != NULL && cur->type == 1) {
            func_02029988(cur, ticks);
            if (cur->state == 1 ? 1 : 0) {
                DebugMenu_Open((char*)menu, 0);
            }
        }
    }

    switch (arg0->unknown_6c_) {
    case 0:
        if (func_02029384(arg0->unknown_50_, arg0->unknown_52_, arg0->unknown_54_, arg0->unknown_56_)) {
            if (arg0->unknown_66_ - arg0->unknown_64_ + 1 < arg0->unknown_5a_) {
                func_02029470(0, 1, 3, 0, 0, 0);
                func_020292ec(arg0->unknown_50_ + arg0->unknown_54_ - 9, arg0->unknown_52_ + 1, 8, arg0->unknown_56_ - 2, 0x7fff);
                func_02029470(0, 1, 3, 0, 0x1f, 0);
                if (var0 < 0 || var0 >= 0x100) {
                    var4 = arg0->unknown_52_ + 1;
                    var0 = arg0->unknown_56_ - 2;
                }
                func_020292ec(var2, var4, 8, var0, 0x7fff);
            }
        }
        break;
    case 1:
        break;
    case 2:
        arg0->unknown_58_ = arg0->unknown_56_;
        arg0->unknown_6c_ = 0;
        func_02029384(arg0->unknown_50_, arg0->unknown_52_, arg0->unknown_54_, arg0->unknown_58_);
        break;
    case 3:
        arg0->unknown_58_ = 0;
        arg0->unknown_6c_ = 1;
        func_02029384(arg0->unknown_50_, arg0->unknown_52_, arg0->unknown_54_, arg0->unknown_58_);
        break;
    }
}
