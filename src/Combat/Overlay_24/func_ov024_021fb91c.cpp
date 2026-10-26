#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021fb91c_4 {
    unsigned int field_0x0;
    unsigned int code : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 22;
    unsigned int unknown_c_;
    unsigned int flags;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int kind : 5;
    unsigned int range : 7;
    unsigned int unknown_19_4_ : 20;
};
struct Struct_ov024_021fb91c_5 {
    float value;
    unsigned char id, flag, index, unknown_7_, kind, unknown_9_;
    unsigned char padding[2];
};
struct Struct_ov024_021f6a1c {
    Struct_ov024_021fb91c_5 entries[16];
    int count;
    float threshold;
    Struct_ov024_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fb91c_6 {
    unsigned char padding[0x3ec];
    int unknown_3ec_;
    Struct_ov024_021fb91c_4* action;
    unsigned char unknown_3f4_[5];
    unsigned char unknown_3f9_;
    unsigned char unknown_3fa_[2];
    Struct_ov024_021f6a1c* list;
    Struct_ov024_021fb91c_5 unknown_400_;
    GameObject* target;
    int targetIndex;
};
struct Struct_ov024_021fb91c {
    unsigned char padding[0x8e18];
    unsigned char* partyWork;
};
struct Struct_ov024_021fb91c_2 {
    Struct_ov024_021fb91c* battle;
    short id;
    unsigned short unknown_6_;
    GameObject* actor;
    unsigned char unknown_c_[0x114 - 0xc];
    float unknown_114_[4];
    float threshold;
    int unknown_128_;
    unsigned char unknown_12c_[0x25c - 0x12c];
    Struct_ov024_021fb91c_6 work;
};
struct Struct_ov024_021fb91c_3 {
    PrimaryCombatStats primary;
    unsigned int flags;
    unsigned char padding[0x24 - 0x18];
    signed char rate;
};
struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
struct S_10088;
extern "C" int func_02053c6c(unsigned char*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" float func_02074738(int, int);
extern "C" void func_ov024_021f6a1c(Struct_ov024_021f6a1c*, void*);
extern "C" void func_ov024_021f8938(void*, float*, float*, int, void*, GameObject*);
extern "C" void func_ov024_021f6a4c(void*, void*);
extern "C" void func_ov024_021fd858(void*);
extern "C" void func_ov024_021f9874(void*, void*, int, int);

static inline unsigned int inline_ov024_021fb91c(GameObject* actor) { return actor->currentStats_->primaryStats.maxHP; }

// USA: func_ov024_021fb91c
extern "C" ARM void func_ov024_021fb91c(Struct_ov024_021fb91c_2* context) {
    Struct_ov024_021fb91c_4* action = context->work.action;
    if (action->mode == 1) return;
    float threshold = context->threshold;
    int var2 = 1;
    if (context->unknown_114_[context->unknown_128_] >= threshold) var2 = 0;
    if (!var2 && action->kind == 0) return;
    GameObject* actor = context->actor;
    func_02053c6c((unsigned char*)actor);
    func_020797dc();
    int var4 = context->work.unknown_3ec_;
    float value = 0;
    float var6 = 0;
    func_ov024_021f8938(context, &value, &var6, var4, context->work.action, actor);
    if (action->code == 0x21) {
        value = 999.0f;
        var6 = 999.0f;
    }
    if ((action->flags & 0x2000) &&
        (func_ov024_021da998((Struct_ov024_021da670_6*)actor) ||
        func_ov024_021dd260((Struct_ov024_021dd028_5*)actor))) {
        float var7 = func_02074738(((Struct_ov024_021fb91c_3*)actor->currentStats_)->rate, 0);
        value *= var7;
        var6 *= var7;
    }
    Struct_ov024_021f6a1c list;
    memset(&list, 0, sizeof(list));
    for (int index = 0; index < 4; ++index) {
        if (!func_020a35e0(context->battle->partyWork, index)) continue;
        if (action->unknown_17_4_ == 1 && index != context->id) continue;
        if (action->unknown_17_4_ == 8 && index == context->id) continue;
        GameObject* target = GetCombatantByID((int)context->battle, (short)index);
        if (!target) continue;
        if (func_02010088((S_10088*)target)) continue;
        context->work.unknown_3f9_ = 1;
        if (context->unknown_114_[index] >= threshold) context->work.unknown_3f9_ = 0;
        if (!context->work.unknown_3f9_ && action->kind == 0) continue;
        if ((action->flags & 0x400) && (((Struct_ov024_021fb91c_3*)target->currentStats_)->flags & 0x200)) continue;
        float amount = value;
        int hp = target->currentStats_->primaryStats.currHP;
        int maximum = target->currentStats_->primaryStats.maxHP;
        if (action->code == 0x1fa) amount = 0.4f * (float)maximum;
        if (action->range == 14) {
            if ((float)hp / (float)maximum > 0.08f) continue;
            unsigned int var14 = inline_ov024_021fb91c(actor);
            unsigned int var15 = actor->currentStats_->primaryStats.currHP;
            if (((float)var15 - amount) / (float)var14 < 0.5f) continue;
            amount *= 0.3f;
        }
        maximum -= hp;
        if (amount > (float)maximum) amount = (float)maximum;
        Struct_ov024_021fb91c_6* work = &context->work;
        Struct_ov024_021fb91c_5 entry;
        entry.flag = 0;
        entry.unknown_7_ = 100;
        entry.kind = 3;
        entry.value = amount;
        entry.index = index;
        func_ov024_021f6a1c(&list, &entry);
        if (action->kind != 0) {
            context->work.list = &list;
            func_ov024_021f6a4c(&work->unknown_400_, &entry);
            context->work.target = target;
            context->work.targetIndex = index;
            func_ov024_021fd858(context);
        }
        if (action->unknown_17_4_ == 2 || action->unknown_17_4_ == 1 || action->unknown_17_4_ == 8) {
            func_ov024_021f9874(context, &list, 0, (unsigned char)target->obj3D_.actorIndex_);
            memset(&list, 0, sizeof(list));
        }
    }
    if (action->unknown_17_4_ == 4 || action->unknown_17_4_ == 3) {
        GetCombatantByID((int)context->battle, 0);
        int target = (unsigned char)actor->obj3D_.actorIndex_;
        if (action->unknown_17_4_ == 3) target = 0xff;
        func_ov024_021f9874(context, &list, 0, target);
    }
}
