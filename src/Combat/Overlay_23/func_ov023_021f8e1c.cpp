#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Input/Input.h"


struct Struct_ov023_021f8e1c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

static inline const Struct_ov023_021f8e1c* inline_ov023_021f8e1c_35(const Struct_ov023_021f8e1c& arg0) { return &arg0; }

class Struct_ov023_021f8e1c_3 {
public:
    virtual void inline_ov023_021f8e1c_36(); virtual void inline_ov023_021f8e1c_37(); virtual void inline_ov023_021f8e1c_38(); virtual void inline_ov023_021f8e1c_39();
    virtual void inline_ov023_021f8e1c_40(); virtual void inline_ov023_021f8e1c_43(); virtual void inline_ov023_021f8e1c_44(); virtual void inline_ov023_021f8e1c_45();
    virtual Struct_ov023_021f8e1c inline_ov023_021f8e1c_46();
    virtual void inline_ov023_021f8e1c_47(); virtual void inline_ov023_021f8e1c_48(); virtual void inline_ov023_021f8e1c_49(); virtual void inline_ov023_021f8e1c_50();
    virtual void inline_ov023_021f8e1c_51(); virtual void inline_ov023_021f8e1c_52(); virtual void inline_ov023_021f8e1c_53();
    virtual int inline_ov023_021f8e1c_54();
    virtual void inline_ov023_021f8e1c_55();
    virtual int inline_ov023_021f8e1c_56();
    virtual void inline_ov023_021f8e1c_57(); virtual void inline_ov023_021f8e1c_58(); virtual void inline_ov023_021f8e1c_59(); virtual void inline_ov023_021f8e1c_60();
    virtual void inline_ov023_021f8e1c_61(); virtual void inline_ov023_021f8e1c_62(); virtual void inline_ov023_021f8e1c_63(); virtual void inline_ov023_021f8e1c_64();
    virtual void inline_ov023_021f8e1c_65(); virtual void inline_ov023_021f8e1c_66(); virtual void inline_ov023_021f8e1c(); virtual void inline_ov023_021f8e1c_2();
    virtual void inline_ov023_021f8e1c_3();
    virtual int inline_ov023_021f8e1c_4();
    virtual void inline_ov023_021f8e1c_5(); virtual void inline_ov023_021f8e1c_6(); virtual void inline_ov023_021f8e1c_7(); virtual void inline_ov023_021f8e1c_8();
    virtual void inline_ov023_021f8e1c_9(); virtual void inline_ov023_021f8e1c_10(); virtual void inline_ov023_021f8e1c_11(); virtual void inline_ov023_021f8e1c_12();
    virtual void inline_ov023_021f8e1c_13(); virtual void inline_ov023_021f8e1c_14(); virtual void inline_ov023_021f8e1c_15(); virtual void inline_ov023_021f8e1c_16();
    virtual void inline_ov023_021f8e1c_17(); virtual void inline_ov023_021f8e1c_18(); virtual void inline_ov023_021f8e1c_19(); virtual void inline_ov023_021f8e1c_20();
    virtual void inline_ov023_021f8e1c_21(); virtual void inline_ov023_021f8e1c_22(); virtual void inline_ov023_021f8e1c_23(); virtual void inline_ov023_021f8e1c_24();
    virtual void inline_ov023_021f8e1c_25(); virtual void inline_ov023_021f8e1c_26(); virtual void inline_ov023_021f8e1c_27(); virtual void inline_ov023_021f8e1c_28();
    virtual void inline_ov023_021f8e1c_29(); virtual void inline_ov023_021f8e1c_30(); virtual void inline_ov023_021f8e1c_31(); virtual void inline_ov023_021f8e1c_32();

#if !defined(jpn)
    virtual void inline_ov023_021f8e1c_33();
#endif
    virtual int inline_ov023_021f8e1c_34();

    char unknown_4_[0x2c];
    short unknown_30_;
    short unknown_32_;
};

struct Struct_ov023_021f8e1c_2 {
    char unknown_0_[6];
    unsigned short unknown_6_;
    char unknown_8_[4];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    unsigned short* unknown_20_;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
    unsigned short unknown_28_;
    unsigned short unknown_2a_;
    Struct_ov023_021f8e1c unknown_2c_;
    int unknown_38_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown_42_;
    unsigned short unknown_44_;
    unsigned short unknown_46_;
    unsigned short unknown_48_;
    unsigned short unknown_4a_;
    unsigned short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned short unknown_50_;
    unsigned short unknown_52_;
    unsigned short unknown_54_;
    unsigned short unknown_56_;
    unsigned short unknown_58_;
    unsigned short unknown_5a_;
    short unknown_5c_;
    short unknown_5e_;
    unsigned char unknown_60_;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
};

