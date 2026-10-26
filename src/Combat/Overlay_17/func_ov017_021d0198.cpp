#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d0198 {
	unsigned char v0;
	unsigned char v1;
	unsigned char v2;
	unsigned char pad3;
	unsigned short v4;
};

struct Struct_ov017_021d0198_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021d0198 sub;
	unsigned char pad2[10];
};

// USA: func_ov017_021d0198
extern "C" ARM void func_ov017_021d0198(int a, int b, int c, int d) {
	Struct_ov017_021d0198_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0xaa;
	Struct_ov017_021d0198* s = &buf.sub;
	s->v0 = (unsigned char)a;
	s->v1 = (unsigned char)b;
	s->v2 = (unsigned char)c;
	s->v4 = (unsigned short)d;
	func_0205e330(p, &buf, 0);
}
