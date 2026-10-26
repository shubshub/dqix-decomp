#include <globaldefs.h>

#if defined(jpn)
#define func_020c89e4 func_020ca4b0
#endif

// USA: func_020c89e4
extern "C" ARM unsigned int func_020c89e4(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c9, c1, 0
    }
    v = v & 0xfffff000;
    return v;
}
