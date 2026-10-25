#include <globaldefs.h>


// Main, originally func_020c39a0 (USA 0x020c39a0, EUR 0x020c39b0, JPN 0x020c546c)
extern "C" ARM void GXx_SetMasterBrightness_(short* out, int value) {
    if (value == 0) {
        *out = 0;
    } else if (value > 0) {
        *out = value | 0x4000;
    } else {
        *out = (-value) | 0x8000;
    }
}
