#include <globaldefs.h>

union Struct_ov017_021d6110 { int i; float f; };
struct Struct_ov017_021d6110_2 { int type; Struct_ov017_021d6110 value; };

// USA: func_ov017_021d6110
extern "C" ARM float func_ov017_021d6110(Struct_ov017_021d6110_2 *a) {
	if (a->type != 0) {
		return a->value.f;
	}
	return (float)a->value.i;
}
