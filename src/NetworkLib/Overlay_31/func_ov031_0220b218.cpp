#include <globaldefs.h>

extern "C" void func_ov031_0220b1d0(unsigned int* dst, const void* src, unsigned int len);
extern "C" ARM unsigned int func_ov031_0220b148(unsigned int t, unsigned int* w);

#define ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define F1(b, c, d) ((d) ^ ((b) & ((c) ^ (d))))
#define F2(b, c, d) ((d) ^ ((b) ^ (c)))
#define F3(b, c, d) (((b) & ((c) | (d))) | ((c) & (d)))

#define R(f, k, a, b, c, d, e, x) \
    e += ROL(a, 5) + f(b, c, d) + (x) + k; \
    b = ROL(b, 30);

// USA: func_ov031_0220b218
extern "C" ARM void func_ov031_0220b218(unsigned int* state, const void* block) {
    unsigned int w[16];
    unsigned int a = state[0];
    unsigned int b = state[1];
    unsigned int c = state[2];
    unsigned int d = state[3];
    unsigned int e = state[4];
    int i;
    int j;

    func_ov031_0220b1d0(w, block, 0x40);

    i = 0;
    for (j = 0; j < 3; j++) {
        R(F1, 0x5a827999, a, b, c, d, e, w[i]);
        R(F1, 0x5a827999, e, a, b, c, d, w[i + 1]);
        R(F1, 0x5a827999, d, e, a, b, c, w[i + 2]);
        R(F1, 0x5a827999, c, d, e, a, b, w[i + 3]);
        R(F1, 0x5a827999, b, c, d, e, a, w[i + 4]);
        i += 5;
    }
    R(F1, 0x5a827999, a, b, c, d, e, w[15]);
    R(F1, 0x5a827999, e, a, b, c, d, func_ov031_0220b148(0, w));
    R(F1, 0x5a827999, d, e, a, b, c, func_ov031_0220b148(1, w));
    R(F1, 0x5a827999, c, d, e, a, b, func_ov031_0220b148(2, w));
    R(F1, 0x5a827999, b, c, d, e, a, func_ov031_0220b148(3, w));

    i = 4;
    for (j = 0; j < 4; j++) {
        R(F2, 0x6ed9eba1, a, b, c, d, e, func_ov031_0220b148(i, w));
        R(F2, 0x6ed9eba1, e, a, b, c, d, func_ov031_0220b148(i + 1, w));
        i = (i + 2) & 0xf;
        R(F2, 0x6ed9eba1, d, e, a, b, c, func_ov031_0220b148(i, w));
        R(F2, 0x6ed9eba1, c, d, e, a, b, func_ov031_0220b148(i + 1, w));
        R(F2, 0x6ed9eba1, b, c, d, e, a, func_ov031_0220b148(i + 2, w));
        i += 3;
    }
    for (j = 0; j < 4; j++) {
        R(F3, 0x8f1bbcdc, a, b, c, d, e, func_ov031_0220b148(i, w));
        R(F3, 0x8f1bbcdc, e, a, b, c, d, func_ov031_0220b148(i + 1, w));
        R(F3, 0x8f1bbcdc, d, e, a, b, c, func_ov031_0220b148(i + 2, w));
        i = (i + 3) & 0xf;
        R(F3, 0x8f1bbcdc, c, d, e, a, b, func_ov031_0220b148(i, w));
        R(F3, 0x8f1bbcdc, b, c, d, e, a, func_ov031_0220b148(i + 1, w));
        i += 2;
    }
    for (j = 0; j < 4; j++) {
        R(F2, 0xca62c1d6, a, b, c, d, e, func_ov031_0220b148(i, w));
        R(F2, 0xca62c1d6, e, a, b, c, d, func_ov031_0220b148(i + 1, w));
        R(F2, 0xca62c1d6, d, e, a, b, c, func_ov031_0220b148(i + 2, w));
        R(F2, 0xca62c1d6, c, d, e, a, b, func_ov031_0220b148(i + 3, w));
        i = (i + 4) & 0xf;
        R(F2, 0xca62c1d6, b, c, d, e, a, func_ov031_0220b148(i, w));
        i++;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}
