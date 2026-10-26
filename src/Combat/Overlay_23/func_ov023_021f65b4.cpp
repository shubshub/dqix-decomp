#include <globaldefs.h>

struct Struct_ov023_021f65b4 { char pad[0x5c]; unsigned short unknown_5c_; unsigned short unknown_5e_; };

extern "C" struct Struct_ov023_021f65b4* func_ov023_021f6524(void* a, void* b);

// USA: func_ov023_021f65b4
extern "C" ARM void func_ov023_021f65b4(void* a, void* b, short v1, short v2) {
	struct Struct_ov023_021f65b4* p = func_ov023_021f6524(a, b);
	if (p != 0) {
		p->unknown_5c_ = v1;
		p->unknown_5e_ = v2;
	}
}
