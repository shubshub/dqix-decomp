#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"


struct Struct_0205faf4_3;
struct Struct_0205faf4_4;
struct Struct_0205faf4_13;
extern "C" int func_0206e120(Struct_0205faf4_3* arg0, int arg1);
extern "C" int func_0206e260(Struct_0205faf4_4* arg0, int arg1);
extern "C" int func_0206e2dc(Struct_0205faf4_13* arg0, int arg1);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_ov017_021b9bcc(int id, const char* name);

static inline int inline_ov017_021ba524(Struct_0205faf4_3* arg0, int arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

struct Struct_ov017_021ba524 {
    char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_ov017_021d8438 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
    unsigned char unknown_8_[8];
    int unknown_10_;
};
extern struct Struct_ov017_021d8438 data_ov017_021d8438;

struct Struct_ov017_021d7c54_5 {
    signed char unknown_0_;
    signed char unknown_1_;
};
extern struct Struct_ov017_021d7c54_5 data_ov017_021d7c54;

// USA: func_ov017_021ba524
extern "C" ARM int func_ov017_021ba524(Script::Parameter* arg0, int arg1) {
    if (data_ov017_021d8438.unknown_10_ != 0) return 1;

    GameState* battle = GameState::GetInstance();
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) return 1;

    GameObject* var1 = var0->GetGameObjectByIndex(0);
    struct Struct_ov017_021ba524* var2 = *(struct Struct_ov017_021ba524**)((char*)var1 + 0x130);
    int var3 = var2->unknown_4_;
    if (var3 > 0) return 1;

    PackedNibbleArray0206e120* nibbles = (PackedNibbleArray0206e120*)Scenario_GetInstance();
    int slot = params[0].ToInt();
    int cur = data_ov017_021d7c54.byte0;
    if (cur != slot && cur > -1) {
        if (NibbleIs(nibbles, slot, 1) || NibbleIs(nibbles, slot, 2) ||
            (NibbleIs(nibbles, data_ov017_021d7c54.byte0, 3) && NibbleIs(nibbles, slot, 3) &&
             data_ov017_021d7c54.byte0 <= slot)) {
        } else {
            return 1;
        }
    }

    Script::Parameter* var7 = &arg0[1];
    arg0 = &arg0[2];
    switch (var7->ToInt()) {
    case -1:
        if (!inline_ov017_021ba524(var4, var5, 0)) return 1;
        break;
    case 0:
        if (!inline_ov017_021ba524(var4, var5, 2)) return 1;
        break;
    case 1:
        if (!func_0206e260((Struct_0205faf4_4*)var4, var5)) return 1;
        break;
    case 2:
        if (!inline_ov017_021ba524(var4, var5, 3)) return 1;
        break;
    case 3:
        if (!inline_ov017_021ba524(var4, var5, 1)) return 1;
        break;
    case 4:
        if (func_0206e2dc((Struct_0205faf4_13*)var4, var5) && inline_ov017_021ba524(var4, var5, 0)) {
        } else {
            return 1;
        }
        break;
    }

    if (arg1 >= 5) {
        int var8 = arg0->ToInt();
        arg0++;
        if (var8 != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.unknown_2_ = 1;
        }
    } else {
        if (data_ov017_021d8438.unknown_2_ != 0) return 0;
    }

    int var9 = arg0[0].ToInt();
    const char* var10 = arg0[1].ToString();
    if (var10 == 0) return 0;
    if (func_ov017_021b9bcc(var9, var10) != 0) data_ov017_021d7c54.unknown_0_ = var5;
    return 1;
}
