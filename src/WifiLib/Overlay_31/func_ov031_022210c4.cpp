#include <globaldefs.h>

extern "C" long long func_0200cf24(long long a, long long b);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" int memcmp(const void* a, const void* b, int n);
extern "C" int func_ov031_0222157c(unsigned int* rk, const unsigned char* cipherKey, int keyBits);
extern "C" void func_ov031_0222127c(const unsigned char* a, const unsigned char* b, unsigned char* out);
extern "C" void func_ov031_02221ac8(const unsigned int* rk, int Nr, const unsigned char* ct, unsigned char* pt);

#define BSWAP64(x) \
    ((((x) & 0x00000000000000ffULL) << 56) | \
     (((x) & 0x000000000000ff00ULL) << 40) | \
     (((x) & 0x0000000000ff0000ULL) << 24) | \
     (((x) & 0x00000000ff000000ULL) <<  8) | \
     (((x) & 0x000000ff00000000ULL) >>  8) | \
     (((x) & 0x0000ff0000000000ULL) >> 24) | \
     (((x) & 0x00ff000000000000ULL) >> 40) | \
     (((x) & 0xff00000000000000ULL) >> 56))

struct Struct_ov031_02220f0c {
    unsigned char unknown_0_[8];
};

static inline void inline_ov031_02220f0c(const unsigned char* arg0, unsigned char* arg1) {
    unsigned int var0;
    for (var0 = 8; var0 != 0; var0--) {
        *arg1++ = *arg0++;
    }
}

// USA: func_ov031_022210c4  (semantic: AES key unwrap, RFC 3394)
extern "C" THUMB int func_ov031_022210c4(Struct_ov031_02220f0c* arg0, const unsigned char* arg1, unsigned int arg2,
                                          const unsigned char* arg3, unsigned int arg4) {
    unsigned int var0[80];
    Struct_ov031_02220f0c var1[2];
    unsigned long long var2;
    unsigned int var3[2];
    int var4;
    int var5;
    int var6;
    int var7;
    int var8;
    Struct_ov031_02220f0c* var9;
    long long var10;
    long long var11;
    unsigned long long var12;

    var8 = 1;
    var3[0] = 0xa6a6a6a6;
    var3[1] = 0xa6a6a6a6;
    if ((arg2 & 7) || (arg4 & 7)) {
        return 0;
    }
    var4 = (arg2 - 1) >> 3;
    if (var4 < 2) {
        return 0;
    }
    var7 = func_ov031_0222157c(var0, arg3, arg4 * 8);
    inline_ov031_02220f0c(arg1, var1[0].unknown_0_);
    memcpy(arg0, arg1 + 8, arg2 - 1);

    var6 = 5;
    var10 = var4;
    do {
        var5 = var4;
        if (var5 > 0) {
            var11 = func_0200cf24(var10, var6);
            do {
                var12 = var5 + var11;
                var2 = BSWAP64(var12);
                func_ov031_0222127c(var1[0].unknown_0_, (unsigned char*)&var2, var1[0].unknown_0_);
                var9 = arg0 + (var5 - 1);
                var1[1] = *var9;
                func_ov031_02221ac8(var0, var7, var1[0].unknown_0_, var1[0].unknown_0_);
                *var9 = var1[1];
            } while (--var5 > 0);
        }
    } while (--j >= 0);
    if (memcmp(iv, b, 8) != 0) {
        ret = 0;
    }
    return var8;
}
