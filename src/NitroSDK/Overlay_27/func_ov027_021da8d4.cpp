#include <globaldefs.h>

extern void *data_ov027_021e33ec;

struct Struct_ov027_021da8d4_3 {
	int unknown_0_[3];
	unsigned short unknown_c_[3];
	unsigned short count;
};

struct Struct_ov027_021da8d4 {
	int f0;
	int pad4;
	int f8;
	int pad12;
};

struct Struct_ov027_021da8d4_2 {
	int f0;
	int f4;
	int f8;
	unsigned char fc;
};

// USA: func_ov027_021da8d4
extern "C" ARM int func_ov027_021da8d4(Struct_ov027_021da8d4_2 *out, Struct_ov027_021da8d4_3 *table, unsigned int key, void *arg3) {
	if (key >= table->count) {
		return 0;
	}
	signed char idx = 2;
	for (;;) {
		if (key >= table->unknown_c_[idx]) break;
		idx = idx - 1;
		if (idx < 0) break;
	}
	if (idx < 0) {
		return 0;
	}
	int limit = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
	int diff = key - table->unknown_c_[idx];
	int var3 = diff * limit;
	Struct_ov027_021da8d4 *var4 = (Struct_ov027_021da8d4 *)((char *)arg3 + 0xc);
	Struct_ov027_021da8d4 *e = var4 + idx;
	int f4 = e->f8 - var3;
	out->f4 = f4;
	int var7 = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
	if ((unsigned int)f4 > (unsigned int)var7) {
		out->f4 = var7;
	}
	out->f8 = var3 + table->unknown_0_[idx];
	out->f0 = var3 + e->f0;
	out->fc = (unsigned char)idx;
	return 1;
}
