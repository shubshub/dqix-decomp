#include <globaldefs.h>

struct Struct_ov024_021fa7ec_4 {
    char pad0[0x21];
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
    char pad0[0x34];
    unsigned short unknown_34_;
};

struct Struct_ov024_021fa7ec_10 {
    char pad0[0xa];
    unsigned short unknown_a_0_ : 12;
    unsigned short unknown_b_4_ : 1;
};

struct Struct_ov024_021fa7ec_11 {
    char pad0[4];
    short id;
    char pad6[0x134 - 6];
    struct Struct_ov024_021fa7ec_9* info;
    struct Struct_ov024_021fa7ec_4* stats;
    char unknown_13c_[0x144 - 0x13c];
#if defined(jpn)
    union {
        struct Struct_ov024_021fa7ec_10* entry;
        unsigned char* field150;
    };
#else
    struct Struct_ov024_021fa7ec_10* entry;
    char unknown_148_[0x150 - 0x148];
    unsigned char* field150;
#endif
};

struct Struct_ov024_021fa7ec {
    unsigned int pad0;
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int lo8 : 8;
    unsigned int kind : 2;
    unsigned int unknown_9_2_ : 12;
    unsigned int elem : 5;
    unsigned int unknown_b_3_ : 5;
    unsigned int unknown_c_;
    unsigned int flags10;
    unsigned int unknown_14_;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
    unsigned int cap : 14;
    unsigned int unknown_1d_6_ : 18;
    unsigned int pad20[3];
    unsigned int unknown_2c_0_ : 27;
    unsigned int unknown_2f_3_ : 1;
    unsigned int unknown_2f_4_ : 4;
};

struct Struct_ov024_021fa7ec_2 {
    char pad0[0x8e50];
    short unknown_8e50_;
    short unknown_8e52_;
    char unknown_8e54_[0x8e82 - 0x8e54];
    signed char unknown_8e82_;
    signed char unknown_8e83_;
};

struct Struct_ov024_021fa7ec_3 {
    struct Struct_ov024_021fa7ec_2* battle;
    char pad4[4];
    struct Struct_ov024_021fa7ec_11* attacker;
    char unknown_c_[0x9c - 0xc];
    int unknown_9c_;
    char unknown_a0_[0xe4 - 0xa0];
    float rates[(0x170 - 0xe4) / 4];
    float weight;
    char unknown_174_[0x64c - 0x174];
    struct Struct_ov024_021fa7ec* action;
    char unknown_650_[4];
    unsigned char unknown_654_;
};

struct Struct_ov024_021f736c {
    struct Struct_ov024_021fa7ec_11* attacker;
    struct Struct_ov024_021fa7ec_11* target;
    struct Struct_ov024_021fa7ec_10* entry;
    short count;
    struct Struct_ov024_021fa7ec* action;
    float unknown_14_;
    float unknown_18_;
    float hi;
    float lo;
    float scale;
};

extern "C" int func_02053c6c(unsigned char*);
extern "C" struct Struct_ov024_021fa7ec_10* func_ov000_02153758(void*, int);
extern "C" int func_ov024_021f736c(struct Struct_ov024_021f736c* obj);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" float func_02074738(int arg0, int mode);
extern "C" int GameObject_GetPartyMemberLevel(void*);
float CalculateTensionBonus(int tension, int level);
extern "C" float func_ov024_021f875c(struct Struct_ov024_021fa7ec_3* self, struct Struct_ov024_021fa7ec_11* target, struct Struct_ov024_021fa7ec* action, int flag);
extern "C" int func_ov000_02156068(struct Struct_ov024_021fa7ec_2* battle, int id, int kind, int mode);
extern "C" float func_ov000_02156b38(struct Struct_ov024_021fa7ec_2* battle, int id, int elem);
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
extern "C" float func_02085818(unsigned char* p);
extern "C" float func_02085a10(char*);
struct Struct_02085a48;
extern "C" float func_02085a48(Struct_02085a48*);
extern "C" float func_020859d8(char*);
extern "C" float func_020859a0(char*);
extern "C" float func_02085930(char*);
extern "C" float func_02085850(unsigned char* p);
extern "C" float func_020858f8(unsigned char* p);
struct Struct_02085a80;
extern "C" float func_02085a80(Struct_02085a80*);
extern "C" float func_020858c0(unsigned char* p);
extern "C" float func_02085888(unsigned char* p);
struct Struct_ov024_021fa7ec_5;
extern "C" int func_ov024_021fb430(Struct_ov024_021fa7ec_5*);
struct Struct_ov024_021fa7ec_6;
extern "C" int func_ov024_021fb448(Struct_ov024_021fa7ec_6*);
struct Struct_ov024_021fa7ec_7;
extern "C" int func_ov024_021fb460(Struct_ov024_021fa7ec_7*);
struct Struct_ov024_021fa7ec_8;
extern "C" int func_ov024_021fb478(Struct_ov024_021fa7ec_8*);
extern "C" float func_020748d0(int v);
extern "C" float func_020748a8(int v);
extern "C" float func_02074938(int v);
struct GameObject;
extern "C" int func_ov024_021e67b0(GameObject*);
extern "C" int func_020851d8(unsigned char* p);
extern "C" int func_02085128(unsigned char* p);

