#include <globaldefs.h>

struct Struct_ov005_02156ecc_2 { int a; int b; int c; };
struct Struct_ov005_02156ecc { char pad[0x1c]; int a; int b; int c; };

// USA: func_ov005_02157174
extern "C" ARM void func_ov005_02157174(Struct_ov005_02156ecc* dst, Struct_ov005_02156ecc_2* src) {
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
