#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021e95d4 {
    char pad[0x8e95];
    unsigned char unknown_8e95_;
};

struct Struct_ov024_021e95d4_2 {
    char pad[0x10];
    Struct_ov024_021e95d4* battle;
};

struct Struct_ov024_021e95d4_3 {
    char pad[0x24];
    unsigned int unknown_24_0_ : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int unknown_26_4_ : 10;
    unsigned int unknown_27_6_ : 2;
};

// USA: func_ov024_021e95d4
extern "C" ARM int func_ov024_021e95d4(Struct_ov024_021e95d4_2* ctx, int id,
    Struct_ov024_021e95d4_3* params, int mode, signed char arg4,
    unsigned char changed, unsigned char flag) {
    GameObject* combatant = GetCombatantByID((int)ctx->battle, id);
    if (!combatant) return 0;
    if (changed != 0) {
        if (mode == 0) {
            switch (arg4) {
                case 2: return 0x3a;
                case 0: return 0x3e;
                default: return 0x3c;
            }
        }
        switch (arg4) {
            case -2: return 0x3b;
            case 0: return 0x3e;
            default: return 0x3d;
        }
    }
    if (mode == 1) {
        if (flag != 0) return 0x1f;
        if (ctx->battle->unknown_8e95_ != 0 ||
            (int)((unsigned char*)combatant->currentStats_)[0x50] <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return func_ov024_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return func_ov024_021da644(id,
        params->unknown_25_2_, params->unknown_26_4_);
}
