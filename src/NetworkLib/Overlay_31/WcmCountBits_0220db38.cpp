#include <globaldefs.h>

// USA: func_ov031_0220db38
extern "C" ARM asm unsigned int func_ov031_0220db38(unsigned int value)
{
    mov r1, r0
    mov r0, #0x0
    mov r3, #0x1
_L0c:
    clz r2, r1
    rsbs r2, r2, #0x1f
    bcc _L1c
    b _L20
_L1c:
    bx lr
_L20:
    bic r1, r1, r3, lsl r2
    add r0, r0, #0x1
    b _L0c
}
