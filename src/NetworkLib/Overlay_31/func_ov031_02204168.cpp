#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_02204168
extern "C" ARM void* func_ov031_02204168(int value, unsigned int end, void* dst, unsigned int start) {
    if (start < end) {
        unsigned int len = end - start;
        VectorizedMemset(dst, value, len);
        dst = (char*)dst + len;
    }
    return dst;
}
