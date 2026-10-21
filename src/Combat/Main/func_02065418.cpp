#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02065418_14076 = 0x34ec };
#else
enum { Enum_02065418_14076 = 0x36fc };
#endif

#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/OverlayId.h"

struct Struct_02015438;

int IsIndexMappedToSelf020a18f4(unsigned int idx);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** head);

static inline int inline_02065418() {
    return (int)((*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8);
}

static inline void inline_02065418_2(int arg0) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (arg0 << 8);
}

// USA: func_02065418
extern "C" ARM void func_02065418(int arg0) {
    if (!func_020a18f4(OVERLAY_ID(17))) {
        return;
    }
    HeadNode02046b24** head = *(HeadNode02046b24***)((char*)GameState::GetInstance()->GetResources() + kRegionalFieldOffset);
    if (head == NULL) {
        return;
    }
    if (func_02046b24(var0) == 0x2d) {
        return;
    }
    if (func_02046b24(var0) == 0x2a) {
        return;
    }
    if (arg0 != 0) {
        return;
    }
    inline_02065418_2(inline_02065418() | 0x10);
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
}
