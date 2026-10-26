#include <globaldefs.h>

struct Struct_02114260_2 { void (*fn)(int); int arg; unsigned char count; };
extern struct Struct_02114260_2 data_02114260[];

// USA: func_020d2960
extern "C" ARM void func_020d2960(int idx) {
    struct Struct_02114260_2* e = &data_02114260[idx];
    e->count++;
}
