#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021eda60(GameObject* combatant);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

struct Struct_ov024_021ee9b4 { int field0; };
struct Struct_ov024_021feedc { short v[8]; };
extern struct Struct_ov024_021feedc data_ov024_021feedc;

// USA: func_ov024_021ee9b4
extern "C" ARM int func_ov024_021ee9b4(struct Struct_ov024_021ee9b4* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021feedc buf = data_ov024_021feedc;

    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021eda60(c)) continue;
        if (!func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    if (*outCount * 3 < count) return 0;

    *outCount = count;
    memcpy(arg4, buf.v, 0x10);
    return 1;
}
