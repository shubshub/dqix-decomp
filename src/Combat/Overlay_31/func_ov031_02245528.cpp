#include <globaldefs.h>

struct Struct_02245528 { unsigned char pad[0x34]; unsigned char f34; unsigned char unknown_35_; unsigned char unknown_36_; unsigned char unknown_37_; };

// USA: func_ov031_02245528
extern "C" ARM void func_ov031_02245528(struct Struct_02245528* p, int v) {
	p->f34 = v;
	p->unknown_35_ = 0;
	p->unknown_37_ = 0;
	if (v == 0) {
		p->unknown_36_ = 1;
	}
}
