#include <globaldefs.h>

extern "C" void* func_020bd580(int index);
extern "C" int func_020be2ec(unsigned int index, int b, int flag);
extern "C" int func_020be280(unsigned int index, int b, int flag);
extern "C" int func_020bd8ac(unsigned int index);

struct Struct_020be010 {
    unsigned int offset : 24;
    unsigned int unknown_3_0_ : 8;
};

// USA: func_020be010
extern "C" ARM int func_020be010(int index, unsigned int flags, int b, int flag, int* out) {
    struct Struct_020be010* w = (struct Struct_020be010*)func_020bd580(index);
    if (w == NULL) return 5;
    int result;
    if (flags & 4) {
        if (w->unknown_3_0_ & 1) {
            result = func_020be2ec(w->offset, b, flag);
        } else {
            result = func_020be280(w->offset, b, flag);
        }
        if (result == 0) return 9;
    } else {
        result = func_020bd8ac(w->offset);
    }
    if (out) *out = result;
    return 0;
}
