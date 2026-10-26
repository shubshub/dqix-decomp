#include <globaldefs.h>
#include "NitroSDK/NSBXX/RenderCommands_Common.h"

extern "C" void func_020ca568(void* block, void* dst);

// USA: func_020c54fc
ARM int func_020c54fc(void* dst) {
    unsigned int* base = (unsigned int*)0x4000600;
    if (*base & 0x8000000) {
        return -1;
    }
    func_020ca568((unsigned char*)base + 0x40, dst);
    return 0;
}
