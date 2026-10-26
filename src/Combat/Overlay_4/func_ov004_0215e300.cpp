#include <globaldefs.h>

struct Struct_ov004_0215e300 { unsigned int w[3]; };
extern "C" void __clear(void* buf, int size);

// USA: func_ov004_0215e300
extern "C" ARM void func_ov004_0215e300(Struct_ov004_0215e300* dst) {
    Struct_ov004_0215e300 tmp;
    __clear(&tmp, sizeof(tmp));
    *dst = tmp;
}
