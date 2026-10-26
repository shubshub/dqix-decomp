#include <globaldefs.h>

struct Struct_020df850_4 {
    unsigned short a;
    unsigned short b;
};

// USA: func_020dfbc0
extern "C" ARM int func_020dfbc0(struct Struct_020df850_4* s) {
    return (int)((char*)(s->a << 3) + (s->b << 3));
}
