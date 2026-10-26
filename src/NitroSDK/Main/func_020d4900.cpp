#include <globaldefs.h>

#include "NitroSDK/Cache.h"

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int a, int b, int c);

struct Struct_020d4900 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d4900
extern "C" ARM int func_020d4900(void) {
    struct Struct_020d4900* ctx = (struct Struct_020d4900*)func_020d41d8();
    if (func_020d424c(2, 7, 8) != 0) return 0;
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xc), 4);
    if (*(int*)((char*)ctx->sub + 0xc) == 1) return 0;
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x188), 2);
    int flag = (*(unsigned short*)((char*)ctx->sub + 0x188) == 0);
    InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0x3e), 2);
    unsigned short var2 = *(unsigned short*)((char*)ctx->sub + 0x3e);
    if (flag == 1) {
        InvalidateDataCacheRange((const void*)((char*)ctx->sub + 0xf8), 2);
        unsigned short var3 = *(unsigned short*)((char*)ctx->sub + 0xf8);
        return (((var2 + 0xc) * var3 + 0x29) & ~0x1f) << 1;
    }
    return ((var2 + 0x51) & ~0x1f) << 1;
}
