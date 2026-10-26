#include <globaldefs.h>

struct Struct_ov027_021dcc8c {
    char pad0[0x50d];
    unsigned char unknown_50d_;
    char pad1[0x526 - 0x50e];
    unsigned short unknown_526_;
    char pad2[0x5e4 - 0x528];
    unsigned int unknown_5e4_;
};

struct Struct_ov027_021e33e0_12 {
    char pad[0x8];
    Struct_ov027_021dcc8c *work;
};

extern "C" void func_ov027_021dcc80(void);
extern Struct_ov027_021e33e0_12 data_ov027_021e33e0;
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int);
extern "C" unsigned int func_ov027_021dd55c(int);
extern "C" void func_ov027_021db4e0(int a);
extern "C" int func_ov027_021dcc48(void);
extern "C" int func_ov027_021dd3b0(void);

// USA: func_ov027_021dcc8c
extern "C" ARM int func_ov027_021dcc8c(void) {
    int result = 1;
    unsigned int var1 = DisableIRQInterrupts();
    Struct_ov027_021dcc8c *work = data_ov027_021e33e0.work;
    if (work->unknown_50d_ == 0) {
        func_ov027_021db4e0(0);
    } else if (work->unknown_526_ == 0) {
        work->unknown_5e4_ = 0;
        data_ov027_021e33e0.work->unknown_526_ = 1;
        if (func_ov027_021dd3b0()) {
            func_ov027_021dd55c((unsigned int)func_ov027_021dcc80);
            result = 0;
        } else {
            result = func_ov027_021dcc48();
        }
    }
    SetIRQInterruptState(var1);
    return result;
}
