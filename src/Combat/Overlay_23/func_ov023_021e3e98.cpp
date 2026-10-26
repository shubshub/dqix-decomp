#if defined(jpn)
enum {regionalOffset0=0x4e0, regionalOffset1=0x4e4, regionalOffset2=0x56c, regionalOffset3=0x3d44, regionalOffset4=0x4e2};
#else
enum {regionalOffset0=0x4e4, regionalOffset1=0x4e8, regionalOffset2=0x634, regionalOffset3=0x3dcc, regionalOffset4=0x4e6};
#endif
#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_ov023_021e29d0(void* a);

struct Struct_ov023_021e3e98 {
    void* f0;
    char pad4[0xd4 - 4];
    char unknown_d4_[1];
    char unknown_d5_[regionalOffset0 - 0xd5];
    unsigned char unknown_4e4_;
    char unknown_4e5_[1];
    unsigned char unknown_4e6_;
    unsigned char unknown_4e7_;
    char unknown_4e8_[regionalOffset2 - regionalOffset1];
    unsigned short unknown_634_;
};

// USA: func_ov023_021e3e98
extern "C" ARM void func_ov023_021e3e98(struct Struct_ov023_021e3e98* obj) {
    int cond = (func_ov023_021e29d0(&obj->unknown_d4_) == 0x1f);
    if (cond) {
        obj->unknown_634_ |= 0x800;
    }

    if (obj->f0 != 0 && (*(int*)((char*)obj->f0 + regionalOffset3) & 0x400) == 0) {
        return;
    }

    if (g_keyManager.TestKeysPressed(2) != 0) {
        cond = 1;
    }
    if (!cond) {
        return;
    }

    obj->unknown_634_ |= 0x800;
    signed char tmp = *(signed char*)((char*)obj + regionalOffset4);
    obj->unknown_4e7_ = tmp;
    obj->unknown_4e6_ = 1;
    obj->unknown_4e4_ = 0;
}
