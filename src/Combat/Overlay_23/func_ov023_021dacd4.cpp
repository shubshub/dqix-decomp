#include <globaldefs.h>

// Overlay 23, originally func_ov023_021dacd4 (USA/EUR 0x021dacd4, JPN 0x021db548)
extern "C" ARM void CharacterCreationUI_DrawFullscreenQuad(void* unused, int color, int attr) {
    *(volatile unsigned int*)0x40004a8 = 0x900000;
    *(volatile unsigned int*)0x40004a4 = (arg2 << 0x10) | 0xc0;
    *(volatile unsigned int*)0x4000444 = 0;
    *(volatile unsigned int*)0x4000470 = 0;
    *(volatile unsigned int*)0x4000470 = 0;
    *(volatile unsigned int*)0x4000470 = -0x80000;
    *(volatile unsigned int*)0x400046c = 0x100000;
    *(volatile unsigned int*)0x400046c = 0xc0000;
    *(volatile unsigned int*)0x400046c = 0;
    *(volatile unsigned int*)0x4000500 = 1;
    *(volatile unsigned int*)0x4000480 = arg1;

    int var0 = 0x10001000;
    *(volatile unsigned int*)0x400048c = var0;
    *(volatile unsigned int*)0x400048c = 0;
    *(volatile unsigned int*)0x400048c = var0 + 0xe000;
    *(volatile unsigned int*)0x400048c = 0;
    *(volatile unsigned int*)0x400048c = 0x10000 - var0;
    *(volatile unsigned int*)0x400048c = 0;
    *(volatile unsigned int*)0x400048c = var0 - 0x20000000;
    *(volatile unsigned int*)0x400048c = 0;

    *(volatile unsigned int*)0x4000504 = 0;
    *(volatile unsigned int*)0x4000448 = 1;
}
