#include <globaldefs.h>

// USA: func_0204a628
extern "C" ARM void func_0204a628(int priority) {
    unsigned short *reg = (unsigned short *)0x400100c;
    *reg = (*reg & ~3) | priority;
}
