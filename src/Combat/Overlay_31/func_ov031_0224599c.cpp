#include <globaldefs.h>
#include "std_library_functions.h"


void SleepCurrentContext(unsigned int ticks);
extern "C" int func_ov031_0220d540(void);
extern "C" void* func_ov031_0220ec04(int arg0);
extern "C" int func_ov031_0220ca88(void);
extern "C" int func_ov031_0220c970(void* arg0, unsigned int arg1);
extern "C" int func_ov031_02245c68(int arg0);
extern "C" void func_ov031_0220eadc(void);
extern "C" int func_ov031_0220eb88(int arg0);
extern "C" int func_ov031_0220eb30(void);
extern "C" int func_020c7ea0(void* queue, int* msg, int flags);
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" void func_020ca4b4(const void* src, void* dest, int count);

struct Struct_ov031_0224599c {
	int unknown_0_;
	void* unknown_4_;
	unsigned int unknown_8_;
	int unknown_c_;
};

struct Struct_ov031_02291f24_3 {
	unsigned char unknown_0_;
	int unknown_4_;
	int unknown_8_;
	int unknown_c_;
	int unknown_10_;
	void* unknown_14_;
	char unknown_18_[0x14];
	struct Struct_ov031_0224599c unknown_2c_;
};

struct Struct_ov031_02292040 {
	unsigned short unknown_0_;
	char unknown_2_[0xbe];
};

extern struct Struct_ov031_02291f24_3 data_ov031_02291f24;
extern struct Struct_ov031_02292040 data_ov031_02292040;
extern int data_ov031_02291f60;

static inline void CpuClear8(void* dest, int count) {
	MIi_CpuClearFast(0, dest, count);
}

static inline void inline_ov031_0224599c_2(const void* arg0, void* arg1, int arg2) {
	func_020ca4b4(arg0, arg1, arg2);
}

enum Enum_ov031_0224599c { Enum_ov031_0224599c_1 = 1, Enum_ov031_0224599c_4 = 4, Enum_ov031_0224599c_5 = 5 };

// USA: func_ov031_0224599c
extern "C" ARM void func_ov031_0224599c(void) {
	void* var0 = data_ov031_02291f24.unknown_14_;
	unsigned int var1;
	char* var2;
	int var3;

	if (var0 == NULL) {
		return;
	}
	if (data_ov031_02291f24.unknown_0_ != 0) {
		var1 = data_ov031_02291f24.unknown_0_ * 0xd0 + 0xc;
	} else {
		var1 = 0x11ec;
	}
	memset(var0, 0, var1 + 0x2300);
	if (var0 == NULL) {
		return;
	}
	var2 = (char*)var0 + 0x2300;
	if (func_ov031_0220c970(var0, 0x2300) != 0) {
		return;
	}
	data_ov031_02291f24.unknown_2c_.unknown_0_ = 2;
	data_ov031_02291f24.unknown_2c_.unknown_4_ = var2;
	data_ov031_02291f24.unknown_2c_.unknown_8_ = var1;
	data_ov031_02291f24.unknown_2c_.unknown_c_ = 0;

	while (data_ov031_02291f24.unknown_4_ == 0) {
		switch (func_ov031_0220d540()) {
		case 1:
			func_ov031_02245c68(1);
			break;
		case 3:
			if (data_ov031_02292040.unknown_0_ == 0) {
				func_ov031_0220eadc();
				func_ov031_02245c68(3);
			} else if (func_ov031_02245c68(5) == 0) {
				inline_ov031_0224599c(&data_ov031_02292040, 0xc0);
			}
			break;
		case 6:
			func_020c7ea0(&data_ov031_02291f60, &var3, 1);
			{
				Enum_ov031_0224599c var4 = Enum_ov031_0224599c_1;
				Enum_ov031_0224599c var5 = Enum_ov031_0224599c_4;
				if (var3 == var4) {
					if (data_ov031_02291f24.unknown_c_ == 0) {
						func_ov031_0220eb88(1);
						if (func_ov031_0220eb30() >= 1) {
							inline_ov031_0224599c_2(func_ov031_0220ec04(0), &data_ov031_02292040, 0xc0);
						}
						func_ov031_0220eb88(0);
						func_ov031_02245c68(4);
					}
				} else if (var3 == var5) {
					func_ov031_02245c68(4);
				}
			}
			break;
		case 9:
			func_020c7ea0(&data_ov031_02291f60, &var3, 1);
			{
				Enum_ov031_0224599c var6 = Enum_ov031_0224599c_5;
				if (var3 == var6) {
					func_ov031_02245c68(6);
				}
			}
			break;
		case 12:
			SleepCurrentContext(1);
			func_ov031_02245c68(9);
			break;
		default:
			for (;;) {
				SleepCurrentContext(10000);
			}
		}
	}

	while (data_ov031_02291f24.unknown_4_ != 0) {
		switch (func_ov031_0220d540()) {
		case 1:
			data_ov031_02291f24.unknown_4_ = 0;
			break;
		case 3:
			func_ov031_02245c68(2);
			break;
		case 6:
			func_ov031_02245c68(4);
			break;
		case 9:
			func_ov031_02245c68(6);
			break;
		case 12:
			func_ov031_02245c68(9);
			break;
		default:
			for (;;) {
				SleepCurrentContext(10000);
			}
		}
	}

	if (func_ov031_0220ca88() == 0) {
		return;
	}
}
