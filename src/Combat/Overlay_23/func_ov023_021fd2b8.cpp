#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct Struct_ov023_021fd2b8 {
    char pad0[0x20];
    int f20;
    int f24;
    unsigned char f28;
    unsigned char unknown_29_;
};

// USA: func_ov023_021fd2b8
extern "C" ARM int func_ov023_021fd2b8(struct Struct_ov023_021fd2b8* s) {
    FontBankLoader* val = FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads(val);
    func_02094b40(val);
    func_02094b34(val, s->f20, s->f24, s->f28, s->unknown_29_);
    return 1;
}
