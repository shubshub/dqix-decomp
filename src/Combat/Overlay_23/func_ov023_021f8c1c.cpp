#include <globaldefs.h>

extern "C" void __clear(void*, int);

struct Struct_ov023_021f8c1c { unsigned int w[3]; };

// USA: func_ov023_021f8c1c
extern "C" ARM void func_ov023_021f8c1c(void* dst) {
    Struct_ov023_021f8c1c buf;
    __clear(&buf, 0xc);
    *(Struct_ov023_021f8c1c*)dst = buf;
}
