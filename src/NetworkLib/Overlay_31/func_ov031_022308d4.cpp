#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02235c70(void);
extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_022307fc(void);
extern unsigned char data_ov031_02290ca0;
extern unsigned char data_ov031_0224903c;

// USA: func_ov031_022308d4
extern "C" ARM void func_ov031_022308d4(void) {
	unsigned char v = data_ov031_02290ca0;
	unsigned int t = (v + 0xf5) & 0xff;
	if (t <= 2) {
		func_ov031_022307fc();
		return;
	}
	unsigned char* base = func_ov031_02235c70();
	unsigned short field4 = *(unsigned short*)(&data_ov031_02290ca0 + 4);
	int var4 = FastIntDivide(field4, 0x1d);
	unsigned char field2 = (&data_ov031_02290ca0)[2];
	int sum = field2 + var4;
	switch (sum) {
		case 2:
			if (base[0xf5]) {
				(&data_ov031_02290ca0)[0] = 2;
			} else {
				(&data_ov031_02290ca0)[0] = 3;
			}
			break;
		case 6:
			if (base[0xf6]) {
				(&data_ov031_02290ca0)[0] = 7;
			} else {
				(&data_ov031_02290ca0)[0] = 8;
			}
			break;
		default:
			(&data_ov031_02290ca0)[0] = (&data_ov031_0224903c)[sum];
			break;
	}
	func_ov031_022307fc();
}
