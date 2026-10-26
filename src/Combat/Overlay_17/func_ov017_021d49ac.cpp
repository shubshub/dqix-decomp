#include <globaldefs.h>

// USA: func_ov017_021d49ac
struct Struct_ov017_021d49ac { int a; int b; int c; int d; };

extern "C" ARM int func_ov017_021d49ac(struct Struct_ov017_021d49ac s) {
	return s.a != 0 || s.b != 0;
}
