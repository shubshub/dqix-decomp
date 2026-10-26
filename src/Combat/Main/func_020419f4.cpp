#include <globaldefs.h>

// USA: func_020419f4
extern "C" ARM void func_020419f4(int a, int b) {
    *(volatile unsigned int*)0x4000488 =
        (unsigned short)(short)(a >> 8) | ((unsigned short)(short)(b >> 8) << 16);
}
