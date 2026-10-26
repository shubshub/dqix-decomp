#include <globaldefs.h>

extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_022350bc(int a, int b, int c, int d, int e);

struct Struct_ov031_0222b870 {
	unsigned char pad[0x40];
	unsigned short field40;
	unsigned char pad2[0x51 - 0x42];
	unsigned char unknown_51_;
	unsigned char pad3[1];
	unsigned char unknown_53_;
};
struct Struct_ov031_02290c8c_3 {
	unsigned char pad[2];
	unsigned short field2;
	Struct_ov031_0222b870* field4;
};
extern Struct_ov031_02290c8c_3 data_ov031_02290c8c;

// USA: func_ov031_0222b870
extern "C" ARM void func_ov031_0222b870(void) {
	int var0 = 0;
	Struct_ov031_0222b870* obj = data_ov031_02290c8c.field4;
	obj->field40 = (obj->unknown_51_ - 4) * 0x1c;

	obj = data_ov031_02290c8c.field4;
	unsigned char v = obj->unknown_51_;
	int flag;
	if (v <= 4) {
		obj->unknown_53_ = 0;
		flag = 0;
	} else if (v <= 8) {
		obj->unknown_53_ = 0x1f;
		flag = 1;
	} else {
		obj->unknown_53_ = 0x37;
		flag = 2;
	}

	if (flag != 0) {
		obj = data_ov031_02290c8c.field4;
		unsigned short cnt = data_ov031_02290c8c.field2;
		unsigned char sz = obj->unknown_53_;
		unsigned short f40 = obj->field40;
		var0 = FastIntDivide(cnt * sz, f40);
	}
	func_ov031_022350bc(flag, 0x55, 0xec, 0x3f, var0);
}
