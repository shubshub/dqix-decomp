#include <globaldefs.h>

struct Struct_02114260 { void (*fn)(int); int arg; unsigned char count; };
extern struct Struct_02114260 data_02114260[8];

// USA: func_020d2930
extern "C" ARM void func_020d2930() {
    int i = 0;
    struct Struct_02114260* e = data_02114260;
    do {
        e->fn = 0;
        e->arg = 0;
        e->count = 0;
        i++;
        e++;
    } while (i < 8);
}
