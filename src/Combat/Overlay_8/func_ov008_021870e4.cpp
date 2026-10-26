#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_ov008_021870e4 {
    unsigned char pad0[0x40];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
};
extern int data_ov008_0218b495;

struct Struct_ov008_02184754 { char pad[0xb18]; unsigned int unknown_b18_; };

// USA: func_ov008_021870e4
extern "C" ARM void func_ov008_021870e4(struct Struct_ov008_02184754* obj, unsigned int ticks) {
    if (!(obj->unknown_b18_ & 0x4000)) return;
    if (!((Object3D*)((struct Struct_ov008_021870e4*)((char*)obj + 0x790)))->HasAnimationReachedEnd()) return;
    ((Object3D*)((char*)obj + 0x790))->SetAnimationByName((char const*)&data_ov008_0218b495, 0);
    obj->unknown_b18_ &= ~0x4000;
}
