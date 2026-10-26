#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c70e8
ARM asm void ReleaseLockOwnerID(register unsigned short lockID)
{
    ldr r3, =0x027fffb0
    cmp r0, #0x60
    bpl _L10
    b _L14
_L10:
    add r3, r3, #0x4
_L14:
    bpl _L1c
    b _L20
_L1c:
    sub r0, r0, #0x60
_L20:
    bmi _L28
    b _L2c
_L28:
    sub r0, r0, #0x40
_L2c:
    mov r1, #0x80000000
    mov r1, r1, lsr r0
    ldr r2, [r3, #0x0]
    orr r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
