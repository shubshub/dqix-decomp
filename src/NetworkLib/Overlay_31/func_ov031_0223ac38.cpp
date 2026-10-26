#include <globaldefs.h>

extern "C" unsigned short func_ov031_0223911c(void);
extern "C" int func_ov031_02239be8(void);
extern "C" int func_ov031_0223a47c(void);
extern "C" int func_ov031_02239130(int a);
extern "C" void func_ov031_022387f4(int a0, int a1);
extern "C" int func_ov031_02238c40(void);
extern "C" void func_ov031_02238ca8(void);
extern "C" void func_ov031_02238da0(void);

struct Struct_ov031_0223ac38 {
	unsigned char pad0[0x64a];
	unsigned short unknown_64a_;
	unsigned char pad1[0x444];
	unsigned char unknown_a90_;
	unsigned char pad2[7];
	int unknown_a98_;
};
extern struct Struct_ov031_0223ac38* data_ov031_02290d20;

// USA: func_ov031_0223ac38
extern "C" ARM void func_ov031_0223ac38(void) {
	switch (func_ov031_0223911c()) {
	case 1: {
		unsigned short v = *(unsigned short*)((char*)data_ov031_02290d20 + 0x600 + 0x4a);
		func_ov031_022387f4((int)((char*)data_ov031_02290d20 + 0x2b4 + 0x800), v);
		break;
	}
	case 2:
		if (func_ov031_02239130(2) != 0) {
			data_ov031_02290d20->unknown_a90_ = 5;
			break;
		}
		if (func_ov031_02239130(3) != 0 || func_ov031_02239130(4) != 0) {
			data_ov031_02290d20->unknown_a90_ = 6;
			break;
		}
		if (data_ov031_02290d20->unknown_a90_ == 5 && func_ov031_02239130(2) == 0) {
			data_ov031_02290d20->unknown_a90_ = 0xd;
		}
		break;
	case 3:
		if (func_ov031_02238c40() != 0) {
			func_ov031_02238ca8();
			break;
		}
		{
			unsigned char v = (unsigned char)(data_ov031_02290d20->unknown_a90_ + 0xfa);
			if (v > 1) break;
		}
		if (func_ov031_02239130(3) != 0) break;
		data_ov031_02290d20->unknown_a90_ = 0x12;
		break;
	case 5:
		data_ov031_02290d20->unknown_a90_ = 7;
		break;
	case 7:
		func_ov031_02238da0();
		data_ov031_02290d20->unknown_a90_ = 1;
		break;
	case 4:
	case 6:
		break;
	case 0:
		switch (func_ov031_02239be8()) {
		case 1:
			func_ov031_0223a47c();
			break;
		case 0:
			data_ov031_02290d20->unknown_a90_ = 0x1f;
			break;
		case 3:
			break;
		default:
			data_ov031_02290d20->unknown_a90_ = 0x1f;
			break;
		}
		break;
	}
}
