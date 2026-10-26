#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"

extern "C" void func_020d19e0(void* obj);
extern "C" void func_020d19f4();
extern void* data_02112328;
extern int data_0211232c;
extern int data_02112750;

// USA: func_020d1954
extern "C" ARM void func_020d1954(void* obj) {
    int var0 = DisableIRQInterrupts();
    if (data_02112328 == NULL) {
        data_02112328 = obj;
        func_020d19e0((char*)obj + 0xc4);
        func_020d19e0(&data_0211232c);
        *(int*)((char*)obj + 0xc0) = 0;
        PopulateContext((ProcessorContext*)obj, (unsigned int)func_020d19f4, (unsigned int)obj, (unsigned int)&data_02112750, 0x400, 0x14);
        MarkContextReadyAndSwitch((ProcessorContext*)obj);
    }
    SetIRQInterruptState(var0);
}
