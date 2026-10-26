#include <globaldefs.h>

struct Struct_ov023_021f650c {
	char pad[0x3a];
	unsigned char field;
};

// USA: func_ov023_021f650c
extern "C" ARM void func_ov023_021f650c(struct Struct_ov023_021f650c *obj, unsigned int v) {
	obj->field = (obj->field & ~0xf0) | ((v & 0xf) << 4);
}
