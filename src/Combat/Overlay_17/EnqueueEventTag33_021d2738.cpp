#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d2738 { unsigned char valA; unsigned char valB; };
struct LocalEvt021d2738 { unsigned char tag; unsigned char pad0[3]; Sub021d2738 sub; unsigned char pad2[14]; };

// USA: func_ov017_021d2738
ARM void EnqueueEventTag33_021d2738(unsigned char a, unsigned char b) {
	LocalEvt021d2738 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 0x21;
	Sub021d2738* s = &buf.sub;
	s->valA = a;
	s->valB = b;
	func_0205e330(p, &buf, 0);
}
