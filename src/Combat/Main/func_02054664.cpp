#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void GameObject_InitPartyMember(void *obj);

struct Struct_02054664 {
    unsigned short field0;
    #if defined(jpn)
    char pad2[0x2c2];
#else
    char pad2[0x2ce];
#endif
    signed char unknown_2d0_;
    signed char unknown_2d1_;
    signed char unknown_2d2_;
};

// USA: func_02054664
extern "C" ARM void func_02054664(struct Struct_02054664 *obj) {
    GameObject_InitPartyMember(obj);
    obj->field0 |= 0x1000;
    obj->unknown_2d0_ = -1;
    obj->unknown_2d1_ = -1;
    obj->unknown_2d2_ = 0;
    ((Object3D*)((unsigned char *)obj))->EnableFlag(0x80);
}
