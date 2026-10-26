#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// Main, originally CopyFrom027ffcf4_020c99ac (USA 0x020c99ac, EUR 0x020c99bc, JPN 0x020cb478)
extern "C" ARM void OS_GetMacAddress(void* dst) {
    VectorizedInvertedMemcpy((const void*)0x27ffcf4, dst, 6);
}
