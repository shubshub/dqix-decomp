#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* p);
extern "C" int func_020882f8(unsigned char* p);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* p);
struct Struct_02088660;
extern "C" int func_02088660(struct Struct_02088660* p);
struct Struct_ov024_021fa7ec_5;
extern "C" int func_ov024_021fb430(struct Struct_ov024_021fa7ec_5* p);
struct Struct_ov024_021fa7ec_6;
extern "C" int func_ov024_021fb448(struct Struct_ov024_021fa7ec_6* p);
struct Struct_ov024_021fa7ec_8;
extern "C" int func_ov024_021fb478(struct Struct_ov024_021fa7ec_8* p);
struct Struct_ov024_021eda78_5;
extern "C" int func_ov024_021edc08(struct Struct_ov024_021eda78_5* p);
struct Struct_ov024_021e4604;
extern "C" int func_ov024_021e47dc(struct Struct_ov024_021e4604* p);
struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f6a4c(void* dst, void* src);
extern "C" void func_ov024_021fd858(void* obj);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Struct_ov024_021fd954 {
    char pad0[4];
    short id;
    char pad6[0x138 - 0x6];
    struct ModifiableCombatStats* stats;
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    unsigned char* field150;
};

struct Struct_ov024_021fd954* GetCombatantByID(int unused, int id);

