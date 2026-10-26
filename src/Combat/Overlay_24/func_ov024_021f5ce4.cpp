#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int a, short* buf, int max, int start);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);

struct Struct_ov024_021f5ce4 { int field0; };
struct Struct_ov024_021fed9c { short v[8]; };
extern struct Struct_ov024_021fed9c data_ov024_021fed9c;

// USA: func_ov024_021f5ce4
extern "C" ARM int func_ov024_021f5ce4(struct Struct_ov024_021f5ce4* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021fed9c buf = data_ov024_021fed9c;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c)) {
            (*outCount)++;
        }
    }
    if (*outCount <= 0) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 0x10);
    return 1;
}
