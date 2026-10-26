#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union {
        int i;
        float f;
    } value;
};

// USA: func_ov011_02184c30
extern "C" ARM int func_ov011_02184c30(struct TaggedNumber02184c30* v) {
    if (v->type == 1) return (int)v->value.f;
    return v->value.i;
}
