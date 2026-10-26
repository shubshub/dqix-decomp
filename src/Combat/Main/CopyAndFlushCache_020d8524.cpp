#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"


// Main, originally func_020d8524 (USA 0x020d8524, EUR 0x020d8534, JPN 0x020d9e88)
extern "C" ARM unsigned int CopyAndFlushCache(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    CleanInvalidateCacheRange(dst, length);
    return length;
}
