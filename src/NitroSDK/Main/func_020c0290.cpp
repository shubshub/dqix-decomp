#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" void VectorizedInvertedMemcpy(void* src, void* dst, int n);

struct Struct_020c0290 {
    unsigned short magic;
    unsigned short pad2;
    unsigned short pad4;
    unsigned short unknown_6_;
};

struct Struct_020c0290_2 {
    char pad0[0x3c];
    unsigned short f3c;
    char unknown_3e_[0x44 - 0x3e];
    int unknown_44_;
    char unknown_48_[0x50 - 0x48];
    char unknown_50_[8];
};

// USA: func_020c0290
extern "C" ARM int func_020c0290(struct Struct_020c0290_2* obj) {
    if (obj == NULL) return 0;
    if (obj->f3c == 0) return 0;

    struct Struct_020c0290 buf;
    VectorizedInvertedMemcpy(obj->unknown_50_, &buf, 8);
    CleanCacheRange(&buf, 8);

    if (obj->unknown_44_ != 0) goto fail;
    if (buf.magic != 0x2348 && *(volatile unsigned short*)&buf.magic != 0xbd8a) goto fail;
    if (buf.unknown_6_ == 4) return 1;
fail:
    return 0;
}
