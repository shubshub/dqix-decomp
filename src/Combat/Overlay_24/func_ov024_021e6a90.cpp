#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021e6a90_9 {
    char pad0[0x14];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    char unknown_1c_[0x21 - 0x1c];
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

struct Struct_ov024_021e6a90_8 {
    unsigned int bit0 : 1;
    unsigned int unknown_0_1_ : 1;
    unsigned int rest : 30;
};

struct Struct_ov024_021e6a90_10 {
    char pad0[0x34];
    unsigned short unknown_34_;
};

struct Struct_ov024_021e6a90_11 {
    char pad0[0x134];
    struct Struct_ov024_021e6a90_10* info;
    struct Struct_ov024_021e6a90_9* stats;
#if defined(jpn)
    char unknown1_13c_[0x144 - 0x13c];
#else
    char unknown_13c_[0x150 - 0x13c];
#endif
    unsigned char* field150;
};

struct Struct_ov024_021e6a90 {
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

struct Struct_ov024_021e6a90_2 {
    char pad0[0xb];
    unsigned char lo : 3;
    unsigned char show : 1;
    unsigned char unknown_b_4_ : 1;
    unsigned char level : 3;
};

struct Struct_ov024_021e6a90_3 {
    char pad0[0x1c];
    unsigned char bit0 : 1;
    unsigned char unknown_1c_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_1c_3_ : 3;
    unsigned char unknown_1c_6_ : 1;
    unsigned char unknown_1c_7_ : 1;
};

struct Struct_ov024_021e6a90_4 {
    char pad0[0x8e38];
    int unknown_8e38_;
    char unknown_8e3c_[0x8e83 - 0x8e3c];
    signed char unknown_8e83_;
    char unknown_8e84_[0x8e94 - 0x8e84];
    unsigned char unknown_8e94_;
};

struct Struct_ov024_021e6a90_5 {
    char pad0[4];
    struct Struct_ov024_021e6a90_2* hud;
    char pad8[4];
    struct Struct_ov024_021e6a90_3* flags;
    struct Struct_ov024_021e6a90_4* battle;
    char unknown_14_[0x47 - 0x14];
    unsigned char unknown_47_;
    char unknown_48_[0x76 - 0x48];
    unsigned char unknown_76_;
};

struct Struct_ov024_021e6a90_6 {
    char pad0[0x16c];
    unsigned short values[1];
#if defined(jpn)
    char unknown_16e_[0x8b8 - 0x16e];
#else
    char unknown1_16e_[0x950 - 0x16e];
#endif
    int index;
};

struct Struct_ov024_021e6a90_11* GetCombatantByID(int, int);
struct GameObject;
extern "C" int func_ov024_021e7ba8(GameObject*);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" float func_02074738(int arg0, int mode);
extern "C" int func_ov000_02156068(struct Struct_ov024_021e6a90_4* battle, int id, int kind, int mode);
extern "C" struct Struct_ov024_021e6a90_6* func_ov000_02153710(struct Struct_ov024_021e6a90_4* battle, int id);
extern "C" int func_ov000_02159dbc(struct Struct_ov024_021e6a90_4* battle, int id);
float CalculateTensionBonus(int tension, int level);
struct Struct_ov024_021e6a90_7;
extern "C" int func_ov024_021ea7fc(void*, Struct_ov024_021e6a90_7*, int);
struct Random;
extern "C" float func_02074838(int, int, Random*);
extern "C" float func_ov000_02156b38(struct Struct_ov024_021e6a90_4* battle, int id, int elem);
extern "C" int func_02085748(unsigned char* p);
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
extern "C" float func_020748d0(int v);
extern "C" float func_020748a8(int v);
extern "C" float func_02074938(int v);
extern "C" int func_ov024_021e67b0(GameObject*);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" int func_02085154(unsigned char* p);
extern "C" int func_020851d8(unsigned char* p);
int NextRandomMax(Random*, int);
extern "C" int func_02085128(unsigned char* p);
extern "C" void func_ov000_0215cd80(void*);

extern signed char data_ov024_021fe798[];
struct Struct_ov024_021fe778 { float v[4]; };
extern struct Struct_ov024_021fe778 data_ov024_021fe778;

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e6a90
extern "C" ARM int func_ov024_021e6a90(struct Struct_ov024_021e6a90_5* ctx, int arg1, int targetId,
                                                          struct Struct_ov024_021e6a90* action, unsigned int base) {
    GameState* gs = GameState::GetInstance();
    struct Struct_ov024_021e6a90_11* attacker = GetCombatantByID((int)ctx->battle, arg1);
    struct Struct_ov024_021e6a90_11* target = GetCombatantByID((int)ctx->battle, targetId);
    int var3;
    if (ctx->flags->unknown_1c_7_) {
        var3 = 1;
    } else {
        var3 = 0;
    }
    float var4 = base;
    float var5 = var4;

