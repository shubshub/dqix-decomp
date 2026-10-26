#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021eda60(GameObject* combatant);
struct Struct_ov024_021df454_2;
extern "C" int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj);

struct Struct_ov024_021f125c { int field0; };

struct Struct_ov024_021fef2c { short v[8]; };
extern struct Struct_ov024_021fef2c data_ov024_021fef2c;

// USA: func_ov024_021f125c
extern "C" ARM int func_ov024_021f125c(struct Struct_ov024_021f125c* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021fef2c buf = data_ov024_021fef2c;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) continue;
        if (!func_ov024_021eda60(c)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 0x10);
    return 1;
}
