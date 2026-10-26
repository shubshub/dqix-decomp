#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d3bbc {
	unsigned char v0;
	unsigned char v1;
	unsigned char v2;
	unsigned char v3;
};

struct Struct_ov017_021d3bbc_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021d3bbc sub;
	unsigned char pad2[12];
};

// USA: func_ov017_021d3bbc
extern "C" ARM void func_ov017_021d3bbc(int a, int b, int c, int d) {
	Struct_ov017_021d3bbc_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021d3bbc* s = &buf.sub;
	buf.tag = 0xb8;
	s->v0 = (unsigned char)c;
	s->v1 = (unsigned char)d;
	s->v3 = (unsigned char)a;
	s->v2 = (unsigned char)b;
	func_0205e330(p, &buf, 0);
}
