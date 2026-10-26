#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_02158f64
extern "C" ARM void func_ov001_02158f64(void* ctx, EventVec3 v1, EventVec3 v2, int d, int one, unsigned char arg5) {
    char* node = (char*)func_ov001_02158dcc(ctx);
    if (node != NULL) {
        *(int*)node = 3;
        memcpy(node + 4, &v1, 0xc);
        memcpy(node + 0x10, &v2, 0xc);
        *(int*)(node + 0x1c) = d;
        *(int*)(node + 0x20) = one;
        *(int*)(node + 0x24) = arg5;
    }
}
