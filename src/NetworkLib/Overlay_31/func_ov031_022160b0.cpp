#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern void* data_ov031_0224e5d8;

extern "C" int func_020d4aa8(void);
extern "C" unsigned short func_020d4be8(void);
extern "C" void func_ov031_02215ce0(void);

struct Struct_02101680;
extern "C" int func_020d5340(int a0, struct Struct_02101680* ctx);

// USA: func_ov031_022160b0
extern "C" ARM int func_ov031_022160b0(int arg) {
    if (arg == 0) {
        return -1;
    }
    *(void**)((char*)data_ov031_0224e5d8 + 0x1000 + 0x300) = (char*)data_ov031_0224e5d8 + 0xf00;
    *(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1300 + 0x4) = 0x400;
    int v1 = func_020d4aa8();
    *(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1300 + 0x6) = v1;
    unsigned short v2 = func_020d4be8();
    *(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1300 + 0x8) = v2;
    *(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1300 + 0x10) = 1;
    VectorizedMemset((char*)data_ov031_0224e5d8 + 0x1300 + 0xa, 0xff, 6);
    *(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0x344) = arg;
    *(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 1;
    int r = func_020d5340((int)func_ov031_02215ce0, (struct Struct_02101680*)((char*)data_ov031_0224e5d8 + 0x1300));
    return (r == 2) ? 0 : r;
}
