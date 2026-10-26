#include <globaldefs.h>


extern "C" void func_020ca3ec(int value, void* dst, int size);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int func_020d1ee4(int a, int b, int c, int d);

struct Struct_0210fd74_2 {
    char pad[0x48];
    int unknown_48_;
};

struct Struct_0210fdbc_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
    unsigned int unknown_14_;
    char pad1[0x1c - 0x18];
    int f1c;
    char pad2[0x24 - 0x20];
    int f24;
    int f28;
    int unknown_2c_;
};

extern Struct_0210fd74_2 data_0210fd74;
extern Struct_0210fdbc_2 data_0210fdbc;

// USA: func_020bd08c
extern "C" ARM void func_020bd08c(void) {
    Struct_0210fdbc_2* ctx = &data_0210fdbc;
    if (data_0210fd74.unknown_48_ == 0) return;
    ctx->f1c = 0;
    func_020ca3ec(0, ctx->unknown_c_, ctx->unknown_14_);
    func_020ca3ec(0, ctx->unknown_10_, ctx->unknown_14_);
    CleanInvalidateCacheRange(ctx->unknown_c_, ctx->unknown_14_);
    CleanInvalidateCacheRange(ctx->unknown_10_, ctx->unknown_14_);
    int shift = ctx->unknown_2c_;
    int mask = (shift >= 0) ? (1 << shift) : 0;
    func_020d1ee4(ctx->f24, ctx->f28, mask, 0);
}
