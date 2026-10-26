#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020ac234_15040 = 0x3880 };
#else
enum { Enum_020ac234_15040 = 0x3ac0 };
#endif
#include "GameState/GameState.h"

struct Struct_020ac234 {
    unsigned short a;
    unsigned short bit0 : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short rest : 14;
};

// USA: func_020ac234
extern "C" ARM int func_020ac234(struct Struct_020ac234* dst) {
    char* base = (char*)GameState::GetInstance() + Enum_020ac234_15040 + 0x4000;
    unsigned short* src = (unsigned short*)(base + 4);
    int i;
    for (i = 0; i < 0x1d7; i++) {
        struct Struct_020ac234* e = &dst[i];
        e->a = (src[i] & 0xfffc) >> 2;
        e->bit0 = (src[i] & 2) >> 1;
        e->unknown_2_1_ = src[i] & 1;
    }
    return 1;
}
