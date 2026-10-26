#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(void*);
extern "C" int func_ov001_0215a608(void* node, EventVec3 v, int count);

// USA: func_ov001_0215c330
extern "C" ARM int func_ov001_0215c330(void* self, int mode) {
    int count = 0;
    void* x = func_ov017_021d60f4(self);
    EventVec3 v;
    v.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    if (mode >= 5) {
        count = (int)func_ov017_021d60f4((char*)self + 0x20);
    }
    void* node = func_ov001_0215ab20(x);
    if (node != NULL) {
        func_ov001_0215a608(node, v, count);
        return 1;
    }
    return 0;
}
