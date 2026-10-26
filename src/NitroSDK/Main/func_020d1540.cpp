#include <globaldefs.h>

int ReleaseGBABus(unsigned short owner);
typedef int (*Type_020d1540)(int);
unsigned int SetIRQInterruptState(int);

struct Struct_020d135c_3 {
    int field0;
    unsigned int unknown_4_;
};

// USA: func_020d1540
extern "C" ARM unsigned int func_020d1540(int a, struct Struct_020d135c_3* s) {
    if (s->field0 == 0) ((Type_020d1540)&ReleaseGBABus)(a);
    return SetIRQInterruptState(s->unknown_4_);
}
