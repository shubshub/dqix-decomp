#include <globaldefs.h>

struct Struct_ov031_02222ddc {
	unsigned char pad[0xc];
	int unknown_c_;
	unsigned char pad2[9];
	unsigned char unknown_19_;
};

struct Struct_ov031_02250ba8 {
	Struct_ov031_02222ddc *ptr;
};

extern Struct_ov031_02250ba8 data_ov031_02250ba8;

extern "C" void func_ov031_0222318c(void*);
extern "C" int func_ov031_0223e2b8(int, void*);

// USA: func_ov031_02222ddc
extern "C" ARM int func_ov031_02222ddc(void) {
	Struct_ov031_02222ddc *p = data_ov031_02250ba8.ptr;
	p->unknown_19_ = 1;
	Struct_ov031_02222ddc *p2 = data_ov031_02250ba8.ptr;
	return func_ov031_0223e2b8(p2->unknown_c_, (void*)func_ov031_0222318c);
}
