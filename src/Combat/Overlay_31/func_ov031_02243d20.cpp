#include <globaldefs.h>
#include "NitroSDK/Timing.h"

struct Struct_02245528;

extern "C" ARM void func_ov031_02211c38(int a);
extern "C" ARM void func_ov031_02211c50(int idx);
extern "C" void func_ov031_02211ca0(void);
extern "C" void func_ov031_02211e08(void);
extern "C" int func_ov031_02211db0(void);
extern "C" int func_ov031_02211f24(void);
extern "C" void func_ov031_02245528(struct Struct_02245528* p, int v);
extern "C" void func_ov031_022120f8(void);
extern "C" void func_ov031_02245478(void);

struct Struct_ov031_02243d20 {
	unsigned char pad0[0x35];
	unsigned char unknown_35_;
	unsigned char pad1[0x310 - 0x36];
	unsigned char unknown_310_[1];
	unsigned char pad2[0x384 - 0x311];
	int unknown_384_;
	unsigned char pad3[0x3a8 - 0x388];
	unsigned int unknown_3a8_;
	unsigned int unknown_3ac_;
};

// USA: func_ov031_02243d20
extern "C" ARM void func_ov031_02243d20(Struct_ov031_02243d20* obj) {
	switch (obj->unknown_35_) {
	case 0:
		func_ov031_02211c38((int)&obj->unknown_310_);
#if !defined(jpn)
		func_ov031_02211c50(2);
#endif
		func_ov031_02211ca0();
		{
			uint64_t t = GetCurrentTimestamp() + 0xefb5f7;
			obj->unknown_3a8_ = (unsigned int)t;
			obj->unknown_3ac_ = (unsigned int)(t >> 32);
		}
		obj->unknown_35_ = 4;
		break;
	case 4:
		func_ov031_02211e08();
		if (func_ov031_02211db0() != 0) {
			obj->unknown_35_ = 5;
			if (obj->unknown_384_ < 0x3c000) obj->unknown_384_ = 0x3c000;
		} else {
			if (obj->unknown_384_ < 0x3c000) obj->unknown_384_ += 0x333;
		}
		break;
	case 5:
		{
			int v = func_ov031_02211f24();
			switch (v) {
			case 4:
				obj->unknown_35_ = 6;
				break;
			case 7:
			case 8:
				obj->unknown_35_ = 8;
				break;
			}
		}
		break;
	case 6:
		func_ov031_02245528((struct Struct_02245528*)obj, 3);
		break;
	case 7:
		func_ov031_022120f8();
		func_ov031_02245528((struct Struct_02245528*)obj, 0);
		break;
	case 8:
		func_ov031_02245478();
		func_ov031_022120f8();
		break;
	default:
		break;
	}
}
