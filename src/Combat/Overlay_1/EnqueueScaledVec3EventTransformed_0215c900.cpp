#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(void*);
extern "C" int Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(int seed, EventVec3* v);
void* EnqueueEventType1_0215a330(void* ctx, EventVec3 v);

// USA: func_ov001_0215c900
ARM int EnqueueScaledVec3EventTransformed_0215c900(void* self) {
    void* x = func_ov017_021d60f4(self);
    EventVec3 v;
    v.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    int tmp = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.b = 0xa000;
    v.c = tmp;
    v.b = Zone3D_GetGroundHeight(Zone3D_GetInstance(), &v);
    void* node = func_ov001_0215ab20(x);
    if (node != NULL) {
        EnqueueEventType1_0215a330(node, v);
        return 1;
    }
    return 0;
}