    if (action->id != 0x150 && func_ov024_021e7ba8((GameObject*)target) &&
        action->kind == 1) {
        ctx->flags->unknown_1c_6_ = 1;
        if ((action->flags10 & 0x2000) &&
            (func_ov024_021da998((Struct_ov024_021da670_6*)attacker) ||
             func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker))) {
            ctx->unknown_47_ = 1;
            if (func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker)) {
                ctx->unknown_47_ = 2;
            }
        }
        return 0;
    }

    if (ctx->unknown_76_ && (action->flags10 & 0x2000) &&
        (func_ov024_021da998((Struct_ov024_021da670_6*)attacker) ||
         func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker))) {
        if (base != 0 || (action->id != 0x70 && action->id != 0x48)) {
            float mult;
            if (IsPartyMember(arg1)) {
                mult = func_02074738(attacker->stats->unknown_24_, 0);
            } else {
                mult = func_02074738(attacker->stats->unknown_24_, 1);
            }
            var4 = var4 * mult;
            unsigned char ok = 1;
            if (IsPartyMember(arg1)) {
                if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
                    ok = 0;
                }
            }
            if (ok) {
                signed char level;
                if (IsPartyMember(arg1)) {
                    struct Struct_ov024_021e6a90_6* t = func_ov000_02153710(ctx->battle, arg1);
                    level = t->values[t->index];
                } else {
                    level = func_ov000_02159dbc(ctx->battle, arg1);
                }
                var4 = var4 + CalculateTensionBonus(attacker->stats->unknown_24_, level);
            }
        }
        ctx->unknown_47_ = 1;
        if (func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker)) {
            ctx->unknown_47_ = 2;
        }
    }

    if (var3 && func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (action->flags10 & 0x1000000) {
            var4 = var5;
        }
    }

    if (func_ov024_021ea7fc(ctx, (Struct_ov024_021e6a90_7*)action, var3)) {
        unsigned char mode = 0;
        int value = base;
        float floor = 0.0f;
        if (action->id == 1 || action->id == 0xdb || action->id == 0x1f9) {
            value = attacker->info->unknown_34_;
            mode = 1;
            floor = base;
            if (IsPartyMember(arg1)) {
                struct Struct_ov024_021e6a90_11* p = (struct Struct_ov024_021e6a90_11*)func_0200ff1c(gs, arg1);
                if (p) {
                    struct Struct_ov024_021e6a90_8* w = (struct Struct_ov024_021e6a90_8*)(p->field150 + 0x2f4);
                    if (w && (w->unknown_0_1_ || w->bit0)) {
                        mode = 0;
                        value = base;
                        floor = 0.0f;
                    }
                }
            }
        }
        var4 = 1.2f * var4;
        float v = func_02074838((short)value, mode, (Random*)ctx->battle);
        if (var4 < v) {
            var4 = v;
        }
        if (var4 < floor) {
            var4 = floor;
        }
    }

    var4 = var4 * func_ov000_02156b38(ctx->battle, targetId, action->elem);

    int elem = 0;
    signed char* tbl = data_ov024_021fe798;
    struct Struct_ov024_021e6a90_11* self = (struct Struct_ov024_021e6a90_11*)func_0200ff1c(gs, arg1);
    if (self) {
        for (; *tbl != -1; tbl += 2) {
            if (tbl[1] == func_02085748(self->field150)) {
                elem = tbl[0];
                break;
            }
        }
    }

    int var19 = 0;
    float var20 = 0;
    if (IsPartyMember(arg1) && func_0200ff1c(gs, arg1) &&
        (action->flags10 & 0x40000) && elem >= 1 && elem <= 7) {
        var20 = var4 * func_ov000_02156b38(ctx->battle, targetId, elem);
        var19 = 1;
    }

    float var21 = 0;
    if (target && action->elem == 8 && action->id != 0x1f9 && action->id != 0x205) {
        if (func_020886b0((Struct_020886b0*)attacker->stats)) {
            var21 = 1.1f * var4;
            var21 = var21 * (target->stats->unknown_3e_ / 100.0f);
        } else if (func_020886f8((Struct_020886f8*)attacker->stats)) {
            var21 = 1.1f * var4;
            var21 = var21 * (target->stats->unknown_3f_ / 100.0f);
        } else if (func_02088740((Struct_02088740*)attacker->stats)) {
            struct Struct_ov024_021e6a90_9* var22 = target->stats;
            float a = 1.1f * var4;
            a = a * (var22->unknown_41_ / 100.0f);
            float b = 1.1f * var4;
            b = b * (var22->unknown_40_ / 100.0f);
            var21 = b;
            if (b < a) {
                var21 = a;
            }
        } else if (func_02088788((Struct_02088788*)attacker->stats)) {
            struct Struct_ov024_021e6a90_9* var25 = target->stats;
            float a = 1.1f * var4;
            a = a * (var25->unknown_43_ / 100.0f);
            float b = 1.1f * var4;
            b = b * (var25->unknown_42_ / 100.0f);
            var21 = b;
            if (b < a) {
                var21 = a;
            }
        } else if (func_020887d0((Struct_020887d0*)attacker->stats)) {
            var21 = 1.1f * var4;
            var21 = var21 * (target->stats->unknown_44_ / 100.0f);
        }
        if (func_02088660((Struct_02088660*)attacker->stats)) {
            var19 = 1;
        }
    }

    if (var19) {
        if (var20 <= var21) {
            var4 = var21;
        } else {
            var4 = var20;
        }
    }

    if (IsPartyMember(arg1)) {
        struct Struct_ov024_021e6a90_11* p = (struct Struct_ov024_021e6a90_11*)func_0200ff1c(gs, arg1);
        if (p && (action->flags10 & 0x40000)) {
            if (func_ov000_02156068(ctx->battle, targetId, 1, 0)) {
                var4 = var4 * func_02085968((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 2, 0)) {
                var4 = var4 * func_02085818(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 3, 0)) {
                var4 = var4 * func_02085a10((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 4, 0)) {
                var4 = var4 * func_02085a48((Struct_02085a48*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 5, 0)) {
                var4 = var4 * func_020859d8((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 6, 0)) {
                var4 = var4 * func_020859a0((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 7, 0)) {
                var4 = var4 * func_02085930((char*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 8, 0)) {
                var4 = var4 * func_02085850(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 9, 0)) {
                var4 = var4 * func_020858f8(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 10, 0)) {
                var4 = var4 * func_02085a80((Struct_02085a80*)p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 11, 0)) {
                var4 = var4 * func_020858c0(p->field150);
            }
            if (func_ov000_02156068(ctx->battle, targetId, 12, 0)) {
                var4 = var4 * func_02085888(p->field150);
            }
        }
    }

    unsigned char forced;
    if (target) {
        struct Struct_ov024_021e6a90_9* var30 = target->stats;
        unsigned int var31 = var30->unknown_18_;
        if ((var31 & 2) && action->elem == 1) {
            var4 = 0.75f * var4;
        }
        if ((var31 & 4) && action->elem == 2) {
            var4 = 0.75f * var4;
        }
        if ((var30->unknown_14_ & 0x20000000) && func_ov000_02156068(ctx->battle, arg1, 8, 0)) {
            var4 = 0.5f * var4;
        }
        if (action->flags10 & 1) {
            if ((target->stats->unknown_14_ & 0x10000) && action->unknown_18_5_ != 2) {
                var4 = var4 * func_020748d0((signed char)target->stats->unknown_5a_2_);
            }
        }
        if ((action->flags10 & 4) && (target->stats->unknown_14_ & 0x20000)) {
            var4 = var4 * func_020748a8((signed char)target->stats->unknown_5a_5_);
        }
        if ((action->flags10 & 0x10) && target && ctx->battle->unknown_8e94_ == 0) {
            if (target->stats->unknown_21_ <= 3) {
                var4 = var4 * func_02074938((signed char)target->stats->unknown_21_);
            }
            if (func_ov024_021e67b0((GameObject*)target)) {
                var4 = var4 * func_02074938(1);
            }
            if (func_02086ef0((ArrayContainsByteStruct*)(GameState_GetParty(GameState::GetInstance())), targetId) &&
                target && target->stats->unknown_21_ == 1) {
                func_ov000_0215a8d4((unsigned char*)ctx->battle, 0);
            }
        }
    }

    if (action->id == 0x82 && target->stats->unknown_21_ != 3) {
        var4 = 1.0f;
    }

    forced = 0;
    if (IsPartyMember(arg1)) {
        struct Struct_ov024_021e6a90_11* p = (struct Struct_ov024_021e6a90_11*)func_0200ff1c(gs, arg1);
        if (p) {
            if (action->flags10 & 0x80000) {
                if (func_02085154(p->field150)) {
                    ctx->flags->bit2 = 0;
                }
            }
            if ((action->flags10 & 0x40000) && func_020851d8(p->field150)) {
                var4 = 1.0f;
                forced = 1;
                ctx->flags->bit2 = 0;
                ctx->flags->unknown_1c_1_ = 0;
            }
        }
    }

    if (var4 > 0) {
        if (var4 > 0 && ctx->flags->bit2) {
            var4 = 0;
        }
        if (var4 > 0 && ctx->flags->unknown_1c_1_) {
            var4 = 0;
        }
    }

    if (func_ov000_02156068(ctx->battle, targetId, 0, 1) && (action->flags10 & 0x1000000) &&
        (action->kind == 1 || action->id == 0xdb) && !var3 && action->id != 0x205 &&
        action->id != 0x82) {
        if (!forced) {
            var4 = 0;
        }
    }

    if (var4 <= 0) {
        int var33 = 1;
        if (ctx->flags->bit2) {
            var33 = 0;
        }
        if (ctx->flags->unknown_1c_1_) {
            var33 = 0;
        }
        if (action->id == 0x70) {
            var33 = 0;
        }
        if (action->id == 0x48) {
            var33 = 0;
        }
        if (func_ov000_02156b38(ctx->battle, targetId, action->elem) <= 0) {
            var33 = 0;
        }
        if (func_ov000_02156b38(ctx->battle, targetId, elem) <= 0) {
            var33 = 0;
        }
        if (action->id == 0x1b) {
            var33 = 0;
        }
        if (func_ov000_02156068(ctx->battle, targetId, 0, 1) && !(action->flags10 & 0x1000000)) {
            var33 = 0;
        }
        if (var33) {
            var4 = NextRandomMax((Random*)ctx->battle, 2);
        }
    }

    if (func_ov000_02156068(ctx->battle, targetId, 0, 1)) {
        if (!var3 && (action->id == 0x40 || action->id == 0x7e)) {
            var4 = 1.0f + NextRandomMax((Random*)ctx->battle, 2);
        }
        if (IsPartyMember(arg1)) {
            struct Struct_ov024_021e6a90_11* p = (struct Struct_ov024_021e6a90_11*)func_0200ff1c(gs, arg1);
            if (p && (action->flags10 & 0x40000) && func_02085128(p->field150)) {
                var4 += 1.0f;
            }
        }
        if (ctx->unknown_76_ && (action->flags10 & 0x2000) &&
            (func_ov024_021da998((Struct_ov024_021da670_6*)attacker) ||
             func_ov024_021dd260((Struct_ov024_021dd028_5*)attacker))) {
            float mult;
            if (IsPartyMember(arg1)) {
                mult = func_02074738(attacker->stats->unknown_24_, 0);
            } else {
                mult = func_02074738(attacker->stats->unknown_24_, 1);
            }
            var4 = var4 * mult;
        }
    }

    if (func_ov024_021dd260((Struct_ov024_021dd028_5*)target) && action->unknown_18_5_ == 1) {
        var4 = 0.5f * var4;
    }

    if (action->unknown_2f_3_ && var4 >= 1.0f) {
        struct Struct_ov024_021fe778 scales = data_ov024_021fe778;
        signed char level = ctx->battle->unknown_8e83_;
        if (level > 3) {
            level = 3;
        }
        var4 = var4 * scales.v[level];
        ctx->hud->show = 0;
        if (level != 0) {
            ctx->hud->level = level;
        }
    } else {
        func_ov000_0215cd80(ctx->battle);
    }

    int result = var4;
    if (action->cap != 0 && action->cap < result) {
        result = action->cap;
    }
    if (action->id == 0xaf) {
        ctx->battle->unknown_8e38_ = 0.25f * result;
    }
    return result;
}
