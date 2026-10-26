#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021f65fc { int field0; };
struct Struct_ov024_021fef8c { short v[8]; };
extern struct Struct_ov024_021fef8c data_ov024_021fef8c;

// USA: func_ov024_021f65fc
extern "C" ARM int func_ov024_021f65fc(struct Struct_ov024_021f65fc* obj, short value, int arg2, int* outCount, short* dest) {
    struct Struct_ov024_021fef8c buf = data_ov024_021fef8c;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = func_ov000_021536f8(obj->field0, buf.v[i]);
        if (c && c->obj3D_.unknown_2_ == 0xb4) {
            (*outCount)++;
        }
    }
    int result;
    if (*outCount > 0) {
        result = 0;
    } else {
        result = 1;
        *outCount = 1;
        *dest = value;
    }
    return result;
}
