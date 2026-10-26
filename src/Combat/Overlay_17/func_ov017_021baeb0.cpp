#include <globaldefs.h>

struct S021baeb0 { unsigned char pad[0x20]; void* f20; };

extern "C" void func_ov003_0215c800(void*);
extern "C" void func_ov017_021bac8c(S021baeb0*);

// USA: func_ov017_021baeb0
extern "C" ARM void func_ov017_021baeb0(S021baeb0* obj) {
    void* p = obj->f20;
    if (p) func_ov003_0215c800(p);
    func_ov017_021bac8c(obj);
    ((unsigned char*)obj)[1] = 1;
}
