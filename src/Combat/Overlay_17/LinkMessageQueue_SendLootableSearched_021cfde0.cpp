#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cfde0 {
	unsigned short valA;
	unsigned short valB;
	unsigned short unknown_4_;
};

struct Struct_ov017_021cfde0_2 {
	unsigned char tag;
	unsigned char pad0[3];
	Struct_ov017_021cfde0 sub;
	unsigned char pad2[10];
};

// Overlay 17, originally EnqueueEventTag165_021cfde0 (USA/EUR 0x021cfde0, JPN 0x021d0290)
extern "C" ARM void LinkMessageQueue_SendLootableSearched(unsigned short a, unsigned short b, unsigned short c) {
	Struct_ov017_021cfde0_2 buf;
	void* p = LinkMessageQueue_GetInstance();
	Struct_ov017_021cfde0* s = &buf.sub;
	buf.tag = 0xa5;
	s->valA = a;
	s->valB = b;
	s->unknown_4_ = c;
	func_0205e330(p, &buf, 0);
}
