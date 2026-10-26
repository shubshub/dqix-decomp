#include <globaldefs.h>

struct Struct_ov031_02215528_2 {
	unsigned int f0;
	unsigned int f4;
	unsigned int f8;
	unsigned int fc;
	unsigned int f10;
	unsigned int f14;
	unsigned int f18;
	unsigned int f1c;
	unsigned int f20;
};

struct Struct_ov031_02215528 {
	unsigned int field0;
	unsigned int field4;
};

extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
extern "C" ARM unsigned int func_ov031_022135ac(unsigned int x);
extern "C" ARM unsigned int func_ov031_022155e8(unsigned char* p);
extern "C" ARM unsigned int func_ov031_0221563c(int n);
extern unsigned char data_ov031_02246028[0x58];

// USA: func_ov031_02215528
extern "C" ARM void func_ov031_02215528(Struct_ov031_02215528* obj, unsigned char* a0, Struct_ov031_02215528_2* out) {
	VectorizedInvertedMemcpy(data_ov031_02246028, out, 0x58);
	out->f4 = obj->field0;
	out->f8 = obj->field4;
	if (a0[0xd0d] >= 6) {
		return;
	}
	a0 += func_ov031_022135ac(a0[0xd0d]) << 8;
	if (a0[0xc0] != 0) {
		out->fc = 0;
		out->f10 = func_ov031_022155e8(a0 + 0xc0);
		out->f14 = func_ov031_0221563c(a0[0xd0]);
		out->f18 = func_ov031_022155e8(a0 + 0xc4);
		out->f1c = func_ov031_022155e8(a0 + 0xc8);
		out->f20 = func_ov031_022155e8(a0 + 0xcc);
	} else {
		out->fc = 1;
		out->f10 = 0;
		out->f14 = 0;
		out->f18 = 0;
		out->f1c = 0;
		out->f20 = 0;
	}
}
