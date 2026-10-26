#include <globaldefs.h>

struct Struct_02066a6c_4 {
    char pad[0xc];
    int a;
    int b;
    short c;
};

// USA: func_02066ce0
extern "C" ARM void func_02066ce0(struct Struct_02066a6c_4* s, int a, int b, short c) {
    s->a = a;
    s->b = b;
    s->c = c;
}
