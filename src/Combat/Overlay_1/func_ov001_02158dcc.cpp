#include <globaldefs.h>

extern "C" void* func_ov001_02158d8c(void** ctx);

// USA: func_ov001_02158dcc
extern "C" ARM void* func_ov001_02158dcc(void** ctx) {
    unsigned int* entry = (unsigned int*)func_ov001_02158d8c(ctx);
    if (entry == 0)
        return 0;
    unsigned int* tail = (unsigned int*)ctx[3];
    if (tail != 0)
        tail[0x12] = (unsigned int)entry;
    ctx[3] = entry;
    entry[0x12] = 0;
    if (ctx[2] == 0)
        ctx[2] = entry;
    return entry;
}
