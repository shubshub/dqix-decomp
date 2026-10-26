#include <globaldefs.h>

struct Struct_ov015_02190020 {
	char unknown_0_[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	int* unknown_24_;
	char pad2c[0x2c - 0x28];
	unsigned char unknown_2c_;
	char unknown_2d_[0x3c - 0x2d];
	unsigned char field3c;
};

// USA: func_ov015_02190020
extern "C" ARM void func_ov015_02190020(struct Struct_ov015_02190020* obj, unsigned char val) {
	char* p;
	if (obj->state != 0 && obj->state != 1) {
		return;
	}
	if (obj->field3c == val) {
		return;
	}
	p = (char*)obj->unknown_24_ + 0x200;
	*(short*)(p + 0xb2) = -1;
	obj->field3c = val;
	obj->unknown_2c_ = 1;
}
