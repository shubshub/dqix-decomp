#include <globaldefs.h>

// USA: func_0204a644
extern "C" ARM void func_0204a644(int priority) {
    unsigned short *reg = (unsigned short *)0x400100a;
    *reg = (*reg & ~3) | priority;
}