struct Obj_02184a00;
struct Obj_02184bd8;
struct Obj_02184bcc;
struct Obj021f6f08;
struct Owner02047a5c;
struct Owner02047a3c;
struct SePlayer;

unsigned short GetShortField1b0_02184a00(struct Obj_02184a00* obj);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);
void* AddOffset20_021f7318(void* p);
unsigned char GetEntryByteIfFlag0x84(struct Owner02047a5c* owner, int index);
int GetElementByte1IfEnabled(struct Owner02047a3c* obj, int index);
unsigned short GetShortAt_021f8c50_021f8c50(unsigned char* obj);
unsigned short GetShortAt_021f8c60_021f8c60(unsigned char* obj);
unsigned int GetShort6_021f6f08(struct Obj021f6f08* obj);
int GetField1c8_02184bd8(struct Obj_02184bd8* obj);
void SetField1c8False_02184bcc(struct Obj_02184bcc* obj);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* GetLinkedNodeIfKind6_021f9cb8(void* unused, void* other, void* node);

extern "C" void __clear(void* arg0, int arg1);
extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern "C" void func_ov011_02184a40(void* arg0, int arg1);
extern "C" int func_ov023_021f9bc8(void* arg0);
extern "C" Struct_ov023_021f8e1c_3* func_ov023_021f6880(void* arg0, int arg1);
extern "C" int func_ov023_021f6f10(void* arg0);
extern "C" void func_ov023_021f88b8(void* arg0, void* arg1, int arg2);
extern "C" Struct_ov023_021f8e1c func_ov023_021f8b78(void* arg0, void* arg1);
extern "C" void func_ov023_021f98e0(void* arg0, void* arg1);
extern "C" int func_ov023_021f9da8(void* arg0, void* arg1, int arg2, int arg3);

extern struct SePlayer g_sePlayer;
extern unsigned int data_ov023_021fff24;
extern const unsigned short data_ov023_021fd922[];

static inline int GetMasterBrightnessMain_021f8e1c() { return GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c); }
static inline int GetMasterBrightnessSub_021f8e1c() { return GXx_GetMasterBrightness_((volatile unsigned short*)0x400106c); }

