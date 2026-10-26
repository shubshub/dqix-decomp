#include <globaldefs.h>

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int, int);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int, int);

struct Struct_020d5cc8 {
    unsigned char pad0[4];
    void* sub;
};

// USA: func_020d5cc8
extern "C" ARM int func_020d5cc8(int value) {
    struct Struct_020d5cc8* ctx = (struct Struct_020d5cc8*)func_020d41d8();
    int var1 = func_020d424c(1, 0xb);
    if (var1 != 0) return var1;
    InvalidateDataCacheRange((const void*)((int)((char*)ctx->sub + 0x10)), 4);
    if (*(int*)((char*)ctx->sub + 0x10) == 0) return 3;
    func_020d404c(0x13, value);
    int r = func_020d40bc(0x13, 0);
    return (r == 0) ? 2 : r;
}
