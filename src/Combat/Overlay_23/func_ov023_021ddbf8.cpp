#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
int IsSubBrightnessTransitionActive(GameResources*);
int IsMainBrightnessTransitionActive(GameResources*);

struct Struct_ov023_021dd59c { char pad[
#if defined(jpn)
0x6f8
#else
0x77c
#endif
]; signed char unknown_77c_; };

// USA: func_ov023_021ddbf8
extern "C" ARM int func_ov023_021ddbf8(Struct_ov023_021dd59c* arg) {
    int* p = (int*)GameState::GetInstance()->GetResources();
    int r;
    if (arg->unknown_77c_ == 1) {
        r = IsSubBrightnessTransitionActive((GameResources*)p);
    } else {
        r = IsMainBrightnessTransitionActive((GameResources*)p);
    }
    return r != 0;
}
