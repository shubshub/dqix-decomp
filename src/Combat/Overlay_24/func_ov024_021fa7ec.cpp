#include <globaldefs.h>

struct Struct_ov024_021fa7ec_4 {
    char unknown_0_[0x21];
    unsigned char unknown_21_;
    char unknown_22_[0x24 - 0x22];
    signed char unknown_24_;
    char unknown_25_[0x3e - 0x25];
    unsigned char unknown_3e_;
    unsigned char unknown_3f_;
    unsigned char unknown_40_;
    unsigned char unknown_41_;
    unsigned char unknown_42_;
    unsigned char unknown_43_;
    unsigned char unknown_44_;
    char unknown_45_[0x58 - 0x45];
    int unknown_58_0_ : 18;
    int unknown_5a_2_ : 3;
    int unknown_5a_5_ : 3;
    int unknown_5b_0_ : 8;
};

struct Struct_ov024_021fa7ec_9 {
    char unknown_0_[0x34];
    unsigned short unknown_34_;
};

struct Struct_ov024_021fa7ec_10 {
    char unknown_0_[0xa];
    unsigned short unknown_a_0_ : 12;
    unsigned short unknown_b_4_ : 1;
};

struct Struct_ov024_021fa7ec_11 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0x134 - 6];
    struct Struct_ov024_021fa7ec_9* unknown_134_;
    struct Struct_ov024_021fa7ec_4* unknown_138_;
    char unknown_13c_[0x144 - 0x13c];
#if defined(jpn)
    union {
        struct Struct_ov024_021fa7ec_10* unknown_144_;
        unsigned char* unknown_150_;
    };
#else
    struct Struct_ov024_021fa7ec_10* unknown_144_;
    char unknown_148_[0x150 - 0x148];
    unsigned char* unknown_150_;
#endif
};

struct Struct_ov024_021fa7ec {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 12;
    unsigned int unknown_a_6_ : 5;
    unsigned int unknown_b_3_ : 5;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
    unsigned int unknown_1c_0_ : 14;
    unsigned int unknown_1d_6_ : 18;
    unsigned int unknown_20_[3];
    unsigned int unknown_2c_0_ : 27;
    unsigned int unknown_2f_3_ : 1;
    unsigned int unknown_2f_4_ : 4;
};

struct Struct_ov024_021fa7ec_2 {
    char unknown_0_[0x8e50];
    short unknown_8e50_;
    short unknown_8e52_;
    char unknown_8e54_[0x8e82 - 0x8e54];
    signed char unknown_8e82_;
    signed char unknown_8e83_;
};

struct Struct_ov024_021fa7ec_3 {
    struct Struct_ov024_021fa7ec_2* unknown_0_;
    char unknown_4_[4];
    struct Struct_ov024_021fa7ec_11* unknown_8_;
    char unknown_c_[0x9c - 0xc];
    int unknown_9c_;
    char unknown_a0_[0xe4 - 0xa0];
    float unknown_e4_[(0x170 - 0xe4) / 4];
    float unknown_170_;
    char unknown_174_[0x64c - 0x174];
    struct Struct_ov024_021fa7ec* unknown_64c_;
    char unknown_650_[4];
    unsigned char unknown_654_;
};

struct Struct_ov024_021f736c {
    struct Struct_ov024_021fa7ec_11* unknown_0_;
    struct Struct_ov024_021fa7ec_11* unknown_4_;
    struct Struct_ov024_021fa7ec_10* unknown_8_;
    short unknown_c_;
    struct Struct_ov024_021fa7ec* unknown_10_;
    float unknown_14_;
    float unknown_18_;
    float unknown_1c_;
    float unknown_20_;
    float unknown_24_;
};

