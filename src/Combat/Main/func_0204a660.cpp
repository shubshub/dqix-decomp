#include <globaldefs.h>

// USA: func_0204a660
extern "C" ARM void func_0204a660(int priority) {
    unsigned short *reg = (unsigned short *)0x4001008;
    *reg = (*reg & ~3) | priority;
}
