#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern "C" void* func_ov001_0215ab20(void*);
extern "C" void func_ov001_0215a364(void* ctx, EventVec3 v, int e, int f, const char* g);

// USA: func_ov001_0215c06c
extern "C" ARM int func_ov001_0215c06c(void* self, int mode) {
    const char* g;
    void* x = func_ov017_021d60f4(self);
    EventVec3 v;
    v.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    int e = (int)func_ov017_021d60f4((char*)self + 0x20);
    g = 0;
    if (mode >= 6) {
        g = (const char*)func_ov017_021d612c((char*)self + 0x28);
    }
    void* node = func_ov001_0215ab20(x);
    if (node != NULL) {
        func_ov001_0215a364(node, v, e, 0, g);
        return 1;
    }
    return 0;
}
