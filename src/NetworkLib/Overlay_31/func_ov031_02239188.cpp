#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern unsigned short* data_ov031_02290d14;
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

// USA: func_ov031_02239188
extern "C" ARM int func_ov031_02239188(int arg0) {
    unsigned int state = DisableIRQInterrupts();
    unsigned short mask = 1 << arg0;
    if (!(data_ov031_02290d14[1] & mask)) {
        SetIRQInterruptState(state);
        return 0;
    }
    unsigned short buf[7];
    VectorizedInvertedMemcpy(data_ov031_02290d14, buf, 0xe);
    SetIRQInterruptState(state);
    if (buf[2] & mask) return 2;
    if (buf[3] & mask) return 3;
    if (buf[4] & mask) return 4;
    if (buf[5] & mask) return 5;
    if (buf[6] & mask) return 6;
    return 1;
}
