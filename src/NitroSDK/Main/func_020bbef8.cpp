#include <globaldefs.h>

struct Struct_0210f3c0_3 { int a; unsigned int flags; };
extern struct Struct_0210f3c0_3 data_0210f3c0;

// USA: func_020bbef8
extern "C" ARM void func_020bbef8(int bit) {
    data_0210f3c0.flags &= ~(1 << bit);
}
