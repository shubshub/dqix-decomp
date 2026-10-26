#include <globaldefs.h>
#include "World/Object3D.h"

struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);

struct Struct_02076da0 {
    unsigned char unknown_0_[0xb0];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    unsigned char unknown_b6_[0x130 - 0xb6];
    int f130;
    unsigned char unknown_134_[0x17a - 0x134];
    unsigned char unknown_17a_;
};

// USA: func_02076da0
extern "C" ARM int func_02076da0(struct Struct_02076da0* p) {
    if (p->f130 == 0) GameObject_StoreMotionState((struct Foo02033b58*)p, 0);
    else GameObject_ForceMotionState((struct Bytes02033b88*)p, 0);
    p->unknown_b0_ = 0x328;
    p->unknown_b2_ = 0;
    p->unknown_b4_ = 0;
    ((Object3D*)((unsigned char*)p))->DisableFlag(0x80);
    p->unknown_17a_ = 0;
    return 1;
}
