#include <globaldefs.h>

struct Struct_02114260_3 { void (*fn)(int); int arg; unsigned char count; };
extern struct Struct_02114260_3 data_02114260[];

// USA: func_020d2980
extern "C" ARM unsigned char func_020d2980(int idx, void (*fn)(int), int arg) {
    struct Struct_02114260_3* e = &data_02114260[idx];
    e->fn = fn;
    e->arg = arg;
    return ++e->count;
}
