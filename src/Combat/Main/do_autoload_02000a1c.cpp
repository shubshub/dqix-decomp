#include <globaldefs.h>

// USA: do_autoload  (semantic: NitroSDK crt0 do_autoload)
extern "C" char BuildInfo[];
extern "C" int AutoloadCallback();

// Main, originally func_02000a1c (USA/EUR 0x02000a1c, JPN 0x02000a1c)
extern "C" ARM asm void do_autoload(void) {
    ldr r0, =BuildInfo
    ldr r1, [r0, #0]
    ldr r2, [r0, #4]
    ldr r3, [r0, #8]
loop2:
    cmp r1, r2
    beq skipout
    ldr r5, [r1], #4
    ldr r7, [r1], #4
    add r6, r5, r7
    mov r4, r5
loop1:
    cmp r4, r6
    bmi ldrmi1
    b ldrmi2
ldrmi1:
    ldr r7, [r3], #4
ldrmi2:
    bmi strmi1
    b strmi2
strmi1:
    str r7, [r4], #4
strmi2:
    bmi loop1
    ldr r7, [r1], #4
    add r6, r4, r7
    mov r7, #0
loop3:
    cmp r4, r6
    bcc strcc1
    b strcc2
strcc1:
    str r7, [r4], #4
strcc2:
    bcc loop3
    bic r4, r5, #0x1f
cacheflush:
    mcr p15, 0, r7, c7, c10, 4
    mcr p15, 0, r4, c7, c5, 1
    mcr p15, 0, r4, c7, c14, 1
    add r4, r4, #0x20
    cmp r4, r6
    blt cacheflush
    b loop2
skipout:
    b AutoloadCallback
}
