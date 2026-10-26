#include <globaldefs.h>

struct Struct_ov005_02154d7c {
	char pad0[8];
	int f8;
	int fc;
	int f10;
	int f14;
	char pad1[0x18];
	int unknown_30_;
	int f34;
};

// USA: func_ov005_02154d7c
extern "C" ARM void func_ov005_02154d7c(Struct_ov005_02154d7c* obj, int a, int b) {
	obj->unknown_30_ = obj->fc + (a - obj->f8);
	obj->f34 = obj->f14 + (b - obj->f10);
}
