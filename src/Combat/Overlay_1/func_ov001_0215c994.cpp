#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" float func_ov017_021d6110(void* obj);
extern "C" const char* func_ov017_021d612c(void* obj);
extern "C" int func_ov001_0215ab20(int index);
extern "C" void func_ov001_0215a364(void* ctx, EventVec3 v, int e, int f, const char* g);

// USA: func_ov001_0215c994
extern "C" ARM int func_ov001_0215c994(void* self, int mode) {
    // `label` is DECLARED first on purpose even though it is DEFINED last. Declaration order
    // participates in callee-saved colouring: with `id` declared first, `id` took r4 and the `mode`
    // param took r5 — the exact inversion of the target. Hoisting this declaration above `id` flips
    // that pair (mode->r4, id->r5) and byte-matches. Nothing else about the code changes.
    const char* label;
    int id = func_ov017_021d60f4(self);
    EventVec3 v;
    // 4096.0f * x -> _fmul(0x45800000, x) then _ffix : the float->fx32 idiom. The constant must be
    // the LEFT operand or the argument registers swap.
    v.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 8));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.b = 0xa000;
    int height = func_ov017_021d60f4((char*)self + 0x18);
    label = 0;
    if (mode >= 5) {
        label = func_ov017_021d612c((char*)self + 0x20);
    }
    void* ctx = (void*)func_ov001_0215ab20(id);
    if (ctx == 0) {
        return 0;
    }
    func_ov001_0215a364(ctx, v, height, 1, label);
    return 1;
}
