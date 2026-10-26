#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x34ec };
#else
enum { kRegionalFieldOffset = 0x36fc };
#endif

#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/OverlayId.h"

struct HeadNode02046b24;

extern "C" int Overlay_IsLoaded(unsigned int idx);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** head);

static inline int inline_02065418() {
    return (int)((*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8);
}

static inline void inline_02065418_2(int arg0) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (arg0 << 8);
}

// USA: func_02065418
extern "C" ARM void func_02065418(int arg0) {
    if (!Overlay_IsLoaded(OVERLAY_ID(17))) {
        return;
    }
    HeadNode02046b24** head = *(HeadNode02046b24***)((char*)GameState::GetInstance()->GetResources() + kRegionalFieldOffset);
    if (head == NULL) {
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(head) == 0x2d) {
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(head) == 0x2a) {
        return;
    }
    if (arg0 != 0) {
        return;
    }
    inline_02065418_2(inline_02065418() | 0x10);
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
}
