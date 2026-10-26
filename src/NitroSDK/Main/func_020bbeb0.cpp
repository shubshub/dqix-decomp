#include <globaldefs.h>

struct Struct_0210f3c0_2 { int a; unsigned int flags; };
extern struct Struct_0210f3c0_2 data_0210f3c0;

// USA: func_020bbeb0
extern "C" ARM int func_020bbeb0(void) {
    int i;
    int mask = 1;
    unsigned int val = data_0210f3c0.flags;
    i = 0;
    do {
        if (!(val & mask)) {
            data_0210f3c0.flags |= mask;
            return i;
        }
        mask <<= 1;
        i++;
    } while (i < 8);
    return -1;
}
