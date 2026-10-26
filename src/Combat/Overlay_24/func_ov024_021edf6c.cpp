#include <globaldefs.h>

struct Struct_ov024_021edf6c { unsigned int pad0; unsigned int field : 12; };

extern "C" int func_ov000_02154a04(void* p0, int p1, unsigned short p2, int p3);

// USA: func_ov024_021edf6c
extern "C" ARM int func_ov024_021edf6c(void** a0, int a1, struct Struct_ov024_021edf6c* a2, int* out, int a4) {
    *out = func_ov000_02154a04(*a0, a1, a2->field, a4);
    return 1;
}
