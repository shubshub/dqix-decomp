#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int a, int b);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int a, int b, int c, int d, int e, int f);

struct Struct_020d5bfc {
    unsigned char pad0[4];
    void* sub;
};


// USA: func_020d5bfc
extern "C" ARM int func_020d5bfc(int a0, void* a1, void* a2, unsigned int a3) {
    struct Struct_020d5bfc* ctx = (struct Struct_020d5bfc*)func_020d41d8();
    int var1 = func_020d424c(1, 0xb);
    if (var1 != 0) return var1;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0x10)), 4);
    if (*(int*)((char*)ctx->sub + 0x10) == 0) return 3;
    if (a3 > 0x5e4) return 6;
    CleanCacheRange(a2, a3);
    func_020d404c(0x12, a0);
    unsigned char buf[8];
    VectorizedInvertedMemcpy(a1, buf, 6);
    int r = func_020d40bc(0x12, 4, *(int*)&buf[0], *(int*)&buf[4], (int)a2, (int)a3);
    return (r == 0) ? 2 : r;
}
