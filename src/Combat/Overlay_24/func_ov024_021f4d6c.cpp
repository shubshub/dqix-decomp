#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021ede2c(void* obj);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

struct Struct_ov024_021f4d6c { int field0; };

struct Struct_ov024_021feba4 { short v[4]; };
extern struct Struct_ov024_021feba4 data_ov024_021feba4;

// USA: func_ov024_021f4d6c
extern "C" ARM int func_ov024_021f4d6c(struct Struct_ov024_021f4d6c* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021feba4 buf = data_ov024_021feba4;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    if (!func_ov024_021ede2c(obj)) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) continue;
        int value = *((unsigned char*)c->currentStats_ + 0x4e);
        if (value <= 0) continue;
        arg4[(*outCount)++] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    if (*outCount * 3 < count * 2) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 8);
    return 1;
}
