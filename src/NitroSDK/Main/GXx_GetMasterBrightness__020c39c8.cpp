#include <globaldefs.h>


// Main, originally func_020c39c8 (USA 0x020c39c8, EUR 0x020c39d8, JPN 0x020c5494)
extern "C" ARM int GXx_GetMasterBrightness_(volatile unsigned short* p) {
    unsigned short mask = *p & 0xc000;
    if (mask == 0) {
        return 0;
    }
    if (mask == 0x4000) {
        return *p & 0x1f;
    }
    if (mask == 0x8000) {
        return -(*p & 0x1f);
    }
    return 0;
}
