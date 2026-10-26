#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_02236878(int a);
extern "C" void func_ov031_0222cb5c(void);
extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_0223521c(void);
extern "C" void func_ov031_02222e98(void);
extern "C" void func_ov031_02237b2c(int a, int b, int c, int d, int e);
extern "C" void func_ov031_022274c0(int fn);
extern "C" void func_ov031_0222cb8c(void);
extern "C" void func_ov031_0222c128(void);

struct Struct_ov031_0222c01c {
	char* entries;
	char pad4[0x38 - 4];
	int field38;
	char unknown_3c_[0x52 - 0x3c];
	unsigned char unknown_52_;
	unsigned char unknown_53_;
	unsigned char field54;
	char pad55[0x57 - 0x55];
	unsigned char unknown_57_;
};

struct Struct_ov031_02290c8c_7 {
	unsigned char field0;
	unsigned char pad1;
	unsigned short field2;
	Struct_ov031_0222c01c* field4;
};

extern Struct_ov031_02290c8c_7 data_ov031_02290c8c;

// USA: func_ov031_0222c01c
extern "C" ARM void func_ov031_0222c01c(void) {
	if (data_ov031_02290c8c.field4->field38 != 0 || data_ov031_02290c8c.field4->unknown_57_ != 0) return;

	int r = func_ov031_02222e0c();
	switch (r) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1:
		if (data_ov031_02290c8c.field0 == 4) {
			data_ov031_02290c8c.field4->field54 = 1;
			func_ov031_02236878(6);
			func_ov031_0222cb5c();
			break;
		}
		{
			int d = FastIntDivide(data_ov031_02290c8c.field2, 0x1c);
			int idx = data_ov031_02290c8c.field0 + d;
			Struct_ov031_0222c01c* mgr = data_ov031_02290c8c.field4;
			unsigned char* entry = (unsigned char*)(mgr->entries + idx * 0x2a);
			if (entry[0x28] == 2) {
				func_ov031_02236878(9);
				func_ov031_0223521c();
				func_ov031_02222e98();
				func_ov031_02237b2c(0xe, 1, 1, -1, 0);
				func_ov031_022274c0((int)func_ov031_0222cb8c);
				return;
			}
			mgr->field54 = 1;
			data_ov031_02290c8c.field4->unknown_52_ = (unsigned char)idx;
			func_ov031_02236878(6);
		}
		break;
	default:
		return;
	}
	func_ov031_022274c0((int)func_ov031_0222c128);
}
