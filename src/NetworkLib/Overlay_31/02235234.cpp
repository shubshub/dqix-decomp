#include <globaldefs.h>

struct Struct_ov031_02235234 {
	unsigned char pad[0x14];
	unsigned short unknown_14_;
	unsigned short unknown_16_;
	unsigned char field18;
	unsigned char unknown_19_;
	unsigned char unknown_1a_;
	unsigned char unknown_1b_;
	unsigned char field1c;
	unsigned char unknown_1d_;
	unsigned char unknown_1e_;
};

extern Struct_ov031_02235234* data_ov031_02290cf4;

extern "C" ARM int func_ov031_02235594(void);
extern "C" ARM void func_ov031_0223552c(void);
extern "C" ARM void func_ov031_022353b8(void);
extern "C" ARM int func_ov031_02235620(int);
extern "C" ARM int func_ov031_02236878(int);
extern "C" ARM void func_ov031_0223689c(unsigned char);
extern "C" ARM int func_ov031_0223d69c(void*);
extern "C" void func_ov031_02235500(int a);

// USA: func_ov031_02235234
extern "C" ARM void func_ov031_02235234(void) {
	data_ov031_02290cf4->unknown_1d_ = 0;
	switch (data_ov031_02290cf4->field1c) {
	case 0:
		if (data_ov031_02290cf4->unknown_1e_ != 0) {
			break;
		}
		switch (func_ov031_02235594()) {
		case 1:
			if (data_ov031_02290cf4->unknown_1b_ != 0) {
				func_ov031_02236878(0x16);
				func_ov031_0223689c(0);
				data_ov031_02290cf4->unknown_1d_ = 1;
				func_ov031_0223d69c(&data_ov031_02290cf4->unknown_14_);
				data_ov031_02290cf4->field18 = data_ov031_02290cf4->unknown_1a_;
				data_ov031_02290cf4->field1c = 1;
			}
			break;
		case 2:
			func_ov031_02235500(2);
			break;
		case 3:
			func_ov031_02235500(3);
			break;
		case 4:
			func_ov031_0223552c();
			break;
		}
		break;
	case 1:
		func_ov031_022353b8();
		break;
	case 2:
		if (func_ov031_02235620(2) != 2) {
			data_ov031_02290cf4->unknown_1d_ = 5;
			data_ov031_02290cf4->field1c = 0;
		} else if (func_ov031_02235594() == 2) {
			func_ov031_02235500(2);
		}
		break;
	case 3:
		if (func_ov031_02235620(3) != 3) {
			data_ov031_02290cf4->unknown_1d_ = 7;
			data_ov031_02290cf4->field1c = 0;
		} else if (func_ov031_02235594() == 3) {
			func_ov031_02235500(3);
		}
		break;
	}
}
