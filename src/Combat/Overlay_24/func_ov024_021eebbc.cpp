#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021eebbc { char pad0; unsigned char flags:4; unsigned char pad1:4; };
struct Struct_ov024_021eebbc_2 { int field0; };
struct Struct_ov024_021fecdc { short v[8]; };
extern struct Struct_ov024_021fecdc data_ov024_021fecdc;

// USA: func_ov024_021eebbc
extern "C" ARM int func_ov024_021eebbc(struct Struct_ov024_021eebbc_2* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021eebbc* gate = (struct Struct_ov024_021eebbc*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    int nibble = gate->flags;
    if (nibble >= 5) return 0;

    struct Struct_ov024_021fecdc buf = data_ov024_021fecdc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 0);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (!func_02010088((struct S_10088*)c)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    func_ov024_021ed890((struct Random**)obj, outCount, arg4);
    return 1;
}
