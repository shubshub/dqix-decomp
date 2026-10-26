#include <globaldefs.h>

extern int data_0210f3c0;

// USA: func_020bbe94
extern "C" ARM void func_020bbe94(int mask) {
    data_0210f3c0 &= ~mask;
}
