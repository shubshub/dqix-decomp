#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_ov027_021dd3cc(void *p);
extern "C" void func_ov027_021dd218();

struct Struct_ov027_021e3420 { void *field0; };
extern struct Struct_ov027_021e3420 data_ov027_021e3420;

// USA: func_ov027_021dd330
extern "C" ARM void func_ov027_021dd330(void *arg0, unsigned int size) {
    int state = DisableIRQInterrupts();
    if (data_ov027_021e3420.field0 == NULL) {
        char *ctx = (char *)arg0;
        data_ov027_021e3420.field0 = arg0;
        func_ov027_021dd3cc(ctx + 0xc4);
        *(unsigned int *)(ctx + 0xc0) = 0;
        unsigned int stackSize = (size - 0xe4) & ~3;
        unsigned int var3 = (unsigned int)(ctx + 0xe4) + stackSize;
        PopulateContext((ProcessorContext *)arg0, (unsigned int)func_ov027_021dd218, (unsigned int)arg0, var3, stackSize, 0);
        MarkContextReadyAndSwitch((ProcessorContext *)arg0);
    }
    SetIRQInterruptState(state);
}
