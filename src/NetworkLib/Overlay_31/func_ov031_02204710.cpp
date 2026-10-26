#include <globaldefs.h>

extern "C" void func_ov031_0220321c(void);
extern "C" void func_ov031_02203190(void);
extern "C" void func_ov031_02203250(void);
extern "C" void func_ov031_022031bc(int a, unsigned short b, unsigned int c);
extern "C" void* func_ov031_02204260(int flag);
extern "C" int func_ov031_02204368(int a, int index);

struct Struct_ov031_0224c980_16 {
	unsigned char pad0[0x20];
	unsigned int field20;
	unsigned char pad20[0x38 - 0x24];
	unsigned int field38;
	unsigned char unknown_3c_[0x4c - 0x3c];
	unsigned int field4c;
};
extern Struct_ov031_0224c980_16 data_ov031_0224c980;

// USA: func_ov031_02204710
extern "C" ARM int func_ov031_02204710(int* out, int mode) {
	func_ov031_0220321c();
	func_ov031_02203190();

	if (mode == 1) {
		func_ov031_022031bc(0x44, 0x43, data_ov031_0224c980.field20);
	} else {
		func_ov031_022031bc(0x44, 0x43, 0x43 - 0x44);
	}

	int result = 0;
	int i = 0;
	do {
		result = func_ov031_02204368((int)func_ov031_02204260(mode), i);
		if (result != 0) break;
		i++;
	} while (i < 4);

	func_ov031_02203250();

	if (result == 2) {
		*out = data_ov031_0224c980.field4c >> 1;
		data_ov031_0224c980.field38 = (data_ov031_0224c980.field4c + (data_ov031_0224c980.field4c << 1)) >> 3;
		return 1;
	}

	unsigned int half = data_ov031_0224c980.field38 >> 1;
	data_ov031_0224c980.field38 = half;
	*out = half;

	switch (mode) {
	case 1:
		if (half < 0x3c) {
			*out = 1;
			data_ov031_0224c980.field38 = data_ov031_0224c980.field4c >> 3;
		}
		break;
	case 2:
		if (half < 0x3c) {
			*out = 1;
		}
		break;
	}

	return 0;
}
