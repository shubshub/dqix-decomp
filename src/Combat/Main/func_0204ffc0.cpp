#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include <std_library_functions.h>

extern "C" int func_02050064(void* obj);
extern "C" void func_0204fa0c(void* obj, short a, short b);
extern "C" int func_0204a5e4(int a, int b);

struct Struct_0204ffc0 {
    char pad[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

struct Obj0204ffc0 {
    char pad0[0x4];
    Struct_0204ffc0* unknown_4_;      // 0x4
    void* buf;                  // 0x8
    char pad1[0xa0-0xc];
    int unknown_a0_;                 // 0xa0
    int len;                    // 0xa4
    char pad2[0xbc-0xa8];
    short sa;                   // 0xbc
    short sb;                   // 0xbe
    char pad3[0xc5-0xc0];
    unsigned char flags;        // 0xc5
};

// USA: func_0204ffc0
extern "C" ARM void func_0204ffc0(Obj0204ffc0* a, int) {
    if (a->unknown_4_ == NULL || a->buf == NULL)
        return;
    unsigned char lo = a->unknown_4_->unknown_1c_0_;
    unsigned char hi = a->unknown_4_->unknown_1c_4_;
    int r3 = func_02050064(a);
    if (!r3)
        return;
    if (r3) {
        memcpy(a->buf, (void*)(r3 + a->unknown_a0_), a->len);
    }
    a->flags |= 0x40;
    func_0204fa0c(a, a->sa, a->sb);
    void (*fp)(void*, int, unsigned int) = (void(*)(void*, int, unsigned int))func_0204a5e4(lo, hi);
    CleanInvalidateCacheRange(a->buf, a->len);
    fp(a->buf, a->unknown_a0_, a->len);
}
