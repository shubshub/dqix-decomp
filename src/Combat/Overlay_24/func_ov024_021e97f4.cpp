#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021e97f4 {
    char pad[0x10];
    void* field10;
};

struct Struct_ov024_021e97f4_2 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int reserved : 2;
};

struct Struct_ov024_021e97f4_3 {
    char pad[0x24];
    Struct_ov024_021e97f4_2 unknown_24_;
};

struct Struct_ov024_021e97f4_4 {
    char pad[0x8e95];
    unsigned char unknown_8e95_;
};

static inline int inline_ov024_021e97f4(ModifiableCombatStats* stats) {
    return ((unsigned char*)stats)[0x52];
}

// USA: func_ov024_021e97f4
extern "C" ARM int func_ov024_021e97f4(Struct_ov024_021e97f4* ctx, int id,
    Struct_ov024_021e97f4_3* parameters, int flag, signed char value,
    unsigned char arg5, unsigned char special) {
    GameObject* combatant = GetCombatantByID((int)ctx->field10, id);
    if (!combatant) return 0;

    if (arg5 != 0) {
        if (flag == 0) {
            switch (value) {
                case 2: return 0xab;
                case 0: return 0xae;
                default: return 0xac;
            }
        }
        switch (value) {
            case -2: return 0xaf;
            case 0: return 0xae;
            default: return 0xad;
        }
    }
    if (flag == 1) {
        if (special != 0) return 0x1f;
        if (((Struct_ov024_021e97f4_4*)ctx->field10)->unknown_8e95_ != 0 ||
            inline_ov024_021e97f4(combatant->currentStats_) <= 0) {
#if defined(jpn)
            return 0x1b;
#else
            return func_ov024_021da644(id, 0x26d, 0x1b);
#endif

        }
    }
    return func_ov024_021da644(id,
        parameters->unknown_24_.second,
        parameters->unknown_24_.third);
}
