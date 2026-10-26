#include <globaldefs.h>

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_02159044
extern "C" ARM void* func_ov001_02159044(void* ctx) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) *(int*)node = 6;
    return node;
}
