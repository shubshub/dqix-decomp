#include <globaldefs.h>

extern int data_02105254;

// Main, originally GetData02105254_0203b628 (USA 0x0203b628, EUR 0x0203b638, JPN 0x0203b080)
ARM void* BgVram_GetInstance(void) {
    return &data_02105254;
}
