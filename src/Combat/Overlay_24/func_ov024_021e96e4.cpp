#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021e96e4 {
    char pad[0x10];
    void* field10;
};

struct Struct_ov024_021e96e4_2 {
    char pad[0x24];
    unsigned int reserved : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int unknown_26_4_ : 10;
    unsigned int unknown_27_6_ : 2;
};

// USA: func_ov024_021e96e4
extern "C" ARM int func_ov024_021e96e4(Struct_ov024_021e96e4* ctx, int id,
    Struct_ov024_021e96e4_2* params, int mode, signed char result,
    unsigned char arg5, unsigned char arg6) {
    GameObject* combatant = GetCombatantByID((int)ctx->field10, id);
    if (!combatant) return 0;
    if (arg5 != 0) {
        if (mode == 0) {
            switch (result) {
                case 2: return 0x4c;
                case 0: return 0x50;
                default: return 0x4e;
            }
        }
        switch (result) {
            case -2: return 0x4d;
            case 0: return 0x50;
            default: return 0x4f;
        }
    }
    if (mode == 1) {
        if (arg6 != 0) return 0x1f;
        if (((unsigned char*)ctx->field10)[0x8e95] != 0 ||
            (int)((unsigned char*)combatant->currentStats_)[0x51] <= 0) {
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
