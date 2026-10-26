#include <globaldefs.h>

extern "C" void BgVram_Clear(char* obj);

// Main, originally TailForward0203b66c (USA 0x0203b66c, EUR 0x0203b67c, JPN 0x0203b0c4)
extern "C" ARM void BgVram_Reset(char* bgVram) {
    BgVram_Clear(bgVram);
}
