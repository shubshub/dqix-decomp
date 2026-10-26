#include <globaldefs.h>

struct Struct_ov023_021f2e6c_2 { char pad[0x64]; int f64; int f68; };

// USA: func_ov023_021f3a8c
extern "C" ARM int func_ov023_021f3a8c(struct Struct_ov023_021f2e6c_2* s) {
	return s->f64 == -1 && s->f68 == -1;
}
