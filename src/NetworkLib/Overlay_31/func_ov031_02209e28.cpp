#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" ARM void func_ov031_0220b8a0(unsigned int* ctx);
extern "C" ARM void func_ov031_0220b9ac(void* ctx, void* out);
extern "C" void func_ov031_0220b8f4(void* ctx, void* data, int len);
extern unsigned char data_ov031_0224e528[0x14];
extern unsigned char data_ov031_0224e3b0;

// USA: func_ov031_02209e28
extern "C" ARM void func_ov031_02209e28(void* data, int len) {
    unsigned int ctx[0x5c / 4];
    func_ov031_0220b8a0(ctx);
    int state = DisableIRQInterrupts();
    func_ov031_0220b8f4(ctx, data_ov031_0224e528, 0x14);
    func_ov031_0220b8f4(ctx, data, len);
    func_ov031_0220b9ac(ctx, data_ov031_0224e528);
    SetIRQInterruptState(state);
    data_ov031_0224e3b0 = 1;
}
