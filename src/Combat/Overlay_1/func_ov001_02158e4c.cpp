#include <globaldefs.h>

extern "C" void* func_ov001_02158d8c(void** ctx);

// USA: func_ov001_02158e4c
extern "C" ARM void* func_ov001_02158e4c(void** ctx) {
    unsigned int* entry = (unsigned int*)func_ov001_02158d8c(ctx);
    if (entry == 0)
        return 0;
    unsigned int* tail = (unsigned int*)ctx[9];
    if (tail != 0)
        tail[0x12] = (unsigned int)entry;
    ctx[9] = entry;
    entry[0x12] = 0;
    if (ctx[8] == 0)
        ctx[8] = entry;
    return entry;
}
