#include <globaldefs.h>
#include "NitroSDK/Cache.h"

extern "C" int func_020d424c(int, int, int, int, int, int);
extern "C" int func_020d40bc(int, int, int);
extern "C" void func_020d404c(int index, int value);
extern "C" void* func_020d41d8(void);

struct Struct_020d559c {
    unsigned short field0;
    unsigned char pad[0x180];
    unsigned short unknown_182_;
};

struct Struct_020d559c_2 {
    int field0;
    Struct_020d559c* field4;
};


// USA: func_020d559c
extern "C" ARM int func_020d559c(int a0, unsigned int a1) {
    Struct_020d559c_2* ctx = (Struct_020d559c_2*)func_020d41d8();
    int r = func_020d424c(5, 7, 9, 8, 0xa, 0xb);
    if (r != 0) {
        return r;
    }
    unsigned short var2 = ctx->field4->field0;
    if (var2 == 7 || var2 == 9) {
        if (a1 < 1 || a1 > 0xf) {
            return 6;
        }
        InvalidateDataCacheRange(&ctx->field4->unknown_182_, 2);
        if (!(ctx->field4->unknown_182_ & (1 << a1))) {
            return 7;
        }
    } else {
        if (a1 != 0) {
            return 6;
        }
    }
    func_020d404c(0xd, a0);
    r = func_020d40bc(0xd, 1, 1 << a1);
    if (r == 0) {
        r = 2;
    }
    return r;
}
