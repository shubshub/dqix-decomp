#include <globaldefs.h>

extern int data_020f3390;

// KEEP-NAME
// Main, originally func_0200c9b4 (USA/EUR 0x0200c9b4, JPN 0x0200c878)
extern "C" ARM
asm float sqrtf(float x)
{
    stmdb sp!, {lr}
    mov r2, #0xff
    cmp r0, r2, lsl #23
    bhs _La4
    movs ip, r0, lsr #0x17
    beq _L84
    bic r0, r0, r2, lsl #23
    orr r0, r0, #0x800000
_L20:
    movs ip, ip, asr #1
    bhs _L30
    sub ip, ip, #1
    mov r0, r0, lsl #1
_L30:
    movs r1, r0, lsl #1
    mov r0, #0
    mov r2, #0
    mov lr, #0x1000000
_L40:
    add r3, r2, lr
    cmp r3, r1
    addle r2, r3, lr
    suble r1, r1, r3
    addle r0, r0, lr
    mov r1, r1, lsl #1
    movs lr, lr, lsr #1
    bne _L40
    cmp r1, #0
    biceq r0, r0, #1
    movs r0, r0, lsr #1
    adc r0, r0, #0
    add r0, r0, #0x20000000
    sub r0, r0, #0x800000
    add r0, r0, ip, lsl #23
    ldmia sp!, {lr}
    bx lr
_L84:
    cmp r0, #0
    ldmeqia sp!, {lr}
    bxeq lr
    clz ip, r0
    movs r0, r0, lsl ip
    rsb ip, ip, #9
    mov r0, r0, lsr #8
    b _L20
_La4:
    ldmeqia sp!, {lr}
    bxeq lr
    tst r0, #0x80000000
    beq _Lc0
    bics r3, r0, #0x80000000
    ldmeqia sp!, {lr}
    bxeq lr
_Lc0:
    ldr r2, =0x7fc00000
    orr r0, r0, r2
    ldr r3, =data_020f3390
    mov r4, #0x21
    str r4, [r3]
    ldmia sp!, {lr}
    bx lr
}
