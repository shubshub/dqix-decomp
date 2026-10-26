#include <globaldefs.h>

#include "NitroSDK/Memory.h"

// USA: func_ov031_0221e52c
extern "C" THUMB void func_ov031_0221e52c(void* dst, int value, unsigned int length) {
    VectorizedMemset(dst, (unsigned char)value, length);
}
