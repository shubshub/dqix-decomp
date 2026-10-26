#include <globaldefs.h>

// Main, originally SetByte0xdaAndFlag0x2_02050440 (USA 0x02050440, EUR 0x02050450, JPN 0x02051910)
extern "C" ARM void WindowPane_SetIndicatorPageCount(unsigned char* obj, int val) {
    obj[0xda] = val;
    obj[0xd8] |= 2;
}
