#include <globaldefs.h>

struct Struct_ov031_0220abc4 {
	unsigned int state[4];
};

extern "C" ARM void func_ov031_0220abac(void* dst, const void* src, unsigned int length);

extern unsigned char data_ov031_02249764[];
extern unsigned int data_ov031_022497e4[];

#define MD5_F(x, y, z) ((z) ^ ((x) & ((y) ^ (z))))
#define MD5_G(x, y, z) ((y) ^ ((z) & ((x) ^ (y))))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | ~(z)))
#define MD5_ROTL(v, s) (((v) << (s)) | ((v) >> (32 - (s))))
#define MD5_STEP(f, a, b, c, d, j, s) \
	a += f(b, c, d) + x[data_ov031_02249764[n + (j)]] + data_ov031_022497e4[n + (j)]; \
	a = b + MD5_ROTL(a, s)

// USA: func_ov031_0220abc4
extern "C" ARM void func_ov031_0220abc4(Struct_ov031_0220abc4* ctx, const void* block) {
	unsigned int a = ctx->state[0];
	unsigned int b = ctx->state[1];
	unsigned int c = ctx->state[2];
	unsigned int d = ctx->state[3];
	unsigned int x[16];
	int n;
	int i;

	func_ov031_0220abac(x, block, 0x40);
	n = 0;

	i = 0;
	do {
		MD5_STEP(MD5_F, a, b, c, d, 0, 7);
		MD5_STEP(MD5_F, d, a, b, c, 1, 12);
		MD5_STEP(MD5_F, c, d, a, b, 2, 17);
		MD5_STEP(MD5_F, b, c, d, a, 3, 22);
		n += 4;
		i++;
	} while (i < 4);

	i = 0;
	do {
		MD5_STEP(MD5_G, a, b, c, d, 0, 5);
		MD5_STEP(MD5_G, d, a, b, c, 1, 9);
		MD5_STEP(MD5_G, c, d, a, b, 2, 14);
		MD5_STEP(MD5_G, b, c, d, a, 3, 20);
		n += 4;
		i++;
	} while (i < 4);

	i = 0;
	do {
		MD5_STEP(MD5_H, a, b, c, d, 0, 4);
		MD5_STEP(MD5_H, d, a, b, c, 1, 11);
		MD5_STEP(MD5_H, c, d, a, b, 2, 16);
		MD5_STEP(MD5_H, b, c, d, a, 3, 23);
		n += 4;
		i++;
	} while (i < 4);

	i = 0;
	do {
		MD5_STEP(MD5_I, a, b, c, d, 0, 6);
		MD5_STEP(MD5_I, d, a, b, c, 1, 10);
		MD5_STEP(MD5_I, c, d, a, b, 2, 15);
		MD5_STEP(MD5_I, b, c, d, a, 3, 21);
		n += 4;
		i++;
	} while (i < 4);

	ctx->state[0] += a;
	ctx->state[1] += b;
	ctx->state[2] += c;
	ctx->state[3] += d;
}
