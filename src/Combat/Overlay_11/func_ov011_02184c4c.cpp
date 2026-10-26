#include <globaldefs.h>

struct Struct_ov011_02184c4c {
    int type;
    union {
        int i;
        float f;
    } value;
};

// USA: func_ov011_02184c4c
extern "C" ARM float func_ov011_02184c4c(struct Struct_ov011_02184c4c* v) {
    if (v->type == 0) return (float)v->value.i;
    return v->value.f;
}
