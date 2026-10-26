#include <globaldefs.h>
#include "NitroSDK/NSBXX/RenderCommands_Common.h"

extern "C" void MI_Copy36B(void* block, void* dst);

// USA: func_020c552c
ARM int func_020c552c(void* dst) {
    unsigned int* base = (unsigned int*)0x4000600;
    if (*base & 0x8000000) {
        return -1;
    }
    MI_Copy36B((unsigned char*)base + 0x80, dst);
    return 0;
}
