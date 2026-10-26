#include <globaldefs.h>

// USA: func_0203fc28
extern "C" ARM void func_0203fc28(int a, int b) {
    *(volatile unsigned int*)0x4000488 =
        (unsigned short)(short)(a >> 8) | ((unsigned short)(short)(b >> 8) << 16);
}