int GetFieldAt0x150_02053c6c(unsigned char*);
struct Entry_021fa7ec* FindEntryForCombatant02153758(void*, int);
int DispatchByCategory_021f736c(struct Outer_021f736c* obj);
struct FlagObj_021da998;
int IsFlagBit8388608Set_021da998(FlagObj_021da998*);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(FlagObj_021dd260*);
float GetClampedRateMultiplier_02074738(int tension, int mode);
int GameObject_GetPartyMemberLevel(void*);
float CalculateTensionBonus(int tension, int level);
extern "C" float func_ov024_021f875c(struct Struct_ov024_021fa7ec_3* arg0, struct Struct_ov024_021fa7ec_11* arg1, struct Struct_ov024_021fa7ec* arg2, int arg3);
extern "C" int func_ov000_02156068(struct Struct_ov024_021fa7ec_2* arg0, int arg1, int arg2, int arg3);
extern "C" float func_ov000_02156b38(struct Struct_ov024_021fa7ec_2* arg0, int arg1, int arg2);
struct Struct_020886b0;
extern "C" int func_020886b0(Struct_020886b0*);
struct Struct_020886f8;
extern "C" int func_020886f8(Struct_020886f8*);
struct Struct_02088740;
extern "C" int func_02088740(Struct_02088740*);
struct Struct_02088788;
extern "C" int func_02088788(Struct_02088788*);
struct Struct_020887d0;
extern "C" int func_020887d0(Struct_020887d0*);
struct Struct_02088660;
extern "C" int func_02088660(Struct_02088660*);
extern "C" float func_02085968(char*);
extern "C" float func_02085818(unsigned char* arg0);
extern "C" float func_02085a10(char*);
struct Struct_02085a48;
extern "C" float func_02085a48(Struct_02085a48*);
extern "C" float func_020859d8(char*);
extern "C" float func_020859a0(char*);
extern "C" float func_02085930(char*);
extern "C" float func_02085850(unsigned char* arg0);
extern "C" float func_020858f8(unsigned char* arg0);
struct Struct_02085a80;
extern "C" float func_02085a80(Struct_02085a80*);
extern "C" float func_020858c0(unsigned char* arg0);
extern "C" float func_02085888(unsigned char* arg0);
struct Struct_ov024_021fa7ec_5;
extern "C" int func_ov024_021fb430(Struct_ov024_021fa7ec_5*);
struct Struct_ov024_021fa7ec_6;
extern "C" int func_ov024_021fb448(Struct_ov024_021fa7ec_6*);
struct Struct_ov024_021fa7ec_7;
extern "C" int func_ov024_021fb460(Struct_ov024_021fa7ec_7*);
struct Struct_ov024_021fa7ec_8;
extern "C" int func_ov024_021fb478(Struct_ov024_021fa7ec_8*);
extern "C" float func_020748d0(int arg0);
extern "C" float func_020748a8(int arg0);
extern "C" float func_02074938(int arg0);
struct GameObject;
extern "C" int func_ov024_021e67b0(GameObject*);
extern "C" int func_020851d8(unsigned char* arg0);
extern "C" int func_02085128(unsigned char* arg0);

struct Struct_ov024_021fefa0 { float unknown_0_[4]; };
extern struct Struct_ov024_021fefa0 data_ov024_021fefa0;

