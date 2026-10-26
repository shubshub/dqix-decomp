#include <globaldefs.h>

extern "C" long long func_0200cf24(long long a, long long b);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" int memcmp(const void* a, const void* b, int n);
extern "C" int func_ov031_0222157c(unsigned int* arg0, const unsigned char* arg1, int arg2);
extern "C" void func_ov031_0222127c(const unsigned char* a, const unsigned char* b, unsigned char* out);
extern "C" void func_ov031_02221ac8(const unsigned int* arg0, int arg1, const unsigned char* arg2, unsigned char* pt);

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
    unsigned char v[8];
};

static inline void inline_ov031_02220f0c(const unsigned char* src, unsigned char* dst) {
    unsigned int k;
    for (k = 8; k != 0; k--) {
        *dst++ = *src++;
    }
}

// USA: func_ov031_022210c4  (semantic: AES key unwrap, RFC 3394)
extern "C" THUMB int func_ov031_022210c4(Struct_ov031_02220f0c* arg0, const unsigned char* arg1, unsigned int len,
                                          const unsigned char* arg3, unsigned int arg4) {
    unsigned int var0[80];
    Struct_ov031_02220f0c b[2];
    unsigned long long tb;
    unsigned int iv[2];
    int n;
    int i;
    int j;
    int var7;
    int ret;
    Struct_ov031_02220f0c* r;
    long long nn;
    long long var11;
    unsigned long long t;

    ret = 1;
    iv[0] = 0xa6a6a6a6;
    iv[1] = 0xa6a6a6a6;
    if ((len & 7) || (arg4 & 7)) {
        return 0;
    }
    n = (len - 1) >> 3;
    if (n < 2) {
        return 0;
    }
    var7 = func_ov031_0222157c(var0, arg3, arg4 * 8);
    inline_ov031_02220f0c(arg1, b[0].v);
    memcpy(arg0, arg1 + 8, len - 1);

    j = 5;
    nn = n;
    do {
        i = n;
        if (i > 0) {
            var11 = func_0200cf24(nn, j);
            do {
                t = i + var11;
                tb = BSWAP64(t);
                func_ov031_0222127c(b[0].v, (unsigned char*)&tb, b[0].v);
                r = arg0 + (i - 1);
                b[1] = *r;
                func_ov031_02221ac8(var0, var7, b[0].v, b[0].v);
                *r = b[1];
            } while (--i > 0);
        }
    } while (--j >= 0);
    if (memcmp(iv, b, 8) != 0) {
        ret = 0;
    }
    return ret;
}
