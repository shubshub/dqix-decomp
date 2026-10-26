#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021dee84_4 { char pad[0x10]; int field10; };

// USA: func_ov024_021e9990
extern "C" ARM int func_ov024_021e9990(Struct_ov024_021dee84_4* s, int id, int arg2, unsigned char flag, signed char sb) {
    GameObject* c = GetCombatantByID(s->field10, id);
    if (c == NULL) return 0;
    if (flag != 0) goto retZero;
    switch (sb) {
        case 2: return 0xc4;
        default: return 0xc5;
    }
retZero:
    return 0;
}
