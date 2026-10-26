#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"

struct Struct_ov004_0216950c { unsigned char pad[0x14]; };

// USA: func_ov004_021695fc
extern "C" ARM void func_ov004_021695fc(struct Struct_ov004_0216950c* obj) {
    unsigned char* base = (unsigned char*)obj;
    VectorizedMemset(base, 0, 6);
    memset(base + 6, 0, 0xb);
    unsigned short* f12 = (unsigned short*)(base + 0x12);
    *f12 = *f12 & -0x4000;
    base[0x11] = 0;
    *f12 = *f12 & ~0x4000;
    VectorizedMemset(base + 0x14, 0, 0x18);
}
