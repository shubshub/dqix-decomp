#include <globaldefs.h>

struct Struct_ov031_0223566c {
	unsigned char pad0[0x10];
	unsigned short field10;
	unsigned short field12;
	unsigned char unknown_14_[0x19 - 0x14];
	unsigned char unknown_19_;
	unsigned char unknown_1a_;
	unsigned char unknown_1b_;
};
extern Struct_ov031_0223566c* data_ov031_02290cf4;
extern unsigned char data_ov031_022491f4[];

struct Struct_ov031_0223566c_2 { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short unknown_6_; };

// USA: func_ov031_0223566c
extern "C" ARM void func_ov031_0223566c(int idx, Struct_ov031_0223566c_2* out) {
	unsigned short v10 = data_ov031_02290cf4->field10;
	out->f0 = v10;
	out->f4 = v10 + 0xc;
	switch (idx) {
	case 0:
		break;
	case 1:
		out->f2 = data_ov031_02290cf4->field12 + data_ov031_02290cf4->unknown_1a_;
		out->unknown_6_ = out->f2 + data_ov031_022491f4[data_ov031_02290cf4->unknown_1b_];
		break;
	case 2:
		out->f2 = data_ov031_02290cf4->field12 - 0xd;
		out->unknown_6_ = data_ov031_02290cf4->field12;
		break;
	case 3:
		out->f2 = data_ov031_02290cf4->field12 + data_ov031_02290cf4->unknown_19_;
		out->unknown_6_ = out->f2 + 0xd;
		break;
	case 4:
		out->f2 = data_ov031_02290cf4->field12;
		out->unknown_6_ = out->f2 + data_ov031_02290cf4->unknown_19_;
		break;
	}
}
