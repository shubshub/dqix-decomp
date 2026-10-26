#include <globaldefs.h>

extern "C" void* func_ov001_02159f14(void*);

// USA: func_ov001_0215a3c0
extern "C" ARM void* func_ov001_0215a3c0(void* ctx) {
    void* node = func_ov001_02159f14(ctx);
    if (node != NULL) *(int*)node = 3;
    return node;
}
