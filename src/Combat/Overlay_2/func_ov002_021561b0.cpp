#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct Struct_ov002_021561b0_2 {
#if defined(jpn)
    char pad[0x2aa];
#else
    char pad[0x47a];
#endif
    unsigned char state;
    unsigned char unknown_47b_;
    unsigned int flags;
};

struct Struct_ov002_021561b0 {
    char pad[0x2000];
    struct Struct_ov002_021561b0_2 sub;
};

// USA: func_ov002_021561b0
extern "C" ARM void func_ov002_021561b0(struct Struct_ov002_021561b0* self) {
    unsigned int flags = self->sub.flags;
    if ((flags & 2) == 0) {
        return;
    }
    unsigned char state = self->sub.state;
    if (state == 0) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(g);
        func_02094b3c(g, 0xc);
        func_02094b34(g, 0x64, 0x208, 0, 0);
        self->sub.state = self->sub.state + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    if (!func_02094b4c(FontBankLoader_GetInstance())) {
        return;
    }
    self->sub.flags = self->sub.flags & ~2;
    self->sub.state = 0;
}
