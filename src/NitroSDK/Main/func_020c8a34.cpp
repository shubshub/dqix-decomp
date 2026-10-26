#include <globaldefs.h>

// USA: func_020c8a34
extern "C" ARM void func_020c8a34(unsigned int value) {
    asm {
        mcr p15, 0, value, c6, c2, 0
    }
}