// USA: func_ov023_021f8e1c
extern "C" ARM void func_ov023_021f8e1c(Struct_ov023_021f8e1c_2* arg0, void* arg1) {
    if (arg0->unknown_6_ != func_ov011_02184a00((struct Struct_ov011_02184a00*)arg1)) {
        return;
    }
    if (arg0->unknown_c_ & 0x10) {
        return;
    }
    func_ov023_021f9bc8(arg0);

    int var0;
    int var1;
    int var2;
    int var3 = 0;
    if (inline_ov023_021f8e1c_41() != 0 && inline_ov023_021f8e1c_42() != 0) {
        var3 = 1;
    }

    void* var4 = func_ov011_021849c8(arg1);
    int var5 = 0;
    var0 = arg0->unknown_28_;
    int var6 = arg0->unknown_2a_;

    unsigned short var7[5];
    __clear(var7, sizeof(var7));
    var7[1] = arg0->unknown_3e_;
    var7[2] = arg0->unknown_3c_;
    unsigned short var8[5];
    var8[0] = arg0->unknown_4a_;
    var8[1] = arg0->unknown_50_;
    var8[2] = arg0->unknown_52_;
    var8[3] = arg0->unknown_58_;
    var8[4] = arg0->unknown_5a_;

    if (!var3) {
        for (int var9 = 0; var9 < 5; var9++) {
            if (g_keyManager.TestKeysPressed(data_ov023_021fd922[var9])) {
                int var10 = 0;
                if (var7[var9] != 0) {
                    func_ov011_021848a0(arg1, var7[var9]);
                    var10 = 1;
                }
                if (var8[var9] != 0) {
                    func_ov011_02184a40(arg1, var8[var9]);
                    var10 = 1;
                }
                if (var10) {
                    return;
                }
            }
        }
    }

    int var11 = 0;
    if (arg0->unknown_62_ != 0) {
        if (g_keyManager.TestKeysPressed(0x400)) {
            var11 = 1;
        }
    }
    if (g_keyManager.TestKeysPressed(1) || var11) {
        var5 = 1;
    }
    int var12 = g_keyManager.TestKeysPressed(0x40);
    int var13 = g_keyManager.TestKeysPressed(0x80);
    int var14 = g_keyManager.TestKeysPressed(0x20);
    int var15 = g_keyManager.TestKeysPressed(0x10);

    if (var5 == 0) {
        unsigned int var16 = GameState::GetInstance()->GetEffectiveDeltaTime();
        if (g_keyManager.TestKeysHeld(0x40)) {
            if (data_ov023_021fff24 < var16) {
                var12 = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x80)) {
            if (data_ov023_021fff24 < var16) {
                var13 = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x20)) {
            if (data_ov023_021fff24 < var16) {
                var14 = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x10)) {
            if (data_ov023_021fff24 < var16) {
                var15 = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else {
            data_ov023_021fff24 = 500;
        }
    }

    int var17 = 0;
    if (var12) {
        var0--;
        if (arg0->unknown_4c_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_4c_);
            return;
        }
    } else if (var13) {
        var0++;
        if (arg0->unknown_4e_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_4e_);
            return;
        }
    } else if (var14) {
        var6--;
        if (arg0->unknown_56_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_56_);
            return;
        }
    } else if (var15) {
        var6++;
        if (arg0->unknown_54_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_54_);
            return;
        }
    }

    var1 = 0;
    if (arg0->unknown_60_ != 0) {
        int var18;
        for (var18 = 0; var18 < arg0->unknown_24_; var18++) {
            if (arg0->unknown_20_[var18 * arg0->unknown_26_ + arg0->unknown_2a_] != 0) {
                break;
            }
        }
        int var19;
        for (var19 = arg0->unknown_24_ - 1; var19 >= 0; var19--) {
            if (arg0->unknown_20_[var19 * arg0->unknown_26_ + arg0->unknown_2a_] != 0) {
                break;
            }
        }
        int var20;
        for (var20 = 0; var20 < arg0->unknown_26_; var20++) {
            if (arg0->unknown_20_[arg0->unknown_28_ * arg0->unknown_26_ + var20] != 0) {
                break;
            }
        }
        int var21;
        for (var21 = arg0->unknown_26_ - 1; var21 >= 0; var21--) {
            if (arg0->unknown_20_[arg0->unknown_28_ * arg0->unknown_26_ + var21] != 0) {
                break;
            }
        }
        if (var0 < var18) {
            var0 = var19;
        } else if (var19 < var0) {
            var0 = var18;
        } else if (var6 < var20) {
            var6 = var20;
            var1 = -1;
            if (arg0->unknown_5e_ == 1) {
                var6 = var21;
            }
        } else if (var21 < var6) {
            var6 = var21;
            var1 = 1;
            if (arg0->unknown_5e_ == 1) {
                var6 = var20;
            }
        }
    } else {
        if (var0 < 0) {
            var0 = 0;
        } else if (arg0->unknown_24_ <= var0) {
            var0 = arg0->unknown_24_ - 1;
        } else if (var6 < 0) {
            var6 = 0;
            var1 = -1;
        } else if (arg0->unknown_26_ <= var6) {
            var6 = arg0->unknown_26_ - 1;
            var1 = 1;
        }
    }

    int var22 = var0 * arg0->unknown_26_ + var6;
    if (arg0->unknown_5e_ == 1) {
        var1 = 0;
    }
    if (arg0->unknown_20_[var22] == 0) {
        var0 = arg0->unknown_28_;
        var6 = arg0->unknown_2a_;
    }
    if (var0 != arg0->unknown_28_ || var6 != arg0->unknown_2a_) {
        var17 = 1;
        Struct_ov023_021f8e1c_3* var23 = func_ov023_021f6880(var4, arg0->unknown_20_[func_ov023_021f9bc8(arg0)]);
        void* var24 = func_ov023_021f9cb8(arg0, arg1, var23);
        if (var24 != 0) {
            func_ov023_021f88b8(var24, arg1, 0x8000);
        }
    }

    if (var17 == 0 && g_touchInput.pressed_ != 0) {
        int var25;
        int var26;
        g_touchInput.GetTouchPoint(&var25, &var26);
        var1 = func_ov023_021f9da8(arg0, arg1, var25, var26);
        if (var1 == 0) {
            int var27;
            int var28;
            int var29;
            int var30;
            int var31 = arg0->unknown_26_ * arg0->unknown_24_;
            for (var2 = 0; var2 < var31; var2++) {
                var27 = var28 = var29 = var30 = 0;
                if (arg0->unknown_20_[var2] == 0) {
                    continue;
                }
                Struct_ov023_021f8e1c_3* var32 = func_ov023_021f6880(var4, arg0->unknown_20_[var2]);
                if (var32 == 0) {
                    continue;
                }
                Struct_ov023_021f8e1c var33 = var32->inline_ov023_021f8e1c_46();
                if (func_ov023_021f6f10(var32) == 0) {
                    var27 = (int)(var33.unknown_0_ / 4096.0f);
                    var28 = (int)(var33.unknown_4_ / 4096.0f);
                    void* var34 = func_ov023_021f7318(var32);
                    var29 = func_02047a5c((struct Struct_02047a5c*)var34, 0);
                    var30 = func_02047a3c((struct Struct_02047a3c*)var34, 0);
                } else if (func_ov023_021f6f10(var32) == 8) {
                    const Struct_ov023_021f8e1c* var35 = inline_ov023_021f8e1c_35(func_ov023_021f8b78(var32, arg1));
                    var33.unknown_0_ = var35->unknown_0_;
                    var33.unknown_4_ = var35->unknown_4_;
                    var33.unknown_8_ = var35->unknown_8_;
                    var27 = (int)(var33.unknown_0_ / 4096.0f) + var32->unknown_30_;
                    var28 = (int)(var33.unknown_4_ / 4096.0f) + var32->unknown_32_;
                    var29 = func_ov023_021f8c50((unsigned char*)var32);
                    var30 = func_ov023_021f8c60((unsigned char*)var32);
                }
                if (var27 < var25 && var25 <= var27 + var29 && var28 < var26 && var26 <= var28 + var30) {
                    var6 = var2 % arg0->unknown_26_;
                    var0 = var2 / arg0->unknown_26_;
                    var32 = func_ov023_021f6880(var4, arg0->unknown_20_[var0 * arg0->unknown_26_ + var6]);
                    if (var32 != 0 && func_ov023_021f6f10(var32) == 8 && var32->inline_ov023_021f8e1c_34() == 0) {
                        void* var36 = func_ov023_021f9cb8(arg0, arg1, var32);
                        if (var36 != 0) {
                            func_ov023_021f88b8(var36, arg1, (unsigned short)func_ov023_021f6f08((struct Struct_ov004_02153978*)var32));
                        }
                    } else if (var0 == arg0->unknown_28_ && var6 == arg0->unknown_2a_) {
                        var5 = 1;
                    }
                    break;
                }
            }
        }
    }

    if (var0 != arg0->unknown_28_ || var6 != arg0->unknown_2a_) {
        arg0->unknown_28_ = var0;
        arg0->unknown_2a_ = var6;
        arg0->unknown_38_ = 1;
    }
    if (func_ov011_02184bd8((struct Struct_ov011_02184bd8*)arg1)) {
        arg0->unknown_38_ = 1;
        func_ov011_02184bcc((struct Struct_ov011_02184bcc*)arg1);
    }
    if (arg0->unknown_38_) {
        func_ov023_021f98e0(arg0, arg1);
    }

    if (var1 != 0) {
        arg0->unknown_5c_ += var1;
        if (arg0->unknown_5e_ <= arg0->unknown_5c_) {
            arg0->unknown_5c_ = 0;
        } else if (arg0->unknown_5c_ < 0) {
            arg0->unknown_5c_ = arg0->unknown_5e_ - 1;
        }
        if (arg0->unknown_48_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_48_);
        }
        return;
    }

    if (var12 || var13 || var14 || var15) {
        return;
    }

    if (var5 != 0) {
        if (var3) {
            return;
        }
        var6 = arg0->unknown_2a_;
        var0 = arg0->unknown_28_;
        Struct_ov023_021f8e1c_3* var37 = func_ov023_021f6880(var4, arg0->unknown_20_[var0 * arg0->unknown_26_ + var6]);
        int var38 = 0;
        if (var37 != 0) {
            int var39 = var37->inline_ov023_021f8e1c_54();
            if (var39 > 0) {
                func_ov011_021848a0(arg1, var39);
                var38 = 1;
            }
            var39 = var37->inline_ov023_021f8e1c_56();
            if (var39 > 0) {
                func_ov011_02184a40(arg1, var39);
                var38 = 1;
            }
        }
        if (arg0->unknown_42_ != 0) {
            func_ov011_021848a0(arg1, arg0->unknown_42_);
        }
        if (arg0->unknown_40_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_40_);
        }
        if (played && self->confirmSe != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
    }

    if (g_keyManager.TestKeysPressed(2)) {
        if (var3) {
            return;
        }
        if (arg0->unknown_44_ != 0) {
            func_ov011_021848a0(arg1, arg0->unknown_44_);
        }
        if (arg0->unknown_46_ != 0) {
            func_ov011_02184a40(arg1, arg0->unknown_46_);
        }
    }

    if (g_keyManager.TestKeysPressed(0x400)) {
        if (arg0->unknown_62_ == 0 && !var3) {
            var6 = arg0->unknown_2a_;
            var0 = arg0->unknown_28_;
            Struct_ov023_021f8e1c_3* var40 = func_ov023_021f6880(var4, arg0->unknown_20_[var0 * arg0->unknown_26_ + var6]);
            int var41 = 0;
            if (var40 != 0) {
                int var42 = var40->inline_ov023_021f8e1c_4();
                if (var42 > 0) {
                    func_ov011_02184a40(arg1, var42);
                    var41 = 1;
                }
            }
            if (played && self->confirmSe != 0) {
                SePlayer_Play(&g_sePlayer, 1, 0);
            }
        }
    }
}
