#include <globaldefs.h>

unsigned int EnableSpecificInterrupts(unsigned int mask);
unsigned int DisableSpecificInterrupts(unsigned int mask);

struct Struct_0214e4a0 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int unknown_4_;
};
extern Struct_0214e4a0 data_0214e4a0;

// Main, originally func_020d8694 (USA 0x020d8694, EUR 0x020d86a4, JPN 0x020d9ff8)
extern "C" ARM void VCountIrq_PopDisable(void) {
    if (data_0214e4a0.unknown_4_ & 1) {
        EnableSpecificInterrupts(4);
    } else {
        DisableSpecificInterrupts(4);
    }
    data_0214e4a0.unknown_4_ >>= 1;
}
