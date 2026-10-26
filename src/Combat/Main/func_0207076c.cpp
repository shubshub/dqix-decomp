#include <globaldefs.h>

// USA: func_0207076c
extern "C" ARM void func_0207076c(int a1, int a2, int a3, int a4, int a5, int a6) {
    *(volatile unsigned int*)0x40004a4 =
        a1 | (a2 << 4) | (a3 << 6) | a6 | (a4 << 24) | (a5 << 16);
}
