#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// Main, originally CopyFieldsAndFlushCache0204a8f4 (USA 0x0204a8f4, EUR 0x0204a904, JPN 0x0204b714)
ARM void TileHeader_Flush(char* dst, char* src) {
    unsigned int size;
    unsigned int unused;
    memcpy(&unused, src, 4);
    memcpy(dst + 4, src + 4, 2);
    memcpy(dst + 6, src + 6, 2);
    memcpy(dst + 8, src + 8, 2);
    memcpy(dst + 0xa, src + 0xa, 1);
    memcpy(dst + 0xb, src + 0xb, 1);
    memcpy(&size, src + 0xc, 4);
    CleanInvalidateCacheRange(src + 0x10, size);
}
