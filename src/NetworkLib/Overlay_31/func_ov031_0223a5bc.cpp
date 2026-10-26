#include <globaldefs.h>

extern unsigned char* data_ov031_02290d20;
extern "C" void func_ov027_021dcd20(void);

// USA: func_ov031_0223a5bc
extern "C" ARM int func_ov031_0223a5bc(void) {
	unsigned char v = data_ov031_02290d20[0xa90];
	if (v == 1 || v == 0x14 || v == 0x17 || v == 0x1a || v == 0x1d) {
		data_ov031_02290d20[0xa90] = 0x22;
		data_ov031_02290d20[0xaac] = 0;
		return 1;
	}
	if (v == 4 || v == 5 || v == 6 || v == 0xd) {
		if (v == 4) {
			unsigned int var1 = *(unsigned int*)(data_ov031_02290d20 + 0xa98);
			if (var1 < 6) return 0;
		}
		func_ov027_021dcd20();
		data_ov031_02290d20[0xa90] = 0x10;
		data_ov031_02290d20[0xaac] = 2;
		return 1;
	}
	if (v == 9 || v == 0xa) {
		data_ov031_02290d20[0xa90] = 0x20;
		return 1;
	}
	if (v == 0xc) {
		data_ov031_02290d20[0xa90] = 0x22;
		return 1;
	}
	return 0;
}
