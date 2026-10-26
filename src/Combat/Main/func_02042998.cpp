#include <globaldefs.h>

struct Struct_020421c4_3 {
    char pad[8];
    char* unknown_8_;
    char* unknown_c_;
};

// USA: func_02042998
extern "C" ARM void func_02042998(struct Struct_020421c4_3* p) {
    if (p != 0) {
        p->unknown_8_ = (char*)p + (int)p->unknown_8_;
        p->unknown_c_ = (char*)p + (int)p->unknown_c_;
    }
}
