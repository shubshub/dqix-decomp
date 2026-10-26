#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_ov024_021fb490 {
    unsigned int field_0x0;
    unsigned int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 4;
    unsigned int key : 8;
    unsigned int unknown_a_6_ : 10;
    unsigned int unknown_c_;
    unsigned int flags;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_;
    unsigned int unknown_1c_0_ : 14;
    unsigned int range : 5;
    unsigned int unknown_1e_3_ : 13;
};
struct Struct_ov024_021fb490_7 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};
struct Struct_ov024_021fb490_8 {
    float value;
    unsigned char id, flag, index, unknown_7_, kind;
    Struct_ov024_021fb490_7 unknown_9_;
    unsigned char padding[2];
};
struct Struct_ov024_021f6a1c {
    Struct_ov024_021fb490_8 entries[16];
    int count;
    float threshold;
    Struct_ov024_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fb490_2 {
    unsigned char padding[0xa];
    unsigned short unused : 12;
    unsigned short flag : 1;
};
struct Struct_ov024_021fb490_3 {
    unsigned char unknown_0_[4];
    short unknown_4_;
    unsigned char unknown_6_[0x138 - 6];
    unsigned int* stats;
    unsigned char unknown_13c_[0x144 - 0x13c];
    struct Struct_ov024_021fb490_2* info;
    unsigned char unknown_148_[0x17c - 0x148];
    unsigned char group;
    unsigned char inline_ov024_021fb490() const { return group; }
};
struct Struct_ov024_021fb490_4 {
    unsigned char padding[0x3ec];
    int unknown_3ec_;
    Struct_ov024_021fb490* action;
    unsigned char unknown_3f4_[5];
    unsigned char unknown_3f9_;
    unsigned char unknown_3fa_[2];
    Struct_ov024_021f6a1c* list;
    Struct_ov024_021fb490_8 unknown_400_;
    Struct_ov024_021fb490_3* target;
    int targetIndex;
};
struct Struct_ov024_021fb490_5 {
    unsigned char unknown_0_[8];
    unsigned char* actor;
    unsigned char unknown_c_[0x2c - 0xc];
    unsigned char unknown_2c_;
    unsigned char unknown_2d_[0x34 - 0x2d];
    unsigned char unknown_34_;
    unsigned char unknown_35_[0x7c - 0x35];
    Struct_ov024_021fb490_3* unknown_7c_[8];
    int count;
    unsigned char unknown_a0_[0x25c - 0xa0];
    Struct_ov024_021fb490_4 work;
};
struct Struct_ov024_021fb490_6 { unsigned int bit0 : 1; unsigned int unknown_0_1_ : 1; };
struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;

extern "C" int func_02053c6c(unsigned char*);
extern "C" void* func_020797dc();
extern "C" void* func_02079ee0(void*, int);
extern "C" float func_02074948(int);
extern "C" float _fmul(float, float);
extern "C" int _fgeq(float, float);
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" void func_ov024_021f6a1c(Struct_ov024_021f6a1c*, void*);
extern "C" void func_ov024_021f8938(void*, float*, float*, int, void*, void*);
extern "C" void func_ov024_021fa7ec(void*, float*, float*, float*, int*, float, float, void*, void*, int);
extern "C" void func_ov024_021f8d80(void*, int*, void*, void*, int, float*, float*, int, void*);
extern "C" void func_ov024_021f6a4c(void*, void*);
extern "C" void func_ov024_021fd858(void*);
extern "C" void func_ov024_021f9874(void*, void*, int, int);

struct Struct_ov024_021ff002 {
    unsigned char a;
    unsigned char b;
    unsigned char unknown_2_;
};
extern const Struct_ov024_021ff002 data_ov024_021ff002[];

// USA: func_ov024_021fb490
extern "C" ARM void func_ov024_021fb490(Struct_ov024_021fb490_5* context) {
#if defined(jpn)
    enum { regionalOffset0 = 0x144 };
#else
    enum { regionalOffset0 = 0x150 };
#endif
    float hi[8];
    float lo[8];
    float var2[8];
    Struct_ov024_021fb490* action;
    void* data;
    int total;
    void* element;
    unsigned char* actor;
    Struct_ov024_021fb490_3** var8;
    actor = context->actor;
    func_02053c6c(context->actor);
    data = func_020797dc();
    action = context->work.action;
    int var9 = context->work.unknown_3ec_;
    if (action->mode == 2) return;
    float value;
    float var11;
    int outIndex;
    value = 0;
    var11 = 0;
    outIndex = -1;
    func_ov024_021f8938(context, &value, &var11, var9, action, actor);
    var8 = context->unknown_7c_;
    total = context->count;
    element = func_02079ee0(data, action->key);
    for (int j = 0; j < total; j++) {
        lo[j] = 0;
        var2[j] = 0;
        hi[j] = 0;
        float* var14 = &hi[j];
        float* var15 = &lo[j];
        float* var16 = &var2[j];
        Struct_ov024_021fb490_3* unit = var8[j];
        if (!unit->info || !unit->info->flag || (action->flags & 0x1000000)) {
            func_ov024_021fa7ec(context, var14, var15, var16, &outIndex, value, var11, element, unit, j);
        }
    }
    int kind = action->unknown_17_4_;
    if (kind == 5) {
        char* p = (char*)(*(int**)(actor + regionalOffset0)) + 0x2f4;
        if (p) {
            Struct_ov024_021fb490_6* bits = (Struct_ov024_021fb490_6*)p;
            if (bits->unknown_0_1_) kind = 3;
            else if (bits->bit0) kind = 4;
            else kind = 2;
        }
    }
    if (kind != 2 && kind != 4 && kind != 3) return;
    unsigned int row = action->range;
    short a;
    short b;
    unsigned char var24;
    int var25;
    if (row <= 11) {
        a = data_ov024_021ff002[row].a;
        b = data_ov024_021ff002[row].b;
        var25 = a * b;
        var24 = data_ov024_021ff002[row].unknown_2_;
    } else {
        return;
    }
    int selected = -1;
    if (kind == 2 && a == 1) {
        func_ov024_021f8d80(context, &selected, action, context->unknown_7c_, context->count, var2, lo, var25, actor);
    }
    Struct_ov024_021f6a1c list;
    memset(&list, 0, sizeof(list));
    int count = 0;
    int flag = 0;
    int var30 = 0;
    int i = 0;
    unsigned char weight = var25;
    for (; i < context->count; i++) {
        context->unknown_2c_ = 0;
        if (selected >= 0 && selected != i) continue;
        if (outIndex == i) context->unknown_34_ = 1;
        count++;
        Struct_ov024_021fb490_3* unit = var8[i];
        if (action->flags & 0x400) {
            if (unit->stats[0x14 / 4] & 0x200) flag = 1;
        }
        if (kind != 2 && (context->work.action->flags & 0x20000)) {
            var2[i] = _fmul(var2[i], func_02074948((signed char)var30));
            var30++;
        }
        Struct_ov024_021fb490_8 entry;
        entry.flag = 1;
        entry.unknown_7_ = 100;
        entry.kind = 0;
        entry.value = var2[i];
        entry.index = i;
        entry.unknown_9_.weight = weight;
        entry.unknown_9_.flag = var24;
        func_ov024_021f6a1c(&list, &entry);
        if (hi[i] >= 0.1f && !func_ov024_021da998((Struct_ov024_021da670_6*)actor) &&
            !func_ov024_021dd260((Struct_ov024_021dd028_5*)actor)) {
            context->work.list = &list;
            func_ov024_021f6a4c(&context->work.unknown_400_, &entry);
            context->work.target = unit;
            context->work.targetIndex = i;
            func_ov024_021fd858(context);
        }
        int last = 0;
        if (i == context->count - 1) last = 1;
        else if (kind == 2) last = 1;
        else if (kind == 4) {
            if (unit->inline_ov024_021fb490() != var8[i + 1]->inline_ov024_021fb490()) last = 1;
        }
        if (!last) continue;
        if (count >= 2) {
            if (var24) flag = 1;
        }
        if (count <= 1) var24 = 0;
        if (!flag) {
            int p3 = (unsigned char)unit->unknown_4_;
            int p2 = unit->inline_ov024_021fb490();
            if (kind == 4) p3 = 0xff;
            else if (kind == 3) { p3 = 0xff; p2 = p3; }
            func_ov024_021f9874(context, &list, p2, p3);
        }
        memset(&list, 0, sizeof(list));
        count = 0;
        flag = 0;
        var30 = 0;
    }
}
