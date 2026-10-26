#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d2738 { unsigned char valA; unsigned char valB; };
struct Struct_ov017_021d2738_2 { unsigned char tag; unsigned char pad0[3]; Struct_ov017_021d2738 sub; unsigned char pad2[14]; };

// USA: func_ov017_021d2738
extern "C" ARM void func_ov017_021d2738(unsigned char a, unsigned char b) {
	Struct_ov017_021d2738_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x21;
	Struct_ov017_021d2738* s = &buf.sub;
	s->valA = a;
	s->valB = b;
	func_0205e330(p, &buf, 0);
}
