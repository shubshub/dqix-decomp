#include <globaldefs.h>

extern "C" int func_020d424c(int a, int b, int c);
extern "C" int func_020d40bc(int a, int b, const void* buf, unsigned int size,
                             unsigned short e0, unsigned short e1, unsigned short e2,
                             int f, int g);
extern "C" void* func_020d41d8(void);
extern "C" void InvalidateDataCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

struct Struct_020d59bc {
    char pad0[0x7c];
    const void* field7c;
    char unknown_80_[6];
    unsigned short unknown_86_;
    char unknown_88_[0xfa];
    unsigned short unknown_182_;
    char unknown_184_[4];
    unsigned short unknown_188_;
};

struct Struct_020d59bc_2 {
    char pad0[4];
    struct Struct_020d59bc* field4;
};

// USA: func_020d59bc
extern "C" ARM int func_020d59bc(int a, int b, const void* buf, unsigned int size,
                                 unsigned short e0, unsigned short e1, unsigned short e2) {
    int count = 1;
    struct Struct_020d59bc* var1 = ((struct Struct_020d59bc_2*)func_020d41d8())->field4;
    int r = func_020d424c(2, 9, 0xa);
    if (r != 0) {
        return r;
    }
    InvalidateDataCacheRange(&var1->unknown_188_, 2);
    if (var1->unknown_188_ == 0) {
        InvalidateDataCacheRange(&var1->unknown_182_, 2);
        count = var1->unknown_182_;
        InvalidateDataCacheRange(&var1->unknown_86_, 2);
    }
    if (buf == 0) {
        return 6;
    }
    if (count == 0) {
        return 7;
    }
    InvalidateDataCacheRange(&var1->field7c, 2);
    if (buf == var1->field7c) {
        return 6;
    }
    if (size > 0x200) {
        return 6;
    }
    if (size == 0) {
        return 6;
    }
    CleanCacheRange(buf, size);
    r = func_020d40bc(0xf, 7, buf, size, e0, e1, e2, a, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}
