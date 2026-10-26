#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_02112780_6 {
    unsigned int field0;
    unsigned int field4;
};
extern struct Struct_02112780_6 data_02112780;


// USA: func_020d2718
extern "C" ARM int func_020d2718(unsigned int x) {
    unsigned int mask = DisableIRQInterrupts();
    unsigned int cur = data_02112780.field4;
    int result;
    if (x > cur) {
        if ((x - cur) < 0x80000000u) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = (cur - x) < 0x80000000u;
    }
    SetIRQInterruptState(mask);
    return result;
}
