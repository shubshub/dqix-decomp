#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
int SetSubBrightness(GameResources*, int, int);
int SetMainBrightness(GameResources*, int, int);

// USA: func_ov023_021ddbb8
extern "C" ARM int func_ov023_021ddbb8(void* obj, int a, int b) {
    int w = (int)GameState::GetInstance()->GetResources();
    signed char sb = *(signed char*)((char*)obj
#if defined(jpn)
        + 0x6f8
#else
        + 0x77c
#endif
);
    if (sb == 1) {
        return SetSubBrightness((GameResources*)w, a, b);
    }
    return SetMainBrightness((GameResources*)w, a, b);
}
