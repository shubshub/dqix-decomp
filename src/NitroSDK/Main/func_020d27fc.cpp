#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
extern "C" void func_020d29b0(int packed);

// USA: func_020d27fc
extern "C" ARM void func_020d27fc(int channel, int packed) {
    unsigned int mask = DisableIRQInterrupts();
    func_020d29b0(packed);
    SetIRQInterruptState(mask);
}
