#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

int ClampInt020d9808(int* value, int* lo, int* hi);

extern int data_020f280c;
extern int data_020f2800;

// Main, originally ClampAndSubmit020d97a8 (USA 0x020d97a8, EUR 0x020d97b8, JPN 0x020db1b4)
ARM int ProcessorContext_Create(ProcessorContext* context, void* stackSpace, unsigned int stackSize,
                             int relativePriority, const void* entry, int userdata) {
    int priority = ClampInt020d9808(&relativePriority, &data_020f280c, &data_020f2800) + 16;
    PopulateContext(context, (unsigned int)entry, userdata,
                    (unsigned int)((char*)stackSpace + stackSize), stackSize, priority);
    return 1;
}
