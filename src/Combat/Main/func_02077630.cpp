#include <globaldefs.h>
#include "World/Object3D.h"

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char unknown_40_0_ : 3;
    unsigned char unknown_40_3_ : 5;
};

struct Vector3i;

struct Struct020372b8 {
    char pad[0x40];
    unsigned char unknown_40_0_ : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short unknown_70_;
};

extern "C" void func_02076ccc(void*, int);

// USA: func_02077630
extern "C" ARM void func_02077630(void* obj) {
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0 && ((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0x1f) {
        return;
    }
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() == 0) {
        *(Vector3i*)((int*)((char*)obj + 0x44)) = *(Vector3i const*)((int*)((char*)obj + 0x158));
        ((Object3D*)((struct Struct020372b8*)obj))->TransitionInheritedAlpha(0x1f, 0xfa);
    }
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0x1f) {
        return;
    }
    func_02076ccc(obj, 1);
}
