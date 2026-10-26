#include <globaldefs.h>

extern "C" void* func_ov001_0215a014(void*);

// USA: func_ov001_0215a6dc
extern "C" ARM void* func_ov001_0215a6dc(void* ctx, int a) {
    void* node = func_ov001_0215a014(ctx);
    if (node != NULL) {
        *(int*)node = 0x19;
        *(int*)((char*)node + 0x10) = a;
    }
    return node;
}
