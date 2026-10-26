#include <globaldefs.h>

// USA: func_020c86e8
extern "C" ARM void func_020c86e8(int index, int value) {
    ((volatile int*)0x27ffda0)[index] = value;
}