// USA: func_ov024_021fa7ec
extern "C" ARM void func_ov024_021fa7ec(struct Struct_ov024_021fa7ec_3* arg0, float* arg1, float* arg2, float* arg3,
                                        int* arg4, float arg5, float arg6, int arg7,
                                        struct Struct_ov024_021fa7ec_11* arg8, int arg9) {
    struct Struct_ov024_021fa7ec* var0;
    int var1;
    float var2;
    float var3;
    float var4;
    float var5;
    float var6;
    float var7;
    float var8;
    struct Struct_ov024_021fa7ec_11* var9;
    var9 = arg0->unknown_8_;
    func_02053c6c((unsigned char*)var9);
    var0 = arg0->unknown_64c_;
    float var10 = arg0->unknown_170_;
    var1 = arg0->unknown_9c_;

    if (arg7) {
        var2 = arg5;
        var3 = arg6;
    } else {
        var2 = arg0->unknown_e4_[arg9];
        var3 = 0.9375f * var2;
    }

    struct Struct_ov024_021f736c var11;
    var11.unknown_0_ = var9;
    var11.unknown_4_ = arg8;
    var11.unknown_8_ = func_ov000_02153758(arg0->unknown_0_, arg8->unknown_4_);
    var11.unknown_c_ = var1;
    var11.unknown_10_ = var0;
    var11.unknown_14_ = var2;
    var11.unknown_18_ = var3;
    var11.unknown_1c_ = var2;
    var11.unknown_20_ = var3;
    var11.unknown_24_ = 1.0f;
    func_ov024_021f736c(&var11);

    var4 = var11.unknown_1c_;
    var5 = var11.unknown_20_;
    unsigned char var12 = 0;

    if ((action->flags10 & 0x2000) &&
        (IsFlagBit8388608Set_021da998((FlagObj_021da998*)attacker) ||
         IsFlagBit24Set_021dd260((FlagObj_021dd260*)attacker))) {
        float mult = GetClampedRateMultiplier_02074738(attacker->stats->tension24, 0);
        hi = hi * mult;
        lo = lo * mult;
        if (target->entry == 0 || !target->entry->flagBit12) {
            signed char level = GameObject_GetPartyMemberLevel(attacker);
            CalculateTensionBonus(attacker->stats->tension24, level);
            hi = hi + level;
            lo = lo + level;
        }
    }

    if (var0->unknown_4_0_ == 0x1f9) {
        unsigned short var15 = var9->unknown_134_->unknown_34_;
        float var16 = var15;
        var4 = 1.2f * var4;
        if (var16 < var4) {
            var16 = var4;
        }
        var4 = var16;
        var6 = 0.95f * var15;
        var5 = 1.2f * var5;
        if (var6 < var5) {
            var6 = var5;
        }
        var5 = var6;
        var12 = 1;
    }

    var7 = func_ov024_021f875c(arg0, arg8, var0, 0);
    int var17 = arg8->unknown_4_;

    if (var9 && (var0->unknown_10_ & 0x40000)) {
        if (func_ov000_02156068(arg0->unknown_0_, var17, 1, 0)) {
            var7 = var7 * func_02085968((char*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 2, 0)) {
            var7 = var7 * func_02085818(var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 3, 0)) {
            var7 = var7 * func_02085a10((char*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 4, 0)) {
            var7 = var7 * func_02085a48((Struct_02085a48*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 5, 0)) {
            var7 = var7 * func_020859d8((char*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 6, 0)) {
            var7 = var7 * func_020859a0((char*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 7, 0)) {
            var7 = var7 * func_02085930((char*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 8, 0)) {
            var7 = var7 * func_02085850(var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 9, 0)) {
            var7 = var7 * func_020858f8(var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 10, 0)) {
            var7 = var7 * func_02085a80((Struct_02085a80*)var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 11, 0)) {
            var7 = var7 * func_020858c0(var9->unknown_150_);
        }
        if (func_ov000_02156068(arg0->unknown_0_, var17, 12, 0)) {
            var7 = var7 * func_02085888(var9->unknown_150_);
        }
    }

    unsigned char var18 = 0;
    var8 = 0;
    float var19 = 0;
    int var20 = 0;
    struct Struct_ov024_021fa7ec_11* var21 = arg0->unknown_8_;
    if (var21->unknown_4_ >= 0 && var21->unknown_4_ <= 3) {
        var20 = 1;
    }
    if (var20 && var21 && (var0->unknown_10_ & 0x40000) &&
        arg0->unknown_654_ >= 1 && arg0->unknown_654_ <= 7) {
        var19 = func_ov000_02156b38(arg0->unknown_0_, arg8->unknown_4_, arg0->unknown_654_);
        var18 = 1;
    }

    if (arg8 && var0->unknown_a_6_ == 8) {
        if (func_020886b0((Struct_020886b0*)var9->unknown_138_)) {
            var8 = 1.1f * (arg8->unknown_138_->unknown_3e_ / 100.0f);
        } else if (func_020886f8((Struct_020886f8*)var9->unknown_138_)) {
            var8 = 1.1f * (arg8->unknown_138_->unknown_3f_ / 100.0f);
        } else if (func_02088740((Struct_02088740*)var9->unknown_138_)) {
            struct Struct_ov024_021fa7ec_4* var22 = arg8->unknown_138_;
            float var23 = 1.1f * (var22->unknown_41_ / 100.0f);
            float var24 = 1.1f * (var22->unknown_40_ / 100.0f);
            var8 = var24;
            if (var24 < var23) {
                var8 = var23;
            }
        } else if (func_02088788((Struct_02088788*)var9->unknown_138_)) {
            struct Struct_ov024_021fa7ec_4* var25 = arg8->unknown_138_;
            float var26 = 1.1f * (var25->unknown_43_ / 100.0f);
            float var27 = 1.1f * (var25->unknown_42_ / 100.0f);
            var8 = var27;
            if (var27 < var26) {
                var8 = var26;
            }
        } else if (func_020887d0((Struct_020887d0*)var9->unknown_138_)) {
            var8 = 1.1f * (arg8->unknown_138_->unknown_44_ / 100.0f);
        }
        if (func_02088660((Struct_02088660*)var9->unknown_138_)) {
            var18 = 1;
        }
    }

    if (var18) {
        if (var19 <= var8) {
            var7 = var7 * var8;
        } else {
            var7 = var7 * var19;
        }
    }

    if (func_ov024_021fb430((Struct_ov024_021fa7ec_5*)arg8) && var0->unknown_a_6_ == 1) {
        var7 = 0.75f * var7;
    }
    if (func_ov024_021fb448((Struct_ov024_021fa7ec_6*)arg8) && var0->unknown_a_6_ == 2) {
        var7 = 0.75f * var7;
    }
    if (var0->unknown_10_ & 1) {
        if (func_ov024_021fb460((Struct_ov024_021fa7ec_7*)arg8) && var0->unknown_18_5_ != 2) {
            var7 = var7 * func_020748d0((signed char)arg8->unknown_138_->unknown_5a_2_);
        }
    }
    if ((var0->unknown_10_ & 4) && func_ov024_021fb478((Struct_ov024_021fa7ec_8*)arg8)) {
        var7 = var7 * func_020748a8((signed char)arg8->unknown_138_->unknown_5a_5_);
    }
    if (var0->unknown_10_ & 0x10) {
        if (arg8->unknown_138_->unknown_21_ <= 3) {
            var7 = var7 * func_02074938((signed char)arg8->unknown_138_->unknown_21_);
        } else if (func_ov024_021e67b0((GameObject*)arg8)) {
            var7 = var7 * func_02074938(1);
        }
    }
    if (func_ov024_021dd260((Struct_ov024_021dd028_5*)arg8) && var0->unknown_18_5_ == 1) {
        var7 = 0.5f * var7;
    }

    var4 = var4 * var7;
    var5 = var5 * var7;

    if (var0->unknown_2f_3_) {
        struct Struct_ov024_021fa7ec_2* var28 = arg0->unknown_0_;
        if (var28->unknown_8e52_ == var0->unknown_4_0_ && var28->unknown_8e82_ == 1 && var28->unknown_8e50_ == arg8->unknown_4_) {
            int var29 = var28->unknown_8e83_ + 1;
            if (var29 > 3) {
                var29 = 3;
            }
            struct Struct_ov024_021fefa0 var30 = data_ov024_021fefa0;
            var4 = var4 * var30.unknown_0_[var29];
            var5 = var5 * var30.unknown_0_[var29];
            *arg4 = arg9;
        }
    }

    if (arg0->unknown_64c_->unknown_4_0_ == 0x79) {
        if (arg9 == 0) {
            int var31 = arg0->unknown_9c_;
            var4 = var4 * (0.8f + 0.125f * var31);
            var5 = var5 * (0.8f + 0.125f * var31);
        } else {
            var4 *= 0.8f;
            var5 *= 0.8f;
        }
    }

    if ((var0->unknown_10_ & 0x40000) && func_020851d8(arg0->unknown_8_->unknown_150_)) {
        var4 = 1.0f;
        var5 = var4;
    }

    if (var0->unknown_4_0_ == 1) {
        if (var4 < 1.0f) {
            var4 = 1.0f;
        }
        if (var5 < 0.4f) {
            var5 = 0.4f;
        }
    }

    struct Struct_ov024_021fa7ec_10* var32 = func_ov000_02153758(arg0->unknown_0_, arg8->unknown_4_);
    if (var32 && var32->unknown_b_4_ && !var12) {
        if (var0->unknown_4_0_ != 0x40 && var0->unknown_4_0_ != 0x7e && var0->unknown_4_0_ != 0x82) {
            var4 = 1.0f;
            var5 = 0.4f;
            if ((var0->unknown_10_ & 0x40000) && func_020851d8(arg0->unknown_8_->unknown_150_)) {
                var5 = 1.0f;
            }
            if ((var0->unknown_10_ & 0x40000) && func_02085128(arg0->unknown_8_->unknown_150_)) {
                var4 += 1.0f;
                var5 += 1.0f;
            }
            if ((var0->unknown_10_ & 0x2000) &&
                (func_ov024_021da998((Struct_ov024_021da670_6*)var9) ||
                 func_ov024_021dd260((Struct_ov024_021dd028_5*)var9))) {
                float var33 = func_02074738(var9->unknown_138_->unknown_24_, 0);
                var4 = var4 * var33;
                var5 = var5 * var33;
            }
        }
        if (!(var0->unknown_10_ & 0x1000000)) {
            var4 = 0;
        }
    }

    unsigned int var34 = var0->unknown_1c_0_;
    if (var34 != 0 && var34 < var4) {
        var4 = var34;
    }
    if (var34 != 0 && var34 < var5) {
        var5 = var34;
    }

    *arg1 = var4;
    *arg2 = var5;
    *arg3 = *arg1 * var10 + *arg2 * (1.0f - var10);
}
