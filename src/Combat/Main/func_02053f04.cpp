#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { Enum_02053f04_348 = 0x150, Enum_02053f04_352 = 0x154, Enum_02053f04_364 = 0x160, Enum_02053f04_1 = 4 };
#else
enum { Enum_02053f04_348 = 0x15c, Enum_02053f04_352 = 0x160, Enum_02053f04_364 = 0x16c, Enum_02053f04_1 = 1 };
#endif

extern "C" void __clear(void* buf, int n);
extern int data_020f0420[];

// USA: func_02053f04
extern "C" ARM void func_02053f04(void* obj) {
    Vector3i buf;
    __clear(&buf, 0xc);
    *(int*)((char*)obj + Enum_02053f04_348) = data_020f0420[Enum_02053f04_1];
    *(Vector3i*)((char*)obj + Enum_02053f04_352) = buf;
    *(Vector3i*)((char*)obj + Enum_02053f04_364) = buf;
}
