#include <globaldefs.h>

// USA: MI_Copy36B
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/mi/mi_memory.c — MI_Copy36B. Fixed
// 36-byte block copy, fully unrolled (9 words via ldmia/stmia).
// Main, originally func_020ca528 (USA 0x020ca528, EUR 0x020ca538, JPN 0x020cbff4)
extern "C" ARM asm void MI_Copy36B(const void* pSrc, void* pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}

    bx lr
}
