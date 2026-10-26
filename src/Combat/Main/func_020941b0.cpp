#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_02093b90_2 {
    #if defined(jpn)
    char pad0[0x100];
#else
    char pad0[0x340];
#endif
    int handle;
    #if defined(jpn)
    char pad1[0x138 - 0x104];
#else
    char pad1[0x3c8 - 0x344];
#endif
    unsigned char unknown_3c8_;
    char pad2[0x3cd - 0x3c9];
    unsigned char unknown_3cd_0_ : 4;
    unsigned char unknown_3cd_4_ : 4;
};

// USA: func_020941b0
extern "C" ARM void func_020941b0(struct Struct_02093b90_2* p) {
    int x = (int)BackgroundLoader::GetInstance();
    if (p->handle >= 0) {
        ((BackgroundLoader*)(x))->RemoveTask((int)(p->handle));
        p->handle = -1;
    }
    p->unknown_3c8_ &= ~0x7f;
    p->unknown_3cd_0_ = 0;
    #if defined(jpn)
    ((unsigned char*)p)[0x13d] |= 8;
#else
    ((unsigned char*)p)[0x3cd] |= 8;
#endif
}
