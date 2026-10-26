#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d257c { unsigned char valA; unsigned char pad[3]; int valB; };
struct Struct_ov017_021d257c_2 { unsigned char tag; unsigned char pad0[3]; Struct_ov017_021d257c sub; unsigned char pad2[8]; };

// USA: func_ov017_021d257c
extern "C" ARM void func_ov017_021d257c(unsigned char a, int b) {
	Struct_ov017_021d257c_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x1f;
	Struct_ov017_021d257c* s = &buf.sub;
	s->valA = a;
	s->valB = b;
	func_0205e330(p, &buf, 0);
}
