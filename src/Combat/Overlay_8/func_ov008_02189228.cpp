#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

// USA: func_ov008_02189228
extern "C" ARM void func_ov008_02189228(void* obj) {
    char* p = (char*)obj;
    VectorizedMemset(p, 0, 6);
    memset(p + 6, 0, 0xb);
    unsigned short* f12 = (unsigned short*)(p + 0x12);
    *f12 &= ~0x3FFF;
    p[0x11] = 0;
    *f12 &= ~0x4000;
    VectorizedMemset(p + 0x14, 0, 0x18);
}
