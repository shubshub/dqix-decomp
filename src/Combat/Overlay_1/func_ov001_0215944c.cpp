#include <globaldefs.h>

extern "C" void func_ov001_021579ac(void* a);
extern "C" void func_ov001_02157ae0(void* a, void* b, void* c);

struct Struct_ov001_02157acc {
	unsigned char pad0[0xc4];
	int unknown_c4_;
	unsigned char pad1[0x464 - 0xc8];
	int unknown_464_;
};
extern "C" void func_ov001_02157acc(struct Struct_ov001_02157acc* s);

struct Struct_ov001_0215944c {
	unsigned char pad0[0x48];
	int unknown_48_;
	unsigned char pad1[0x74 - 0x4c];
	int unknown_74_;
	unsigned char pad2[0x84 - 0x78];
	int f84;
	unsigned char pad3[0x11c - 0x88];
	unsigned char unknown_11c_[1];
	unsigned char pad4[0x580 - 0x11d];
	int unknown_580_;
};

// USA: func_ov001_0215944c
extern "C" ARM int func_ov001_0215944c(void* unused, struct Struct_ov001_0215944c* obj) {
	if (obj->unknown_48_ <= 0) {
		func_ov001_021579ac(&obj->unknown_11c_);
		func_ov001_02157acc((struct Struct_ov001_02157acc*)&obj->unknown_11c_);
		obj->unknown_48_ = 1;
	}
	func_ov001_02157ae0(&obj->unknown_11c_, &obj->unknown_74_, &obj->f84);
	int x = (obj->unknown_580_ == 0) ? 1 : 0;
	if (x) {
		x = 0;
		obj->unknown_48_ = x;
	} else {
		x = 1;
	}
	return x;
}
