#include <globaldefs.h>

// Main, originally OrBitsIntoField0_020466e4 (USA 0x020466e4, EUR 0x020466f4, JPN 0x02047504)
ARM void FlagWord_SetBits(unsigned int* p, unsigned int mask) {
    *p |= mask;
}
