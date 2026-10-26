#include <globaldefs.h>

// USA: func_ov031_0220c0ac
extern "C" ARM asm unsigned long long func_ov031_0220c0ac(unsigned short* top)
{
    ldrh r1, [r0, #0x0]
    ldrh r2, [r0, #-0x2]
    ldrh r3, [r0, #-0x4]
    orr r0, r3, r2, lsl #16
    bx lr
}
