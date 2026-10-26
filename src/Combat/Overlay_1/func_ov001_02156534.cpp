#include <globaldefs.h>

struct Struct_ov001_02156534 {
	unsigned char pad0[1];
	unsigned char unknown_1_;
	unsigned char pad2[8];
	unsigned short unknown_a_;
};

extern "C" void func_ov001_02154da0(struct Struct_ov001_02156534* p);
extern "C" void func_ov017_021bb27c(struct Struct_ov001_02156534* p);

// USA: func_ov001_02156534
extern "C" ARM unsigned short func_ov001_02156534(struct Struct_ov001_02156534* p) {
	func_ov001_02154da0(p);
	func_ov017_021bb27c(p);
	p->unknown_1_ = 1;
	return p->unknown_a_;
}
