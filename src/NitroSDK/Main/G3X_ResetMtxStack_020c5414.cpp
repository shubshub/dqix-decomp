#include <globaldefs.h>

extern "C" int func_020c5650(int* out);
extern "C" int func_020c5680(int* out);

// Main, originally func_020c5414 (USA 0x020c5414, EUR 0x020c5424, JPN 0x020c6ee0)
extern "C" ARM void G3X_ResetMtxStack(void) {
    int var0;
    int var1;
    *(volatile unsigned int*)0x4000600 |= 0x8000;
    while (func_020c5650(&var0) != 0) {}
    while (func_020c5680(&var1) != 0) {}
    *(volatile unsigned int*)0x4000440 = 3;
    *(volatile unsigned int*)0x4000454 = 0;
    *(volatile unsigned int*)0x4000440 = 0;
    if (var1 != 0) *(volatile unsigned int*)0x4000448 = var1;
    *(volatile unsigned int*)0x4000440 = 2;
    *(volatile unsigned int*)0x4000448 = var0;
    *(volatile unsigned int*)0x4000454 = 0;
}
