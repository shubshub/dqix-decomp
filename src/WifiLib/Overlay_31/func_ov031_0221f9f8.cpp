#include <globaldefs.h>

int DisableIRQInterrupts();
void SetIRQInterruptState(int);

struct Struct_ov031_0224f670_10 {
    char pad[0x68];
    int a;
    int b;
};

extern Struct_ov031_0224f670_10 data_ov031_0224f670;
extern int data_ov031_0224f6f4[4];

// USA: func_ov031_0221f9f8
extern "C" THUMB void func_ov031_0221f9f8() {
    int var0 = DisableIRQInterrupts();
    data_ov031_0224f670.a = 0;
    data_ov031_0224f670.b = 0;
    int i = 0;
    int* p = data_ov031_0224f6f4;
    do {
        i++;
        *p++ = 0;
    } while (i < 4);
    SetIRQInterruptState(var0);
}
