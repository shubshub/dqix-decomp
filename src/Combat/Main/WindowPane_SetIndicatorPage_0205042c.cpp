#include <globaldefs.h>

// Main, originally SetByte0xd9AndFlag0x2_0205042c (USA 0x0205042c, EUR 0x0205043c, JPN 0x020518fc)
ARM void WindowPane_SetIndicatorPage(unsigned char* obj, unsigned char value) {
    obj[0xd9] = value;
    obj[0xd8] |= 0x2;
}
