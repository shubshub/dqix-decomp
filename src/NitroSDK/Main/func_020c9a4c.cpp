#include <globaldefs.h>

// USA: func_020c9a4c
extern "C" ARM unsigned int func_020c9a4c(unsigned int value) {
    asm {
        clz value, value
    }
    return value;
}
