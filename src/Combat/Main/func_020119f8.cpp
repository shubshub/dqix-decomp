#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_020119f8
extern "C" ARM unsigned char func_020119f8(char* obj, void* dst) {
    if (dst != NULL) {
#if defined(jpn)
        VectorizedInvertedMemcpy(obj + 0x6202, dst, 0x1c);
#else
        VectorizedInvertedMemcpy(obj + 0x6482, dst, 0x1c);
#endif
    }
#if defined(jpn)
    return *(unsigned char*)(obj + 0x6200);
#else
    return *(unsigned char*)(obj + 0x6480);
#endif
}
