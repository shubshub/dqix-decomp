#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

extern char data_021142e0;

struct Struct_020d46cc { unsigned char pad[0x150]; unsigned short unknown_150_; };

// USA: func_020d46cc
extern "C" ARM int func_020d46cc(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct Struct_020d46cc* ctx = *(struct Struct_020d46cc**)(&data_021142e0 + 4);
    int result = ctx ? ctx->unknown_150_ : 0;
    SetIRQInterruptState(mask);
    return result;
}
