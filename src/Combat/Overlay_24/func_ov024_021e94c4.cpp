#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021e94c4 {
    char pad[0x10];
    int field10;
};

struct Struct_ov024_021e94c4_2 {
    char pad[0x24];
    unsigned int : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int unknown_26_4_ : 10;
    unsigned int : 2;
};

// USA: func_ov024_021e94c4
extern "C" ARM int func_ov024_021e94c4(Struct_ov024_021e94c4* ctx, int id,
    Struct_ov024_021e94c4_2* parameters, int mode, signed char value,
    unsigned char arg5, unsigned char arg6) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (!combatant) return 0;
    if (arg5 != 0) {
        if (mode == 0) {
            switch (value) {
                case 2: return 0x47;
                case 0: return 0x4b;
                default: return 0x49;
            }
        }
        switch (value) {
            case -2: return 0x48;
            case 0: return 0x4b;
            default: return 0x4a;
        }
    }
    if (mode == 1) {
        if (arg6 != 0) return 0x1f;
        if (*(unsigned char*)(ctx->field10 + 0x8e95) != 0 ||
            (int)*((unsigned char*)combatant->currentStats_ + 0x4f) <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return func_ov024_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return func_ov024_021da644(id, parameters->unknown_25_2_, parameters->unknown_26_4_);
}
