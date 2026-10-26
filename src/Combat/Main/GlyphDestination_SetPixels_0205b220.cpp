#include <globaldefs.h>

// Main, originally SetField0_0205b220 (USA 0x0205b220, EUR 0x0205b230, JPN 0x0205c5bc)
ARM void GlyphDestination_SetPixels(void* obj, int value) {
    *(int*)obj = value;
}
