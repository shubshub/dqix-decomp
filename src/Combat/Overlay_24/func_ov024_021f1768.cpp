#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021f1768 { int field0; };
struct Struct_ov024_021fec34 { short v[4]; };
extern struct Struct_ov024_021fec34 data_ov024_021fec34;

struct Struct_ov024_021f1768_2 {
    signed int unknown_0_0_ : 3;
    signed int unknown_0_3_ : 3;
    signed int unknown_0_6_ : 3;
    signed int unknown_1_1_ : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int unknown_2_2_ : 3;
};

// USA: func_ov024_021f1768
extern "C" ARM int func_ov024_021f1768(struct Struct_ov024_021f1768* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021fec34 buf = data_ov024_021fec34;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021eda60(c)) continue;
        struct Struct_ov024_021f1768_2* var5 = (struct Struct_ov024_021f1768_2*)((char*)c->currentStats_ + 0x58);
        if (var5->unknown_2_2_ > -2) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 8);
    return 1;
}
