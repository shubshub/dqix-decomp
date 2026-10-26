#include <globaldefs.h>

struct Struct_ov031_022402b0 { unsigned char pad[8]; void* field8; };
extern struct Struct_ov031_022402b0* data_ov031_02290fdc;
extern "C" void func_ov031_02240210(void*);

// USA: func_ov031_022402b0
extern "C" ARM void func_ov031_022402b0(void) {
	struct Struct_ov031_022402b0* n = data_ov031_02290fdc;
	if (n != NULL) {
		do {
			func_ov031_02240210(n->field8);
			n = data_ov031_02290fdc;
		} while (n != NULL);
	}
}
