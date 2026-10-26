#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct_ov024_021fdf04 {
    PrimaryCombatStats primaryStats;
    unsigned int unknown_14_;
    unsigned char pad18[0x21 - 0x18];
    unsigned char unknown_21_;
    unsigned char unknown_22_[0x58 - 0x22];
    signed int unknown_58_0_ : 3;
    signed int unknown_58_3_ : 3;
    signed int unknown_58_6_ : 3;
    signed int unknown_59_1_ : 3;
    signed int unknown_59_4_ : 3;
    signed int unknown_59_7_ : 3;
    signed int unknown_5a_2_ : 3;
    signed int unknown_5a_5_ : 3;
};
struct Struct_ov024_021fdf04_7 {
    unsigned char padding[0xa];
    unsigned short unused : 11;
    unsigned short flag : 1;
};
struct Struct_ov024_021fdf04_8 {
    unsigned char unknown_0_[4];
    short unknown_4_;
    unsigned char unknown_6_[0x138 - 6];
    Struct_ov024_021fdf04* stats;
    unsigned char unknown_13c_[0x144 - 0x13c];
#if defined(jpn)
    union {
        Struct_ov024_021fdf04_7* info;
        unsigned char* field150;
    };
    unsigned char unknown_148_[0x17c - 0x148];
#else
    Struct_ov024_021fdf04_7* info;
    unsigned char unknown1_148_[0x150 - 0x148];
    unsigned char* field150;
    unsigned char unknown_154_[0x17c - 0x154];
#endif
    unsigned char group;
    unsigned char inline_ov024_021fdf04() const { return group; }
};
struct Struct_ov024_021fdf04_2 {
    unsigned int field_0x0;
    unsigned int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 22;
    unsigned int unknown_c_;
    unsigned int flags;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
    unsigned int unknown_1c_0_ : 14;
    unsigned int range : 5;
    unsigned int unknown_1e_3_ : 13;
    unsigned int unknown_20_[4];
    short unknown_30_;
};
struct Struct_ov024_021fdf04_3 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};
struct Struct_ov024_021fdf04_4 {
    float value;
    unsigned char id, flag, index, unknown_7_, kind;
    Struct_ov024_021fdf04_3 unknown_9_;
    unsigned char padding[2];
};
struct Struct_ov024_021f6a1c {
    Struct_ov024_021fdf04_4 entries[16];
    int count;
    float threshold;
    Struct_ov024_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fdf04_5 {
    unsigned char unknown_0_[8];
    Struct_ov024_021fdf04_8* actor;
    unsigned char unknown_c_[0x7c - 0xc];
    Struct_ov024_021fdf04_8* unknown_7c_[8];
    int count;
    unsigned char unknown_a0_[0x64c - 0xa0];
    Struct_ov024_021fdf04_2* action;
};
struct Struct_ov024_021fdf04_6 { unsigned int bit0 : 1; unsigned int unknown_0_1_ : 1; };
struct Struct_ov024_021fefea { unsigned char weight; unsigned char unknown_1_; };
extern const Struct_ov024_021fefea data_ov024_021fefea[];

extern "C" int func_02053c6c(unsigned char*);
extern "C" void* func_020797dc();
extern "C" void func_ov024_021f8bd8(Struct_ov024_021fdf04_5*, float*, Struct_ov024_021fdf04_8*, Struct_ov024_021fdf04_2*);
extern "C" void __clear(void*, int);
struct Struct_ov024_021fa7ec_7;
extern "C" int func_ov024_021fb460(Struct_ov024_021fa7ec_7*);
struct Struct_ov024_021fa7ec_8;
extern "C" int func_ov024_021fb478(Struct_ov024_021fa7ec_8*);
extern "C" float func_020748d0(int v);
extern "C" float func_020748a8(int v);
extern "C" float func_02074938(int v);
extern "C" int func_ov024_021e67b0(GameObject*);
extern "C" float func_ov024_021f875c(Struct_ov024_021fdf04_5*, Struct_ov024_021fdf04_8*, Struct_ov024_021fdf04_2*, int);
extern "C" int func_020882f8(unsigned char*);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(Struct_ov024_021da670_7*);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(Struct_ov024_021de124*);
struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(Struct_ov024_021da670_8*);
struct Struct_021fa76c;
extern "C" int func_ov024_021fa76c(Struct_021fa76c*);
extern "C" void func_ov024_021f6a1c(Struct_ov024_021f6a1c*, void*);
extern "C" void func_ov024_021f9874(Struct_ov024_021fdf04_5*, Struct_ov024_021f6a1c*, int, int);

// USA: func_ov024_021fdf04
extern "C" ARM void func_ov024_021fdf04(Struct_ov024_021fdf04_5* context, int arg1) {
    Struct_ov024_021fdf04_8* actor = context->actor;
    func_02053c6c((unsigned char*)actor);
    func_020797dc();

    Struct_ov024_021fdf04_2* action = context->action;
    if (action->mode == 2) return;

    float base = 1.0f;
    func_ov024_021f8bd8(context, &base, actor, action);

    int total = context->count;
    float rates[8];
    Struct_ov024_021fdf04_8** var5 = context->unknown_7c_;
    __clear(rates, sizeof(rates));

    for (int i = 0; i < total; i++) {
        Struct_ov024_021fdf04_8* unit = var5[i];
        float rate = 1.0f;
        float scale = base;

        if (action->flags & 1) {
            if (func_ov024_021fb460((Struct_ov024_021fa7ec_7*)unit) && action->unknown_18_5_ != 2) {
                rate = rate * func_020748d0((signed char)unit->stats->unknown_5a_2_);
            }
        }
        if (action->flags & 4) {
            if (func_ov024_021fb478((Struct_ov024_021fa7ec_8*)unit)) {
                rate = rate * func_020748a8((signed char)unit->stats->unknown_5a_5_);
            }
        }
        if (action->flags & 0x10) {
            if (unit->stats->unknown_21_ <= 3) {
                rate = rate * func_02074938((signed char)unit->stats->unknown_21_);
            } else if (func_ov024_021e67b0((GameObject*)unit)) {
                rate = rate * func_02074938(1);
            }
        }
        rate = rate * func_ov024_021f875c(context, unit, action, 1);
        rates[i] = scale * rate;
    }

    int kind = action->unknown_17_4_;
    if (kind == 5) {
        unsigned char* p = actor->field150 + 0x2f4;
        if (p) {
            Struct_ov024_021fdf04_6* bits = (Struct_ov024_021fdf04_6*)p;
            if (bits->unknown_0_1_) kind = 3;
            else if (bits->bit0) kind = 4;
            else kind = 2;
        }
    }
    if (kind != 2 && kind != 4 && kind != 3) return;

    unsigned int row = action->range;
    unsigned char weight;
    unsigned char var15;
    if (row <= 11) {
        var15 = data_ov024_021fefea[row].unknown_1_;
        weight = data_ov024_021fefea[row].weight;
    } else {
        return;
    }

    Struct_ov024_021f6a1c list;
    memset(&list, 0, sizeof(list));
    Struct_ov024_021fdf04_4 entry;

    int count = 0;
    int flag = 0;

    for (long i = 0; i < context->count; i++) {
        int var21 = 1;
        count++;
        Struct_ov024_021fdf04_8* unit = var5[i];

        if (action->flags & 0x400) {
            if (unit->stats->unknown_14_ & 0x200) flag = 1;
        }
        if (rates[i] < 30.0f) var21 = 0;

        if (var21) {
            int code = 5;
            int ok = 0;
            int check = 0;
            float threshold = 33.3f;

            if (arg1 == 4) {
                if (func_020882f8((unsigned char*)unit->stats) == 0) ok = 1;
                check = 1;
                threshold = 35.0f;
            } else if (arg1 == 5) {
                if ((unit->stats->unknown_14_ & 0x40) == 0) ok = 1;
                check = 1;
                threshold = 35.0f;
            } else if (arg1 == 3) {
                if (func_ov024_021da9b0((Struct_ov024_021da670_7*)unit) == 0) ok = 1;
                check = 1;
            } else if (arg1 == 6) {
                if (func_ov024_021dd010((Struct_ov024_021dced0_2*)unit) == 0) ok = 1;
                check = 1;
            } else if (arg1 == 7) {
                if (func_ov024_021de25c((Struct_ov024_021de124*)unit) == 0) ok = 1;
                check = 1;
                threshold = 35.0f;
            } else if (arg1 == 8) {
                if (func_ov024_021da9c8((Struct_ov024_021da670_8*)unit) == 0) ok = 1;
                check = 1;
                if (action->unknown_30_ == 2) {
                    Struct_ov024_021fdf04_7* info = unit->info;
                    if (info != 0) {
                        if (info->flag) ok = 0;
                    }
                }
                threshold = 50.0f;
            } else if (arg1 == 9) {
                if (rates[i] >= 30.0f) ok = 1;
                code = 2;
            } else if (arg1 == 0x11) {
                Struct_ov024_021fdf04* s = unit->stats;
                if (s->unknown_58_0_ >= -1) ok = 1;
                if (s->primaryStats.attack <= 40) ok = 0;
                code = 5;
            } else if (arg1 == 0x12) {
                Struct_ov024_021fdf04* s = unit->stats;
                if (s->unknown_58_3_ >= -1) ok = 1;
                if (s->primaryStats.defense <= 20) ok = 0;
                code = 5;
            } else if (arg1 == 0x13) {
                Struct_ov024_021fdf04* s = unit->stats;
                if (s->unknown_58_6_ >= -1) ok = 1;
                if (s->primaryStats.agility <= 40) ok = 0;
                code = 5;
            } else if (arg1 == 0x14) {
                Struct_ov024_021fdf04* s = unit->stats;
                if (s->unknown_59_4_ >= -1) ok = 1;
                if ((unsigned short)s->primaryStats.magicalMight <= 100) ok = 0;
                code = 5;
            } else if (arg1 == 0x15) {
                Struct_ov024_021fdf04* s = unit->stats;
                if (s->unknown_59_7_ >= -1) ok = 1;
                if ((unsigned short)s->primaryStats.magicalMending <= 100) ok = 0;
                code = 5;
            } else if (arg1 == 0x16) {
                if (unit->stats->unknown_5a_2_ >= -1) ok = 1;
                code = 5;
            }

            if (!check || func_ov024_021fa76c((Struct_021fa76c*)unit)) {
                if (rates[i] < threshold) ok = 0;
                if (ok) {
                    entry.value = action->unknown_30_;
                    entry.index = i;
                    entry.id = arg1;
                    entry.flag = 1;
                    entry.unknown_7_ = rates[i];
                    entry.kind = code;
                    entry.unknown_9_.weight = weight;
                    entry.unknown_9_.flag = var15;
                    func_ov024_021f6a1c(&list, &entry);
                }
            } else {
                continue;
            }
        }

        int last = 0;
        if (i == context->count - 1) last = 1;
        else if (kind == 2) last = 1;
        else if (kind == 4) {
            if (unit->inline_ov024_021fdf04() != var5[(int)i + 1]->inline_ov024_021fdf04()) last = 1;
        }
        if (!last) continue;
        if (count >= 2) {
            if (var15) flag = 1;
        }
        if (count <= 1) var15 = 0;
        if (!flag) {
            int p3 = (unsigned char)unit->unknown_4_;
            int p2 = unit->inline_ov024_021fdf04();
            if (kind == 4) p3 = 0xff;
            else if (kind == 3) { p3 = 0xff; p2 = p3; }
            func_ov024_021f9874(context, &list, p2, p3);
        }
        memset(&list, 0, sizeof(list));
        count = 0;
        flag = 0;
    }
}
