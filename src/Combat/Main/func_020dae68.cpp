#include <globaldefs.h>

extern "C" void func_ov003_0217da48(void* obj);

struct Struct_020dae68 {
    unsigned char pad0[0xc];
    void* unknown_c_;
};

// USA: func_020dae68
extern "C" ARM void func_020dae68(Struct_020dae68* p) {
    void* obj = p->unknown_c_;
    if (obj != NULL) {
        func_ov003_0217da48(obj);
    }
}
