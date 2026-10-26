#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);

struct Struct_ov024_021f101c { int field0; };
struct Struct_ov024_021feeec { short v[8]; };
extern struct Struct_ov024_021feeec data_ov024_021feeec;

// USA: func_ov024_021f101c
extern "C" ARM int func_ov024_021f101c(struct Struct_ov024_021f101c* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021feeec buf = data_ov024_021feeec;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !func_ov024_021dd010((struct Struct_ov024_021dced0_2*)c)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 0x10);
    return 1;
}
