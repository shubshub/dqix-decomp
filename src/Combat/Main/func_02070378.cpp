#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_02070378
extern "C" ARM void func_02070378(char* obj) {
    VectorizedMemset(obj, 0, 0x70);
    obj[0x4] = 1;
    obj[0x8] = 1;
    obj[0x9] = 1;
    obj[0xb] = -1;
    *(int*)(obj + 0x20) = -1;
    *(int*)(obj + 0x24) = -1;
    *(int*)(obj + 0x28) = -1;
    *(int*)(obj + 0x2c) = -1;
    *(short*)(obj + 0x1e) = -1;
    obj[0xc] = 0;
    *(short*)(obj + 0x6c) = -1;
}
