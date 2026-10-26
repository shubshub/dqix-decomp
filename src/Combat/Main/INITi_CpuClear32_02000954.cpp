#include <globaldefs.h>

// Main, originally func_02000954 (USA/EUR 0x02000954, JPN 0x02000954)
extern "C" ARM asm void INITi_CpuClear32(unsigned int data, void* dst, unsigned int size) {
    add ip, r1, r2
top:
    cmp r1, ip
    blt store
    b after_store
store:
    stmia r1!, {r0}
after_store:
    blt top
    bx lr
}
