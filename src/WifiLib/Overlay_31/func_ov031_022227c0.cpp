#include <globaldefs.h>
#include "NitroSDK/OverlayMD5.h"

// USA: func_ov031_022227c0
extern "C" THUMB void func_ov031_022227c0(unsigned char* destination, const unsigned int* source, unsigned int size) {
    unsigned int offset = 0;
    if (offset < size) do {
        unsigned char* group = destination + offset;
        group[0] = *source;
        group[1] = *source >> 8;
        group[2] = *source >> 16;
        group[3] = *source++ >> 24;
        offset += 4;
    } while (offset < size);
}
