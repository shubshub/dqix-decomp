#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_0223fb60
extern "C" ARM void func_ov031_0223fb60(void *dst, unsigned int length) {
    VectorizedMemset(dst, 0, length);
}
