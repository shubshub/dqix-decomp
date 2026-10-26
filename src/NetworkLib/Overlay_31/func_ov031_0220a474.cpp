#include <globaldefs.h>

struct Struct_ov031_0220a474_2 {
	unsigned char pad0[0x30];
	unsigned char unknown_30_;
	unsigned char unknown_31_;
	unsigned char pad2[0x455 - 0x32];
	unsigned char unknown_455_;
};

struct Struct_ov031_0220a474 {
	unsigned char pad0[0xc];
	Struct_ov031_0220a474_2* inner;
	unsigned char pad1[0x18 - 0x10];
	unsigned short field18;
	int field1c;
};

extern "C" void func_ov031_02209ff0(Struct_ov031_0220a474* obj);
extern "C" int func_ov031_02209b58(Struct_ov031_0220a474* obj);
extern "C" void func_ov031_02208f50(Struct_ov031_0220a474_2* obj);
extern "C" ARM int func_ov031_0220a444(int a);
extern "C" void func_ov031_02209e98(Struct_ov031_0220a474* obj);
extern "C" void func_ov031_0220a184(Struct_ov031_0220a474* obj);
extern "C" ARM void func_ov031_02208ef0(void* ctx);
extern "C" void func_ov031_02207b44(void* obj, int a, int b);

// USA: func_ov031_0220a474
extern "C" ARM int func_ov031_0220a474(Struct_ov031_0220a474* obj) {
	Struct_ov031_0220a474_2* inner = obj->inner;
	func_ov031_02209ff0(obj);
	int state;
	do {
		state = func_ov031_02209b58(obj);
		if (state == 9) return 1;
		if (state == 4) break;
	} while (inner->unknown_31_ == 0);

	if (inner->unknown_31_ != 0) {
		func_ov031_02208f50(inner);
		if (func_ov031_0220a444((int)obj) != 0) return 1;
		func_ov031_02209e98(obj);
	} else {
		func_ov031_0220a184(obj);
		func_ov031_02208ef0(inner);
		if (inner->unknown_30_ != 0) {
			func_ov031_02207b44(inner, obj->field1c, obj->field18);
		}
		func_ov031_02208f50(inner);
		func_ov031_02209e98(obj);
		if (func_ov031_0220a444((int)obj) != 0) return 1;
	}
	inner->unknown_455_ = 8;
	return 0;
}
