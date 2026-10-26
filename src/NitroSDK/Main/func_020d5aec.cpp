#include <globaldefs.h>

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int a, int b, int c);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d40bc(int a, int b);

struct Struct_020d5aec {
    unsigned char pad0[4];
    char* f4;
};

// USA: func_020d5aec
extern "C" ARM int func_020d5aec(int a) {
    struct Struct_020d5aec* ctx = (struct Struct_020d5aec*)func_020d41d8();
    int r = func_020d424c(2, 9, 0xa);
    if (r != 0) {
        return r;
    }
    InvalidateDataCacheRange((const void*)((int)(ctx->f4 + 0xc)), 4);
    if (*(int*)(ctx->f4 + 0xc) == 0) {
        return 3;
    }
    func_020d404c(0x10, a);
    r = func_020d40bc(0x10, 0);
    return (r == 0) ? 2 : r;
}
