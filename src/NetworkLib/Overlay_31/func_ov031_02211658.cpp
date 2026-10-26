#include <globaldefs.h>

extern "C" unsigned int func_ov031_02211720(void *a);

struct Struct_ov031_02211658 {
	char pad[0x20];
	unsigned int field20;
	char pad2[0x18];
	unsigned int field3c;
};

// USA: func_ov031_02211658
extern "C" ARM void func_ov031_02211658(Struct_ov031_02211658 *p) {
	p->field20 &= ~1;
	p->field3c = func_ov031_02211720(p);
}
