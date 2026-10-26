#include <globaldefs.h>

extern "C" void* func_ov001_02159f14(void*);

// USA: func_ov001_0215a42c
extern "C" ARM void* func_ov001_0215a42c(void* ctx, int a) {
    void* node = func_ov001_02159f14(ctx);
    if (node != NULL) {
        *(int*)node = 6;
        *(int*)((char*)node + 0x10) = a;
    }
    return node;
}
