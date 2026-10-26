#include <globaldefs.h>

// USA: func_ov003_0215c270
extern "C" ARM void func_ov003_0215c270(void* unused, unsigned int color, unsigned int alpha) {
    *(volatile unsigned int*)0x040004a8 = 0x900000;
    *(volatile unsigned int*)0x040004a4 = (alpha << 16) | 0xc0;
    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x0400046c = 0x100000;
    *(volatile unsigned int*)0x0400046c = 0xc0000;
    *(volatile unsigned int*)0x0400046c = 0;
    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = color;
    *(volatile unsigned int*)0x0400048c = 0x10001000;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0x1000f000;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0xf000f000;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0xf0001000;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
