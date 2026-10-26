#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
extern "C" void* NNS_SndArcSetCurrent(void* value);
extern "C" int func_020bd8ac(unsigned int index);
extern "C" void func_020bd8d4(unsigned int index, int value);

// USA: func_020be3f4
extern "C" ARM void func_020be3f4(int a0, void* a1, unsigned int a2) {
    if (a1 == NULL) return;
    void* prev;
    unsigned int mask = DisableIRQInterrupts();
    prev = NNS_SndArcSetCurrent(a1);
    int val = func_020bd8ac(a2);
    if (a0 == val) {
        func_020bd8d4(a2, 0);
    }
    NNS_SndArcSetCurrent(prev);
    SetIRQInterruptState(mask);
}
