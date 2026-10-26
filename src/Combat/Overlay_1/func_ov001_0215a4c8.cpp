#include <globaldefs.h>

extern "C" void* func_ov001_0215a054(void*);

// USA: func_ov001_0215a4c8
extern "C" ARM void* func_ov001_0215a4c8(void* ctx, int a) {
    void* node = func_ov001_0215a054(ctx);
    if (node != NULL) {
        *(int*)node = 0x12;
        *(int*)((char*)node + 0x10) = a;
    }
    return node;
}
