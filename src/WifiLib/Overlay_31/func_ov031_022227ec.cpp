#include <globaldefs.h>
#include "NitroSDK/OverlayMD5.h"

// USA: func_ov031_022227ec
extern "C" THUMB void func_ov031_022227ec(unsigned int* destination, const unsigned char* source, unsigned int size) {
    unsigned int offset = 0;
    if (offset < size) do {
        const unsigned char* group = source + offset;
        *destination++ = group[0] | (group[1] << 8) |
            (group[2] << 16) | ((unsigned int)group[3] << 24);
        offset += 4;
    } while (offset < size);
}
