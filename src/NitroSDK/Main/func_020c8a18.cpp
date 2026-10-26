#include <globaldefs.h>

// USA: func_020c8a18
extern "C" ARM void func_020c8a18(unsigned int arg0, unsigned int arg1) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c5, c0, 2
        bic v, v, arg0
        orr v, v, arg1
        mcr p15, 0, v, c5, c0, 2
    }
}
