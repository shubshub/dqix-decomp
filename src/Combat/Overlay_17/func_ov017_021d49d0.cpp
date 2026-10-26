#include <globaldefs.h>

struct Struct_ov001_021538d4;
extern "C" void func_ov017_021d4a24(Struct_ov001_021538d4* obj);

struct Struct_ov001_02165828 {
	int f0;
	int f4;
	unsigned char pad1[4];
	int fc;
	int f10;
	int f14;
	int f18;
	unsigned char pad2[4];
	int f20;
	int f24;
	int f28;
	int unknown_2c_;
	unsigned char pad3[8];
	int unknown_38_;
	unsigned char pad4[4];
	int f40;
};

// USA: func_ov017_021d49d0
extern "C" ARM Struct_ov001_02165828* func_ov017_021d49d0(Struct_ov001_02165828* obj) {
	obj->f14 = obj->f10;
	obj->f18 = obj->f10;
	obj->f28 = obj->f24;
	obj->unknown_2c_ = obj->f24;
	obj->unknown_38_ = 0;
	obj->f4 = 0;
	obj->fc = 0;
	obj->f20 = 0;
	obj->f40 = 0;
	obj->f0 = 1;
	func_ov017_021d4a24((Struct_ov001_021538d4*)obj);
	return obj;
}
