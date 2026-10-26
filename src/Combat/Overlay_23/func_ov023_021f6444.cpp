#include <globaldefs.h>

struct Struct_ov023_021f6444 {
	char pad[0x44];
	unsigned char field;
};

// USA: func_ov023_021f6444
extern "C" ARM void func_ov023_021f6444(struct Struct_ov023_021f6444 *obj, unsigned int v) {
	obj->field = (obj->field & ~0xf0) | ((v & 0xf) << 4);
}
