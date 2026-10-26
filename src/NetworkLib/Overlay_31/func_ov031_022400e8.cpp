#include <globaldefs.h>

struct Struct_ov031_0223ede0 { int field0; unsigned char pad[0x14]; int field18; int field1c; };

// USA: func_ov031_022400e8
extern "C" ARM int func_ov031_022400e8(Struct_ov031_0223ede0* p, int a, int b) {
	if (p->field0 != 0) {
		return 0;
	}
	p->field1c = a;
	p->field18 = b;
	return 1;
}
