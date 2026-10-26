#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"

#if defined(jpn)
#define func_020d84f8 func_020d9e5c
#endif

// USA: func_020d84f8
extern "C" ARM unsigned int func_020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    CleanInvalidateCacheRange(obj, len);
    return len;
}
