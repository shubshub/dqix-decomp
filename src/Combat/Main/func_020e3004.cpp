#include <globaldefs.h>

struct Struct_020e3004_2;
extern "C" void func_020e303c(struct Struct_020e3004_2* s);

struct Struct_020e3004 {
    int elems[8];
    unsigned char flags[8];
};

// USA: func_020e3004
extern "C" ARM void func_020e3004(struct Struct_020e3004 *p) {
    int *e = p->elems;
    unsigned char *f = p->flags;
    int i = 0;
    for (; i < 8; ) {
        func_020e303c((struct Struct_020e3004_2*)e);
        *f = 0;
        i++;
        e++;
        f++;
    }
}
