#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" int func_020d9808(int* value, int* lo, int* hi);

extern int data_020f280c;
extern int data_020f2800;

// Main, originally ClampAndSubmit020d97a8 (USA 0x020d97a8, EUR 0x020d97b8, JPN 0x020db1b4)
extern "C" ARM int ProcessorContext_Create(ProcessorContext* context, void* stackSpace, unsigned int stackSize,
                             int arg3, const void* entry, int arg5) {
    int priority = func_020d9808(&arg3, &data_020f280c, &data_020f2800) + 16;
    PopulateContext(context, (unsigned int)entry, arg5,
                    (unsigned int)((char*)stackSpace + stackSize), stackSize, priority);
    return 1;
}
