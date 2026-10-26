#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_02111654_6 { int f0; int f4; int f8; };
extern Struct_02111654_6 data_02111654;

// USA: func_020c96a8
extern "C" ARM int func_020c96a8(int value) {
    unsigned int mask;
    mask = DisableIRQInterrupts();
    if (value < data_02111654.f4) {
        data_02111654.f8++;
    }
    data_02111654.f4 = value;
    SetIRQInterruptState(mask);
    return data_02111654.f8;
}