struct Struct_ov024_021fd954_2 {
    float value;
    unsigned char id;
    unsigned char flag5;
    unsigned char index;
    unsigned char unknown_7_;
    unsigned char code;
};
struct Struct_ov024_021fd954_3 {
    char raw[0xc8];
    Struct_ov024_021fd954_3() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fd954_4 {
    char pad0[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[4];
    unsigned int flags10;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int kind : 5;
    unsigned int pad18 : 27;
};
struct Struct_ov024_021fd954_5 {
    char pad[0x8e18];
    unsigned char* partyWork;
};
struct Struct_ov024_021fbec4 {
    struct Struct_ov024_021fd954_5* battle;
    short field4;
    struct Struct_ov024_021fd954* actor;
    char unknown_c_[0x64c - 0xc];
    struct Struct_ov024_021fd954_4* action;
    char unknown_650_[0x658 - 0x650];
    struct Struct_ov024_021fd954_3* list;
    struct Struct_ov024_021fd954_2 entry;
    struct Struct_ov024_021fd954* target;
    int targetId;
};

// USA: func_ov024_021fd954
extern "C" ARM void func_ov024_021fd954(struct Struct_ov024_021fbec4* obj, int arg1) {
    struct Struct_ov024_021fd954_4* action;
    int var1;
    int i;
    struct Struct_ov024_021fd954* c;
    int found;
    struct Struct_ov024_021fd954* actor;
    actor = obj->actor;
    func_02053c6c((unsigned char*)actor);
    action = obj->action;
    if (action->mode == 1) return;
    var1 = action->unknown_17_4_;
    if (var1 == 6) {
        if (func_02083b00(actor->field150, 0xe6)) {
            var1 = 3;
        } else {
            var1 = 2;
        }
    }
    if (var1 != 2 && var1 != 1 && var1 != 4 && var1 != 3) return;

    struct Struct_ov024_021fd954_3 list;
    memset(&list, 0, sizeof(list));
    found = 0;
    for (i = 0; i < 4; i++) {
        if (var1 == 1 && i != obj->field4) continue;
        if (!func_020a35e0(obj->battle->partyWork, i & 0xff)) continue;
        c = GetCombatantByID((int)obj->battle, (short)i);
        if (!c) continue;
        if (func_02010088((struct S_10088*)c)) continue;
        if ((action->flags10 & 0x400) && (*(unsigned int*)((char*)c->stats + 0x14) & 0x200)) continue;

        bool ok = false;
        int code = 8;
        if (arg1 == 2) {
            if (func_02088514((struct Struct_02088514*)c->stats)) ok = true;
        } else if (arg1 == 3) {
            if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) ok = true;
        } else if (arg1 == 4) {
            if (func_020882f8((unsigned char*)c->stats)) ok = true;
        } else if (arg1 == 7) {
            if (func_ov024_021de25c((struct Struct_ov024_021de124*)c)) ok = true;
        } else if (arg1 == 0x11) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->attackBuff <= 0) ok = true;
            if (s->primaryStats.attack >= 999) ok = false;
            code = 7;
        } else if (arg1 == 0x12) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->defenseBuff <= 0) ok = true;
            if (s->primaryStats.defense >= 999) ok = false;
            code = 7;
        } else if (arg1 == 0x13) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->agilityBuff <= 0) ok = true;
            if (s->primaryStats.agility >= 999) ok = false;
            code = 7;
        } else if (arg1 == 0x14) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->magicalMightBuff <= 0) ok = true;
            if ((unsigned short)s->primaryStats.magicalMight >= 999) ok = false;
            code = 7;
        } else if (arg1 == 0x15) {
            struct ModifiableCombatStats* s = c->stats;
            if (s->magicalMendingBuff <= 0) ok = true;
            if ((unsigned short)s->primaryStats.magicalMending >= 999) ok = false;
            code = 7;
        } else if (arg1 == 0x16) {
            if (c->stats->unknown_5a_2_ <= 0) ok = true;
            code = 7;
        } else if (arg1 == 0x17) {
            if ((((*(int*)((char*)c->stats + 0x58)) << 8) >> 29) <= 0) ok = true;
            code = 7;
        } else if (arg1 == 0xd) {
            if (!func_02088660((struct Struct_02088660*)c->stats)) ok = true;
            code = 7;
        } else if (arg1 == 0xe) {
            if (!func_ov024_021fb430((struct Struct_ov024_021fa7ec_5*)c) && !func_ov024_021fb448((struct Struct_ov024_021fa7ec_6*)c)
                && !func_ov024_021fb478((struct Struct_ov024_021fa7ec_8*)c)) ok = true;
            code = 7;
        } else if (arg1 == 0xf) {
            if (!func_ov024_021fb430((struct Struct_ov024_021fa7ec_5*)c) && !func_ov024_021fb448((struct Struct_ov024_021fa7ec_6*)c)
                && !func_ov024_021fb478((struct Struct_ov024_021fa7ec_8*)c)) ok = true;
            code = 7;
        } else if (arg1 == 0x10) {
            if (!func_ov024_021edc08((struct Struct_ov024_021eda78_5*)c)) ok = true;
            code = 7;
        } else if (arg1 == 0xb) {
            if (!func_ov024_021e47dc((struct Struct_ov024_021e4604*)c)) ok = true;
            code = 7;
        }

        struct Struct_ov024_021fd954_2 e;
        memset(&e, 0, sizeof(e));
        int var15 = 50;
        if (ok) {
            var15 = 100;
            found = 1;
        }
        e.value = 0.0f;
        e.id = arg1;
        e.flag5 = 0;
        e.index = i;
        e.unknown_7_ = var15;
        e.code = code;
        func_ov024_021f6a1c((struct Struct_ov024_021f6a1c*)&list, &e);
        if (action->kind != 0) {
            obj->list = &list;
            func_ov024_021f6a4c(&obj->entry, &e);
            obj->target = c;
            obj->targetId = c->id;
            func_ov024_021fd858(obj);
        }
        if (var1 == 2 || var1 == 1) {
            int value = (unsigned char)c->id;
            if (found) func_ov024_021f9874(obj, &list, 0, value);
            memset(&list, 0, sizeof(list));
            found = 0;
        }
    }
    if (var1 == 4 || var1 == 3) {
        GetCombatantByID((int)obj->battle, 0);
        int value = (unsigned char)actor->id;
        if (var1 == 3) value = 0xff;
        if (found) func_ov024_021f9874(obj, &list, 0, value);
    }
}
