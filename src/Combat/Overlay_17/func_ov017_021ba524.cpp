#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"


struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct Struct_0205faf4_13;
extern "C" int func_0206e120(PackedNibbleArray0206e120* obj, int index);
extern "C" int func_0206e260(PackedNibbleArray0206e260* obj, int index);
extern "C" int func_0206e2dc(Struct_0205faf4_13* obj, int index);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_ov017_021b9bcc(int id, const char* name);

static inline int inline_ov017_021ba524(PackedNibbleArray0206e120* nibbles, int slot, int value) {
    return func_0206e120(nibbles, slot) == value;
}

struct Struct_ov017_021ba524 {
    char pad0[4];
    unsigned short unknown_4_;
};

struct Struct_ov017_021d8438 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Struct_ov017_021d8438 data_ov017_021d8438;

struct Struct_ov017_021d7c54_5 {
    signed char byte0;
    signed char unknown_1_;
};
extern struct Struct_ov017_021d7c54_5 data_ov017_021d7c54;

// USA: func_ov017_021ba524
extern "C" ARM int func_ov017_021ba524(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10 != 0) return 1;

    GameState* battle = GameState::GetInstance();
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) return 1;

    GameObject* leader = battle->GetGameObjectByIndex(0);
    struct Struct_ov017_021ba524* p = *(struct Struct_ov017_021ba524**)((char*)leader + 0x130);
    int pending = p->unknown_4_;
    if (pending > 0) return 1;

    PackedNibbleArray0206e120* nibbles = (PackedNibbleArray0206e120*)Scenario_GetInstance();
    int slot = params[0].ToInt();
    int cur = data_ov017_021d7c54.byte0;
    if (cur != slot && cur > -1) {
        if (inline_ov017_021ba524(nibbles, slot, 1) || inline_ov017_021ba524(nibbles, slot, 2) ||
            (inline_ov017_021ba524(nibbles, data_ov017_021d7c54.byte0, 3) && inline_ov017_021ba524(nibbles, slot, 3) &&
             data_ov017_021d7c54.byte0 <= slot)) {
        } else {
            return 1;
        }
    }

    Script::Parameter* var7 = &params[1];
    params = &params[2];
    switch (var7->ToInt()) {
    case -1:
        if (!inline_ov017_021ba524(nibbles, slot, 0)) return 1;
        break;
    case 0:
        if (!inline_ov017_021ba524(nibbles, slot, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((PackedNibbleArray0206e260*)nibbles, slot)) return 1;
        break;
    case 2:
        if (!inline_ov017_021ba524(nibbles, slot, 3)) return 1;
        break;
    case 3:
        if (!inline_ov017_021ba524(nibbles, slot, 1)) return 1;
        break;
    case 4:
        if (func_0206e2dc((Struct_0205faf4_13*)nibbles, slot) && inline_ov017_021ba524(nibbles, slot, 0)) {
        } else {
            return 1;
        }
        break;
    }

    if (count >= 5) {
        int var8 = params->ToInt();
        params++;
        if (var8 != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 0;
    }

    int id = params[0].ToInt();
    const char* name = params[1].ToString();
    if (name == 0) return 0;
    if (func_ov017_021b9bcc(id, name) != 0) data_ov017_021d7c54.byte0 = slot;
    return 1;
}
