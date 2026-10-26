#include <globaldefs.h>

extern "C" void func_020a2d14(void* actor);
extern "C" void func_020a20f0(void* actor);

// Main, originally AdvanceActor020a20d8 (USA 0x020a20d8, EUR 0x020a20e8, JPN 0x020a3e50)
extern "C" ARM void FollowCamera_Update(void* actor) {
    func_020a2d14(actor);
    func_020a20f0(actor);
}
