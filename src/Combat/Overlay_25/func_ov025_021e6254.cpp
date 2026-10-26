#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6254_12 = 0x4 };
#else
enum { Enum_ov025_021e6254_12 = 0xc };
#endif

extern void* data_ov025_021ef988;

struct Struct_ov025_021e6254 {
    char pad0[8];
    int field8;
};

// USA: func_ov025_021e6254
extern "C" ARM int func_ov025_021e6254(struct Struct_ov025_021e6254* in) {
    *(int*)((char*)*(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e6254_12) + 0x544) = in->field8;
    return 1;
}
