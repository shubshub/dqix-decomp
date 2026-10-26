#include <globaldefs.h>

extern "C" int FastIntDivide(int arg0, unsigned int arg1);

struct Struct_ov031_02290ca0_16 {
	unsigned char unk0;
	unsigned char unknown_1_;
	unsigned char unk2;
	unsigned char unknown_3_;
	unsigned short field4;
};
extern struct Struct_ov031_02290ca0_16 data_ov031_02290ca0;

// USA: func_ov031_022305a4
extern "C" ARM int func_ov031_022305a4(int a) {
	int var0 = FastIntDivide(data_ov031_02290ca0.field4, 0x1d);
	int i = 0;
	do {
		if (var0 == a) return i;
		i++;
		var0++;
	} while (i < 4);
	return -1;
}
