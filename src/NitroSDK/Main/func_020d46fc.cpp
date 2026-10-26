#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

extern char data_021142e0;

struct Struct_020d46fc { unsigned char pad[0x14c]; int unknown_14c_; };

// USA: func_020d46fc
extern "C" ARM unsigned short func_020d46fc(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct Struct_020d46fc* ctx = *(struct Struct_020d46fc**)(&data_021142e0 + 4);
    int value = ctx ? ctx->unknown_14c_ : 0;
    SetIRQInterruptState(mask);
    return (unsigned short)value;
}
