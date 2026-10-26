#include <globaldefs.h>

// Main, originally SetWord0x18ClearByte0x1f_0204b11c (USA 0x0204b11c, EUR 0x0204b12c, JPN 0x0204bf3c)
extern "C" ARM void Background_SetMapSize(unsigned char* obj, int value) {
    *(int*)(obj + 0x18) = value;
    obj[0x1f] = 0;
}
