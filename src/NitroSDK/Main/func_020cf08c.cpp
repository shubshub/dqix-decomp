#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" int func_020cf88c(void);

struct Struct_02111818 {
    unsigned char pad0[0xc];
    unsigned int busy;
    unsigned int f10;
    unsigned int f14;
    unsigned char unknown_18_[4];
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
};

extern struct Struct_02111818 data_02111818;

// USA: func_020cf08c
extern "C" ARM int func_020cf08c(int a, int b, int c) {
    unsigned int mask = DisableIRQInterrupts();
    if (data_02111818.busy != 0) {
        SetIRQInterruptState(mask);
        return 1;
    }
    data_02111818.busy = 1;
    SetIRQInterruptState(mask);
    data_02111818.f20 = 0;
    data_02111818.f24 = 0;
    data_02111818.f14 = a;
    data_02111818.f10 = b;
    data_02111818.f1c = c;
    return func_020cf88c() ? 0 : 3;
}
