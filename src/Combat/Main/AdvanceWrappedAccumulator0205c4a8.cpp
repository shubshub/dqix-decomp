#include <globaldefs.h>

struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84*);
extern "C" void func_0205bb04(void*, int);

struct Struct_0205c4a8 {
    int field0;
    int field4;
    char pad8[0xc];
    int field14;
};

// USA: func_0205c4a8
ARM void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205c4a8* s, int delta) {
    int base;
    s->field14 += delta;
    if (s->field4 <= s->field14) {
        s->field14 -= s->field4;
    } else if (s->field14 < 0) {
        s->field14 += s->field4;
    }
    base = s->field0;
    if (base <= GridCursor_GetSelectedIndex((struct Struct_0205bb84*)s)) {
        func_0205bb04((void*)s, base - 1);
    }
}
