#include <globaldefs.h>

struct Struct_ov031_02239be8_2 { unsigned char data[0x40]; };
struct Struct_ov031_0223ae1c {
	unsigned char pad0[0x200];
	unsigned short unknown_200_;
	unsigned char pad1[2];
	unsigned int unknown_204_;
	unsigned char pad2[0x440];
	unsigned short unknown_648_;
	unsigned short unknown_64a_;
	unsigned char pad3[0x444];
	unsigned char unknown_a90_;
	unsigned char pad4[0x13];
	struct Struct_ov031_02239be8_2* unknown_aa4_;
};
extern struct Struct_ov031_0223ae1c* data_ov031_02290d20;

extern "C" int func_ov031_02239be8(void);
extern "C" unsigned short func_ov031_0223b30c(void);
extern "C" int func_ov031_0223a0fc(int selection, int first, int second);
extern "C" void func_ov031_0223b0c0(int a, int b, void* src);
extern "C" void func_ov031_0223b228(void);

// USA: func_ov031_0223ae1c
extern "C" ARM void func_ov031_0223ae1c(void) {
	switch (func_ov031_02239be8()) {
	case 1:
		func_ov031_0223a0fc(4, (unsigned short)(data_ov031_02290d20->unknown_648_ + 1), data_ov031_02290d20->unknown_64a_);
		break;
	case 4:
	case 5:
	case 6:
		func_ov031_0223b0c0(0, data_ov031_02290d20->unknown_200_, &data_ov031_02290d20->unknown_aa4_[data_ov031_02290d20->unknown_200_ % 16]);
		func_ov031_0223b228();
		if (data_ov031_02290d20->unknown_a90_ == 0x1b) {
			break;
		}
		if (data_ov031_02290d20->unknown_204_ > 0x1e0) {
			data_ov031_02290d20->unknown_a90_ = 0x1b;
			break;
		}
		if (func_ov031_0223b30c() == 0x10 || func_ov031_0223b30c() == 0x20) {
			func_ov031_0223b30c();
			data_ov031_02290d20->unknown_a90_ = 0xa;
		} else if (func_ov031_0223b30c() == 0x40) {
			data_ov031_02290d20->unknown_a90_ = 0xb;
		} else if (func_ov031_0223b30c() == 0xff) {
			data_ov031_02290d20->unknown_a90_ = 0x1b;
		} else if (func_ov031_0223b30c() == 0x50) {
			data_ov031_02290d20->unknown_a90_ = 0x15;
		} else if (func_ov031_0223b30c() == 0x60) {
			data_ov031_02290d20->unknown_a90_ = 0x18;
		} else if (func_ov031_0223b30c() == 0x70) {
			data_ov031_02290d20->unknown_a90_ = 0x1b;
		} else if (func_ov031_0223b30c() == 0) {
			data_ov031_02290d20->unknown_a90_ = 8;
		} else if (func_ov031_0223b30c() == 0xbd) {
			data_ov031_02290d20->unknown_a90_ = 9;
		} else {
			data_ov031_02290d20->unknown_a90_ = 0x1f;
		}
		break;
	}
}
