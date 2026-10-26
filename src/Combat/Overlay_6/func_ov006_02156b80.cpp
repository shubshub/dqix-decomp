// KEEP-NAME
// USA: func_ov006_02156b80
#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

extern "C" void func_ov006_021557c0(void*);
extern "C" void func_ov023_021dc488(void*);

extern "C" ARM void func_ov006_02156b80(void* object) {
    Struct_ov006_02154614* var0 = (Struct_ov006_02154614*)object;
    if (!(var0->flags_ & 8)) {
        var0->unknown_238_.AdvanceEffects();
        var0->pot_.AdvanceEffects();
        var0->unknown_390_.AdvanceEffects();
        var0->effect_.SetNormalizedAnimationTime(var0->pot_.normalizedAnimationTime_);
    }
    func_ov006_021557c0(var0);
    func_ov023_021dc488(&var0->window_);
}
