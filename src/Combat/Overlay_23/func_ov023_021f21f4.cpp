#include <globaldefs.h>

struct Struct_ov023_021f1868_10 { char pad[0x60]; int f60; int f64; };

// USA: func_ov023_021f21f4
extern "C" ARM int func_ov023_021f21f4(struct Struct_ov023_021f1868_10* s) {
	int a = s->f60 == -1;
	int b = s->f64 == -1;
	return (a & b) != 0;
}
