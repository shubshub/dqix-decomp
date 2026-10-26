#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int unused, int val);

struct Struct_ov024_021fc4f4_4 {
    float value;
    unsigned char id;
    unsigned char flag5;
    unsigned char index;
    unsigned char unknown_7_;
    unsigned char code;
};
struct Struct_ov024_021fc4f4_5 {
    char raw[0xc8];
    Struct_ov024_021fc4f4_5() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fc4f4_6 { char pad0[4]; short id; };
struct Struct_ov024_021fc4f4_7 {
    char pad0[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int mode : 2;
    unsigned int unknown_9_2_ : 22;
    char unknown_c_[4];
    unsigned int flags10;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
};
struct Struct_ov024_021fc4f4 {
    char pad[0x8e18];
    unsigned char* partyWork;
};
struct Struct_ov024_021fc4f4_2 { char pad[0x14]; int flags; };
struct Struct_ov024_021fc4f4_3 {
    struct Struct_ov024_021fc4f4* battle;
    short field4;
    unsigned char field6;
    struct Struct_ov024_021fc4f4_6* actor;
    char unknown_c_[0x128 - 0xc];
    int field128;
    char unknown_12c_[0x134 - 0x12c];
    int unknown_134_;
    char unknown_138_[0x64c - 0x138];
    struct Struct_ov024_021fc4f4_7* action;
};

// USA: func_ov024_021fc4f4
extern "C" ARM void func_ov024_021fc4f4(struct Struct_ov024_021fc4f4_3* obj) {
    if (obj->field6 == 0) return;
    struct Struct_ov024_021fc4f4_6* actor = obj->actor;
    func_02053c6c((unsigned char*)actor);
    func_020797dc();
    struct Struct_ov024_021fc4f4_7* action = obj->action;
    if (action->mode == 1) return;
    GetCombatantByID((int)obj->battle, (short)obj->field128);

    int count = 0;
    struct Struct_ov024_021fc4f4_5 list;
    memset(&list, 0, sizeof(list));
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(obj->battle->partyWork, i & 0xff)) continue;
        if (action->unknown_17_4_ == 1 && i != obj->field4) continue;
        GameObject* c = GetCombatantByID((int)obj->battle, (short)i);
        if (!c) continue;
        if (!func_02010088((struct S_10088*)c)) continue;
        if ((action->flags10 & 0x400) && (((struct Struct_ov024_021fc4f4_2*)c->currentStats_)->flags & 0x200)) continue;
        struct Struct_ov024_021fc4f4_4 e;
        float var7 = 100.0f;
        e.value = c->currentStats_->primaryStats.currHP;
        e.flag5 = 0;
        e.index = i;
        count++;
        e.unknown_7_ = (int)var7;
        e.code = 5;
        func_ov024_021f6a1c((struct Struct_ov024_021f6a1c*)&list, &e);
    }
    if (count >= 2 && obj->unknown_134_ + count >= 3) {
        GetCombatantByID((int)obj->battle, 0);
        int target = actor->id & 0xff;
        if (action->unknown_17_4_ == 3) target = 0xff;
        func_ov024_021f9874(obj, &list, 0, target);
    }
}
