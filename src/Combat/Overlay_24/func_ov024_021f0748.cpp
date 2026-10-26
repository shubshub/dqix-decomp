#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021f0748 { int field0; };
struct Struct_ov024_021feb54 { short v[4]; };
extern struct Struct_ov024_021feb54 data_ov024_021feb54;

// USA: func_ov024_021f0748
extern "C" ARM int func_ov024_021f0748(struct Struct_ov024_021f0748* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021feb54 buf = data_ov024_021feb54;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !func_020882f8((unsigned char*)c->currentStats_)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 8);
    return 1;
}
