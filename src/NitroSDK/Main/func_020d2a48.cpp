#include <globaldefs.h>
#include "NitroSDK/Cache.h"

struct Struct_020d2a48 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned int padding[5];
    struct {
        short unknown_0_[16];
        unsigned int unknown_20_;
    } player[16];
    short unknown_260_[16];
};

// USA: func_020d2a48
extern "C" ARM void func_020d2a48(void* p0) {
    Struct_020d2a48* work = (Struct_020d2a48*)p0;
    int var1, var2;

    work->unknown_4_ = 0;
    work->unknown_8_ = 0;
    work->unknown_a_ = 0;
    work->unknown_0_ = 0;

    for (var1 = 0; var1 < 16; var1++) {
        work->player[var1].unknown_20_ = 0;
        for (var2 = 0; var2 < 16; var2++) {
            work->player[var1].unknown_0_[var2] = -1;
        }
    }

    for (var2 = 0; var2 < 16; var2++) {
        work->unknown_260_[var2] = -1;
    }

    CleanInvalidateCacheRange(work, sizeof(Struct_020d2a48));
}
