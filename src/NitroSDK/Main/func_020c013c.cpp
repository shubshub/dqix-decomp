#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_020c013c
extern "C" ARM int func_020c013c(char* obj, void* dst, int length, int offset) {
    VectorizedInvertedMemcpy(*(char**)(obj + 0xa4) + offset, dst, length);
    return length;
}
