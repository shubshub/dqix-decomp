#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);

struct Struct_0214e4a0 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int unknown_4_;
};
extern Struct_0214e4a0 data_0214e4a0;

// Main, originally PushInterruptDisableState_020d8654 (USA 0x020d8654, EUR 0x020d8664, JPN 0x020d9fb8)
extern "C" ARM void VCountIrq_PushDisable(void) {
    data_0214e4a0.unknown_4_ <<= 1;
    unsigned int old = DisableSpecificInterrupts(4);
    data_0214e4a0.unknown_4_ |= (old & 4) ? 1 : 0;
}
