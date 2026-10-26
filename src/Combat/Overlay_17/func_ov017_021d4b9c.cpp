#include <globaldefs.h>

struct Struct_ov017_021d4b9c { int f0; int f4; int f8; };
struct Struct_ov017_021d4b9c_2 {
	unsigned char pad0[0x28];
	Struct_ov017_021d4b9c* unknown_28_;
	unsigned char pad1[4];
	int unknown_30_;
	int f34;
};

// USA: func_ov017_021d4b9c
extern "C" ARM int func_ov017_021d4b9c(Struct_ov017_021d4b9c_2* obj) {
	obj->unknown_28_--;
	obj->unknown_30_ = obj->unknown_28_->f4;
	obj->f34 = obj->unknown_28_->f8;
	return obj->unknown_28_->f0;
}
