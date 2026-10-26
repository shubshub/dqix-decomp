#include <globaldefs.h>

// Main, originally SetFieldsAt0x4And0x8_0205b228 (USA 0x0205b228, EUR 0x0205b238, JPN 0x0205c5c4)
extern "C" ARM void GlyphDestination_SetRects(void* obj, int value, unsigned char flag) {
    *(int*)((char*)obj + 0x4) = value;
    *(unsigned char*)((char*)obj + 0x8) = flag;
}
