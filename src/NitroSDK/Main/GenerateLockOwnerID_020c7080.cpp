#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c7080
ARM asm int GenerateLockOwnerID(void)
{
    ldr r3, =0x027fffb0
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    bne _L18
    b _L1c
_L18:
    mov r0, #0x40
_L1c:
    bne _L44
    add r3, r3, #0x4
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    ldr r0, =0xfffffffd
    beq _L3c
    b _L40
_L3c:
    bx lr
_L40:
    mov r0, #0x60
_L44:
    add r0, r0, r2
    mov r1, #0x80000000
    mov r1, r1, lsr r2
    ldr r2, [r3, #0x0]
    bic r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
