#include <globaldefs.h>

// Main, originally GetPointerFromArray0x3c_0201e838 (USA 0x0201e838, EUR 0x0201e848, JPN 0x0201e5c4)
ARM void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index) {
    return *(void**)(obj + index * 4 + 0x3c);
}
