#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern "C" int func_ov027_021daa34(int idx, int addr, int len);
extern void *data_ov027_021e33ec;

struct Struct_ov027_021da808 {
	int unknown_0_[3];
	unsigned short unknown_c_[3];
	unsigned short count;
};

struct Struct_ov027_021da808_2 {
	int f0;
	int f4;
	int f8;
	int pad12;
};

// USA: func_ov027_021da808
extern "C" ARM int func_ov027_021da808(Struct_ov027_021da808 *out, void *arg1) {
	Struct_ov027_021da808_2 *var0;
	unsigned short *var1 = (unsigned short *)((char *)out + 0xc);
	int sum = 0;
	if (arg1 == NULL) {
		return 0;
	}
	unsigned char i = 0;
	do {
		out->unknown_0_[i] = sum;
		sum += *(int *)((char *)arg1 + i * 0x10 + 0x14);
		i++;
	} while (i < 3);
	var1[0] = 0;
	var0 = (Struct_ov027_021da808_2 *)((char *)arg1 + 0xc);
	Struct_ov027_021da808_2 *var4;
	int f8;
	unsigned char j = 0;
	do {
		var4 = &var0[j];
		int limit = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
		f8 = var4->f8;
		unsigned int var8 = _u32_div_f(f8 + limit - 1, limit);
		unsigned short var9 = (unsigned short)(var1[j] + (unsigned short)var8);
		int f4 = var4->f4;
		if (!func_ov027_021daa34(j, f4, f8)) {
			return 0;
		}
		if (j < 2) {
			unsigned short *var11 = var1 + j;
			var11[1] = var9;
		} else {
			out->count = var9;
		}
		j++;
	} while (j < 3);
	return 1;
}
