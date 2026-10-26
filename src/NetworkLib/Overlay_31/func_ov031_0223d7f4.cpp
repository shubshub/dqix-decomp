#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

unsigned int SetSpecificInterruptsEnabled(unsigned int which);

struct Struct_ov031_02290d58 { void* handler; unsigned int mask; };
extern Struct_ov031_02290d58 data_ov031_02290d58;

// USA: func_ov031_0223d7f4
extern "C" ARM void func_ov031_0223d7f4(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    (void)old;
    *ime = 0;
    SetSpecificInterruptsEnabled(data_ov031_02290d58.mask);
    SetInterruptHandler(1, data_ov031_02290d58.handler);
}
