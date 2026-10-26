#include <globaldefs.h>

struct Struct_ov004_0215de9c {
	char pad[0x30];
	unsigned short a;
	unsigned short b;
	unsigned short c;
	unsigned short d;
};

// USA: func_ov023_021fb25c
extern "C" ARM void func_ov023_021fb25c(Struct_ov004_0215de9c* obj, unsigned int a, unsigned int b, unsigned int c, int d) {
	obj->a = a;
	obj->b = b;
	obj->c = c;
	obj->d = d;
}
