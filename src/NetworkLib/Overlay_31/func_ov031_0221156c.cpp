#include <globaldefs.h>

extern "C" ARM int func_ov031_022115a4(int *obj);
extern "C" unsigned int func_ov031_02211720(void *a);

struct Struct_ov031_0221156c {
	char pad[0x3c];
	unsigned int field3c;
};

// USA: func_ov031_0221156c
extern "C" ARM int func_ov031_0221156c(Struct_ov031_0221156c *p) {
	if (!func_ov031_022115a4((int*)p)) return 0;
	return p->field3c == func_ov031_02211720(p);
}
