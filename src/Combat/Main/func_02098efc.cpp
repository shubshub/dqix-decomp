#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_02098efc
extern "C" ARM void func_02098efc(char* obj, int offset, const void* src, unsigned int length) {
    if (src == NULL) return;
    VectorizedInvertedMemcpy(src, obj + offset, length);
}
