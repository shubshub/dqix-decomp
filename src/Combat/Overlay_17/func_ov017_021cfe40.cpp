#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cfe40 {
	unsigned short valA;
	unsigned short unknown_2_;
	unsigned short valB;
};

struct Struct_ov017_021cfe40_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021cfe40 sub;
	unsigned char pad2[10];
};

// USA: func_ov017_021cfe40
extern "C" ARM void func_ov017_021cfe40(unsigned short a, unsigned short b, unsigned short c) {
	Struct_ov017_021cfe40_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cfe40* s = &buf.sub;
	buf.tag = 0xa6;
	s->valA = a;
	s->valB = b;
	s->unknown_2_ = c;
	func_0205e330(p, &buf, 0);
}
