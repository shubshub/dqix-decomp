#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_02155508 {
    unsigned char pad0[LOW_REGION(0x34, 0x1b4)];
    unsigned int unknown_1b4_;
    unsigned int unknown_1b8_;
    unsigned char pad1[0x1c0 - 0x1bc];
    unsigned int unknown_1c0_;
    unsigned char pad2[0xad4 - 0x1c4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char pad3[0xade - 0xadc];
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char pad4[0xae2 - 0xae0];
    unsigned short flags;
};

// USA: func_ov006_02155508
extern "C" ARM void func_ov006_02155508(Struct_ov006_02155508* s) {
    if (s->flags & 1)
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (s->unknown_ad4_ >= 0) {
        loader->RemoveTask(s->unknown_ad4_);
        s->unknown_ad4_ = -1;
    }
    s->unknown_ad4_ = -1;

    s->unknown_ade_ = 0;
    s->flags &= ~2;

    if (s->unknown_ad8_ >= 0) {
        loader->RemoveTask(s->unknown_ad8_);
        s->unknown_ad8_ = -1;
    }
    s->unknown_ad8_ = -1;

    s->unknown_adf_ = 0;
    s->unknown_1b4_ = 0;
    s->unknown_1b8_ = 0;
    s->unknown_1c0_ = 0;

    s->flags = (s->flags | 1) & ~4;
}
