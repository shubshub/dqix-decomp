#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov023_021f6e90
extern "C" ARM void func_ov023_021f6e90(char* obj, int idx, const void* src) {
    if (idx >= 3) return;
    VectorizedInvertedMemcpy(src, obj + 0x30 + idx * 0x16, 0x16);
}
