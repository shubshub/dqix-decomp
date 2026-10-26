#include <globaldefs.h>

struct Struct_ov024_021e9b24_2 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Struct_ov024_021e9b24 {
	char pad[0x20];
	struct Struct_ov024_021e9b24_2 f20;
	struct Struct_ov024_021e9b24_2 f24;
};

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

// USA: func_ov024_021e9b24
extern "C" ARM unsigned short func_ov024_021e9b24(void* unused0, int id, struct Struct_ov024_021e9b24* range, int arg3) {
	if (arg3 != 0) {
		return func_ov024_021da644(id, range->f24.b, range->f24.c);
	} else {
		return func_ov024_021da644(id, range->f20.c, range->f24.a);
	}
}
