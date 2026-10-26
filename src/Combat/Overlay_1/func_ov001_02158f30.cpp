#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_02158f30
extern "C" ARM void* func_ov001_02158f30(void* ctx, int a, int b, int c) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) {
        *(int*)node = 2;
        node = memcpy((char*)node + 0x10, &a, 0xc);
    }
    return node;
}
