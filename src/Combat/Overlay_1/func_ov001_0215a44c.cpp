#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_ov001_02159f54(void*);

// USA: func_ov001_0215a44c
extern "C" ARM void* func_ov001_0215a44c(void* ctx, EventVec3 v) {
    void* node = func_ov001_02159f54(ctx);
    if (node != NULL) {
        *(int*)node = 7;
        node = memcpy((char*)node + 4, &v, 0xc);
    }
    return node;
}
