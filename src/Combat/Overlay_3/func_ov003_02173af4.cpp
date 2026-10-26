#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_ov003_02173af4_237 = 0xe9 };
#else
enum { Enum_ov003_02173af4_237 = 0xed };
#endif

struct Struct_ov003_02173af4 {
    char pad0[Enum_ov003_02173af4_237];
    unsigned char unknown_ed_;
    unsigned char pad1;
    unsigned char unknown_ef_;
};

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);

// USA: func_ov003_02173af4
extern "C" ARM void func_ov003_02173af4(struct Struct_ov003_02173af4* p) {
    GameResources* x = GetGameResources();
    if (p->unknown_ef_ == 0) {
        SetSubBrightness(x, -16, 0x18);
        p->unknown_ef_ = 1;
        return;
    }
    if (p->unknown_ef_ != 1) return;
    if (!IsSubBrightnessTransitionActive(x)) {
        p->unknown_ed_ = 6;
        p->unknown_ef_ = 0;
    }
}
