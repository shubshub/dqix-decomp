#include <globaldefs.h>

extern "C" void* func_ov001_02158d8c(void** ctx);

// USA: func_ov001_02158e0c
extern "C" ARM void* func_ov001_02158e0c(void** ctx) {
    unsigned int* entry = (unsigned int*)func_ov001_02158d8c(ctx);
    if (entry == 0)
        return 0;
    unsigned int* tail = (unsigned int*)ctx[5];
    if (tail != 0)
        tail[0x12] = (unsigned int)entry;
    ctx[5] = entry;
    entry[0x12] = 0;
    if (ctx[4] == 0)
        ctx[4] = entry;
    return entry;
}
