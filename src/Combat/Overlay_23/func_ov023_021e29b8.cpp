#include <globaldefs.h>

struct Struct_ov023_021e29b8 {
	char pad[2];
	unsigned char byteField;
};

extern "C" struct Struct_ov023_021e29b8 *func_ov023_021e2418(void *a, int b);

// USA: func_ov023_021e29b8
extern "C" ARM void func_ov023_021e29b8(void *a, int b, unsigned char v) {
	struct Struct_ov023_021e29b8 *e = func_ov023_021e2418(a, b);
	if (e != NULL) {
		e->byteField = v;
	}
}
