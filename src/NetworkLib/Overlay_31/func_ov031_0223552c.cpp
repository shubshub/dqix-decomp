#include <globaldefs.h>

struct Struct_ov031_0223552c {
	unsigned char pad0[0x12];
	unsigned short field12;
	unsigned char pad1[0x19 - 0x14];
	unsigned char unknown_19_;
	unsigned char pad2[0x1b - 0x1a];
	unsigned char unknown_1b_;
	unsigned char pad3[0x1d - 0x1c];
	unsigned char unknown_1d_;
};
extern Struct_ov031_0223552c* data_ov031_02290cf4;
extern unsigned char data_ov031_022491f4[];

struct Struct_ov031_0223552c_2 { unsigned short a; unsigned short b; };
extern "C" int func_ov031_0223d69c(void*);
extern "C" ARM void func_ov031_02235744(int);

// USA: func_ov031_0223552c
extern "C" ARM void func_ov031_0223552c(void) {
	struct Struct_ov031_0223552c_2 buf;
	func_ov031_0223d69c(&buf);
	Struct_ov031_0223552c* ctx = data_ov031_02290cf4;
	unsigned int t = data_ov031_022491f4[ctx->unknown_1b_];
	int v = buf.b - ctx->field12;
	v -= t >> 1;
	if (v < 0) {
		v = 0;
	} else {
		int var4 = ctx->unknown_19_ - t;
		if (v >= var4) v = var4;
	}
	func_ov031_02235744(v);
	data_ov031_02290cf4->unknown_1d_ = 3;
}
