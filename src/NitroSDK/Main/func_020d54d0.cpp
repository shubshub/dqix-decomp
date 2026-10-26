#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

extern "C" int func_020d424c(int a, int b);
extern "C" void* func_020d41d8(void);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d4168(void* a, unsigned int b);

struct Struct_020d54d0 { unsigned short len; };

struct Struct_020d54d0_2 {
    unsigned short tag;
    Struct_020d54d0* ptr;
    unsigned char unknown_8_[0x18];
    int unknown_20_;
    unsigned char unknown_24_[2];
    unsigned short unknown_26_;
};


// USA: func_020d54d0
extern "C" ARM int func_020d54d0(int a0, Struct_020d54d0* a1, const void* a2, int a3, unsigned short a4) {
    int r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    if (a1 == NULL) {
        return 6;
    }
    CleanCacheRange(a1, a1->len << 1);
    void* ctx = func_020d41d8();
    *(unsigned short*)((char*)ctx + 0x150) = 0;
    *(int*)((char*)ctx + 0x14c) = 0;
    func_020d404c(0xc, a0);
    struct Struct_020d54d0_2 buf;
    buf.tag = 0xc;
    buf.ptr = a1;
    if (a2 != NULL) {
        VectorizedInvertedMemcpy(a2, buf.unknown_8_, 0x18);
    } else {
        VectorizedMemset(buf.unknown_8_, 0, 0x18);
    }
    buf.unknown_20_ = a3;
    buf.unknown_26_ = a4;
    r = func_020d4168(&buf, 0x28);
    return (r == 0) ? 2 : r;
}
