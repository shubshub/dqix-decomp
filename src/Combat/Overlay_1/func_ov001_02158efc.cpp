#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_02158efc
extern "C" ARM void* func_ov001_02158efc(void* ctx, EventVec3 v) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) {
        *(int*)node = 1;
        node = memcpy((char*)node + 4, &v, 0xc);
    }
    return node;
}
