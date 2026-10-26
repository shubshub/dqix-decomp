#include <globaldefs.h>

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov024_021f72f8_2 { unsigned int unknown_0_; unsigned int val : 10; };
struct Struct_ov024_021f72f8 { void* obj; char pad[0x10]; float unknown_14_; float unknown_18_; float f1c; float f20; };

// USA: func_ov024_021f72f8
extern "C" ARM int func_ov024_021f72f8(struct Struct_ov024_021f72f8* s) {
	int base = func_02053c6c((unsigned char*)s->obj);
	int v = ((struct Struct_ov024_021f72f8_2*)base)->val;
	s->f1c = s->unknown_14_ / 2.0f + (float)v;
	s->f20 = s->unknown_18_ / 2.0f + (float)v;
	return 1;
}
