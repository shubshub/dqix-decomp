#include <globaldefs.h>

extern "C" void* func_ov031_0220510c(int key);

struct Struct_ov031_02205134 {
	void* a;
	void* b;
	int zero;
	signed char unknown_c_;
	unsigned char unknown_d_;
};

// USA: func_ov031_02205134
extern "C" ARM void* func_ov031_02205134(void* a, void* b, int c) {
	Struct_ov031_02205134* p = (Struct_ov031_02205134*)func_ov031_0220510c(c);
	if (p == NULL) return p;
	p->a = a;
	p->b = b;
	p->zero = 0;
	p->unknown_c_ = *((signed char*)b + 0x73);
	p->unknown_d_ = (unsigned char)c;
	return p;
}