struct Struct_ov024_021fefa0 { float v[4]; };
extern struct Struct_ov024_021fefa0 data_ov024_021fefa0;

// USA: func_ov024_021fa7ec
extern "C" ARM void func_ov024_021fa7ec(struct Struct_ov024_021fa7ec_3* self, float* arg1, float* arg2, float* arg3,
                                        int* outIndex, float arg5, float arg6, int arg7,
                                        struct Struct_ov024_021fa7ec_11* target, int index) {
    struct Struct_ov024_021fa7ec* action;
    int count;
    float var2;
    float var3;
    float hi;
    float lo;
    float var6;
    float rate;
    float var8;
    struct Struct_ov024_021fa7ec_11* attacker;
    attacker = self->attacker;
    func_02053c6c((unsigned char*)attacker);
    action = self->action;
    float weight = self->weight;
    count = self->unknown_9c_;

    if (arg7) {
        var2 = arg5;
        var3 = arg6;
    } else {
        var2 = self->rates[index];
        var3 = 0.9375f * var2;
    }

    struct Struct_ov024_021f736c var11;
    var11.attacker = attacker;
    var11.target = target;
    var11.entry = func_ov000_02153758(self->battle, target->id);
    var11.count = count;
    var11.action = action;
    var11.unknown_14_ = var2;
    var11.unknown_18_ = var3;
    var11.hi = var2;
    var11.lo = var3;
    var11.scale = 1.0f;
    func_ov024_021f736c(&var11);

    hi = var11.hi;
    lo = var11.lo;
    unsigned char var12 = 0;

    if ((action->flags10 & 0x2000) &&
        (func_ov024_021da998((Struct_ov024_021da670_6*)attacker) ||
         func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker))) {
        float mult = func_02074738(attacker->stats->unknown_24_, 0);
        hi = hi * mult;
        lo = lo * mult;
        if (target->entry == 0 || !target->entry->unknown_b_4_) {
            signed char level = GameObject_GetPartyMemberLevel(attacker);
            CalculateTensionBonus(attacker->stats->unknown_24_, level);
            hi = hi + level;
            lo = lo + level;
        }
    }

    if (action->id == 0x1f9) {
        unsigned short value = attacker->info->unknown_34_;
        float var16 = value;
        hi = 1.2f * hi;
        if (var16 < hi) {
            var16 = hi;
        }
        hi = var16;
        var6 = 0.95f * value;
        lo = 1.2f * lo;
        if (var6 < lo) {
            var6 = lo;
        }
        lo = var6;
        var12 = 1;
    }

    rate = func_ov024_021f875c(self, target, action, 0);
    int targetId = target->id;

    if (attacker && (action->flags10 & 0x40000)) {
        if (func_ov000_02156068(self->battle, targetId, 1, 0)) {
            rate = rate * func_02085968((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 2, 0)) {
            rate = rate * func_02085818(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 3, 0)) {
            rate = rate * func_02085a10((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 4, 0)) {
            rate = rate * func_02085a48((Struct_02085a48*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 5, 0)) {
            rate = rate * func_020859d8((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 6, 0)) {
            rate = rate * func_020859a0((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 7, 0)) {
            rate = rate * func_02085930((char*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 8, 0)) {
            rate = rate * func_02085850(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 9, 0)) {
            rate = rate * func_020858f8(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 10, 0)) {
            rate = rate * func_02085a80((Struct_02085a80*)attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 11, 0)) {
            rate = rate * func_020858c0(attacker->field150);
        }
        if (func_ov000_02156068(self->battle, targetId, 12, 0)) {
            rate = rate * func_02085888(attacker->field150);
        }
    }

    unsigned char var18 = 0;
    var8 = 0;
    float var19 = 0;
    int isParty = 0;
    struct Struct_ov024_021fa7ec_11* player = self->attacker;
    if (player->id >= 0 && player->id <= 3) {
        isParty = 1;
    }
    if (isParty && player && (action->flags10 & 0x40000) &&
        self->unknown_654_ >= 1 && self->unknown_654_ <= 7) {
        var19 = func_ov000_02156b38(self->battle, target->id, self->unknown_654_);
        var18 = 1;
    }

    if (target && action->elem == 8) {
        if (func_020886b0((Struct_020886b0*)attacker->stats)) {
            var8 = 1.1f * (target->stats->unknown_3e_ / 100.0f);
        } else if (func_020886f8((Struct_020886f8*)attacker->stats)) {
            var8 = 1.1f * (target->stats->unknown_3f_ / 100.0f);
        } else if (func_02088740((Struct_02088740*)attacker->stats)) {
            struct Struct_ov024_021fa7ec_4* var22 = target->stats;
            float a = 1.1f * (var22->unknown_41_ / 100.0f);
            float b = 1.1f * (var22->unknown_40_ / 100.0f);
            var8 = b;
            if (b < a) {
                var8 = a;
            }
        } else if (func_02088788((Struct_02088788*)attacker->stats)) {
            struct Struct_ov024_021fa7ec_4* var25 = target->stats;
            float a = 1.1f * (var25->unknown_43_ / 100.0f);
            float b = 1.1f * (var25->unknown_42_ / 100.0f);
            var8 = b;
            if (b < a) {
                var8 = a;
            }
        } else if (func_020887d0((Struct_020887d0*)attacker->stats)) {
            var8 = 1.1f * (target->stats->unknown_44_ / 100.0f);
        }
        if (func_02088660((Struct_02088660*)attacker->stats)) {
            var18 = 1;
        }
    }

    if (var18) {
        if (var19 <= var8) {
            rate = rate * var8;
        } else {
            rate = rate * var19;
        }
    }

    if (func_ov024_021fb430((Struct_ov024_021fa7ec_5*)target) && action->elem == 1) {
        rate = 0.75f * rate;
    }
    if (func_ov024_021fb448((Struct_ov024_021fa7ec_6*)target) && action->elem == 2) {
        rate = 0.75f * rate;
    }
    if (action->flags10 & 1) {
        if (func_ov024_021fb460((Struct_ov024_021fa7ec_7*)target) && action->unknown_18_5_ != 2) {
            rate = rate * func_020748d0((signed char)target->stats->unknown_5a_2_);
        }
    }
    if ((action->flags10 & 4) && func_ov024_021fb478((Struct_ov024_021fa7ec_8*)target)) {
        rate = rate * func_020748a8((signed char)target->stats->unknown_5a_5_);
    }
    if (action->flags10 & 0x10) {
        if (target->stats->unknown_21_ <= 3) {
            rate = rate * func_02074938((signed char)target->stats->unknown_21_);
        } else if (func_ov024_021e67b0((GameObject*)target)) {
            rate = rate * func_02074938(1);
        }
    }
    if (func_ov024_021dd260((Struct_ov024_021dd028_5*)target) && action->unknown_18_5_ == 1) {
        rate = 0.5f * rate;
    }

    hi = hi * rate;
    lo = lo * rate;

    if (action->unknown_2f_3_) {
        struct Struct_ov024_021fa7ec_2* battle = self->battle;
        if (battle->unknown_8e52_ == action->id && battle->unknown_8e82_ == 1 && battle->unknown_8e50_ == target->id) {
            int level = battle->unknown_8e83_ + 1;
            if (level > 3) {
                level = 3;
            }
            struct Struct_ov024_021fefa0 scales = data_ov024_021fefa0;
            hi = hi * scales.v[level];
            lo = lo * scales.v[level];
            *outIndex = index;
        }
    }

    if (self->action->id == 0x79) {
        if (index == 0) {
            int n = self->unknown_9c_;
            hi = hi * (0.8f + 0.125f * n);
            lo = lo * (0.8f + 0.125f * n);
        } else {
            hi *= 0.8f;
            lo *= 0.8f;
        }
    }

    if ((action->flags10 & 0x40000) && func_020851d8(self->attacker->field150)) {
        hi = 1.0f;
        lo = hi;
    }

    if (action->id == 1) {
        if (hi < 1.0f) {
            hi = 1.0f;
        }
        if (lo < 0.4f) {
            lo = 0.4f;
        }
    }

    struct Struct_ov024_021fa7ec_10* entry = func_ov000_02153758(self->battle, target->id);
    if (entry && entry->unknown_b_4_ && !var12) {
        if (action->id != 0x40 && action->id != 0x7e && action->id != 0x82) {
            hi = 1.0f;
            lo = 0.4f;
            if ((action->flags10 & 0x40000) && func_020851d8(self->attacker->field150)) {
                lo = 1.0f;
            }
            if ((action->flags10 & 0x40000) && func_02085128(self->attacker->field150)) {
                hi += 1.0f;
                lo += 1.0f;
            }
            if ((action->flags10 & 0x2000) &&
                (func_ov024_021da998((Struct_ov024_021da670_6*)attacker) ||
                 func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker))) {
                float mult = func_02074738(attacker->stats->unknown_24_, 0);
                hi = hi * mult;
                lo = lo * mult;
            }
        }
        if (!(action->flags10 & 0x1000000)) {
            hi = 0;
        }
    }

    unsigned int cap = action->cap;
    if (cap != 0 && cap < hi) {
        hi = cap;
    }
    if (cap != 0 && cap < lo) {
        lo = cap;
    }

    *arg1 = hi;
    *arg2 = lo;
    *arg3 = *arg1 * weight + *arg2 * (1.0f - weight);
}
