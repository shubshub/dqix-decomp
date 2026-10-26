#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct Struct_ov024_021df454_2;
extern "C" int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj);

struct Struct_ov024_021f1198 { int field0; };
struct Struct_ov024_021fef1c { short v[8]; };
extern struct Struct_ov024_021fef1c data_ov024_021fef1c;

// USA: func_ov024_021f1198
extern "C" ARM int func_ov024_021f1198(struct Struct_ov024_021f1198* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021fef1c buf = data_ov024_021fef1c;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 0x10);
    return 1;
}
