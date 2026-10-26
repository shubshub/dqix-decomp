#include <globaldefs.h>

union Struct_ov017_021d60f4 { int i; float f; };
struct Struct_ov001_0215f344 { int type; Struct_ov017_021d60f4 value; };

// USA: func_ov017_021d60f4
extern "C" ARM int func_ov017_021d60f4(Struct_ov001_0215f344 *a) {
	if (a->type != 1) {
		return a->value.i;
	}
	return (int)a->value.f;
}
