#include <globaldefs.h>


struct Struct_ov027_021dcc8c {
    char pad[0x1320];
    void *pending;
};

struct Struct_ov027_021e33e0_12 {
    char pad[0xc];
    Struct_ov027_021dcc8c *work;
};

extern Struct_ov027_021e33e0_12 data_ov027_021e33e0;
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int);
extern "C" void HaltSystem(void);
extern "C" void func_ov027_021dcc8c(void);

// USA: func_ov027_021dcd20
extern "C" ARM void func_ov027_021dcd20(void) {
    unsigned int var0 = DisableIRQInterrupts();
    if (data_ov027_021e33e0.work->pending == 0) {
        HaltSystem();
    }
    func_ov027_021dcc8c();
    SetIRQInterruptState(var0);
}
