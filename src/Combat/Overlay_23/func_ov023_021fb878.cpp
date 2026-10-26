#include <globaldefs.h>

struct Struct_ov023_021fb878 {
	unsigned int a;
	unsigned int b;
};

struct Struct_ov023_021fb878_2 {
	char pad[0xa8];
	unsigned int a;
	unsigned int b;
};

// USA: func_ov023_021fb878
extern "C" ARM void func_ov023_021fb878(struct Struct_ov023_021fb878_2 *dst, struct Struct_ov023_021fb878 *src) {
	dst->a = src->a;
	dst->b = src->b;
}
