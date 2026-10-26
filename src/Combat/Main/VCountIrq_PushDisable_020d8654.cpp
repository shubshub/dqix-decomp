#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);

struct IntState020d8654 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d8654 data_0214e4a0;

// Main, originally PushInterruptDisableState_020d8654 (USA 0x020d8654, EUR 0x020d8664, JPN 0x020d9fb8)
ARM void VCountIrq_PushDisable(void) {
    data_0214e4a0.field_4 <<= 1;
    unsigned int old = DisableSpecificInterrupts(4);
    data_0214e4a0.field_4 |= (old & 4) ? 1 : 0;
}
