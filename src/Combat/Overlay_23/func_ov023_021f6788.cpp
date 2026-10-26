#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov023_021f6788
extern "C" ARM void func_ov023_021f6788(char* obj) {
    VectorizedMemset(obj, 0, 0x16);
    *(short*)(obj + 0x12) = -1;
    *(short*)(obj + 0x14) = -1;
}
