#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define REGION(j,u) (j)
#else
#define REGION(j,u) (u)
#endif

struct Struct_ov023_021dd974 {
    char unknown_0_[REGION(0x6f0,0x774)];
    unsigned short flags;
    char unknown_776_[7];
    signed char displayState;
};

extern "C" void func_ov023_021dfb4c(void* obj);
extern "C" void func_ov023_021ddae4(void* obj);
extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
extern "C" int func_ov023_021ddbb8(void* obj, int a, int b);

// USA: func_ov023_021dd974
extern "C" ARM void func_ov023_021dd974(void* obj) {
    Struct_ov023_021dd974* view = (Struct_ov023_021dd974*)obj;
    if (!(view->flags & 0x4000)) {
        func_ov023_021dfb4c(obj);
    }
    func_ov023_021ddae4(obj);

    if (view->displayState >= 0) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
    }

    if (!(view->flags & 0x40)) return;

    GameState::GetInstance()->GetResources();

    if (!(view->flags & 0x20)) return;

    func_ov023_021ddbb8(obj, 0, 8);
    view->flags &= ~0x20;
}
