#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_02112780_5 {
    int unknown_0_;
    int unknown_4_;
    void* head;
    int unknown_c_[5];
    int unknown_20_;
};
extern Struct_02112780_5 data_02112780;

// USA: func_020d26ec
extern "C" ARM int func_020d26ec(void) {
    unsigned int mask = DisableIRQInterrupts();
    int result;
    if (data_02112780.head == 0)
        result = data_02112780.unknown_4_;
    else
        result = data_02112780.unknown_20_;
    SetIRQInterruptState(mask);
    return result;
}
