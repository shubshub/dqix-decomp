#include <globaldefs.h>

// Main, originally GetElementStride0x40_0208a018 (USA 0x0208a018, EUR 0x0208a028, JPN 0x0208a90c)
extern "C" ARM void* PresetTable_GetEntry(unsigned char* obj, int index) {
    unsigned char* base = *(unsigned char**)obj;
    if (base == 0) {
        return NULL;
    }
    if (*(short*)(obj + 4) <= index) {
        return NULL;
    }
    return base + index * 0x40;
}
