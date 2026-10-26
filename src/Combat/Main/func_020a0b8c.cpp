#include <globaldefs.h>

struct Struct_020a0b8c {
    short* keys;
    signed char* values;
    short count;
};

// USA: func_020a0b8c
extern "C" ARM int func_020a0b8c(struct Struct_020a0b8c* p) {
    signed char* values = p->values;
    short count = p->count;
    short n = 0;
    short i;
    for (i = 0; i < count; i++) {
        if (values[i] != 0) {
            n++;
        }
    }
    return n;
}
