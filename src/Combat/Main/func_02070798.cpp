#include <globaldefs.h>

// USA: func_02070798
extern "C" ARM void func_02070798(int a1, int a2, int a3) {
    *(volatile unsigned int*)0x400048c = (a1 & 0xffff) | ((unsigned short)a2 << 16);
    *(volatile unsigned int*)0x400048c = a3 & 0xffff;
}
