#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* func_ov001_02159f14(void*);

// USA: func_ov001_0215a364
extern "C" ARM void func_ov001_0215a364(void* ctx, EventVec3 v, int e, int f, const char* g) {
    void* node = func_ov001_02159f14(ctx);
    if (node != NULL) {
        *(int*)node = 2;
        memcpy((char*)node + 4, &v, 0xc);
        *(int*)((char*)node + 0x10) = e;
        *(int*)((char*)node + 0x14) = f;
        if (g != NULL) {
            strcpy((char*)node + 0x1c, g);
        }
    }
}
