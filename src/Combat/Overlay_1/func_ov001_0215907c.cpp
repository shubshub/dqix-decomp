#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_0215907c
extern "C" ARM void* func_ov001_0215907c(void* ctx, EventVec3 v1, EventVec3 v2) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) {
        *(int*)node = 8;
        memcpy((char*)node + 4, &v1, 0xc);
        return memcpy((char*)node + 0x10, &v2, 0xc);
    }
    return node;
}
