#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Payload021d24a8 {
	unsigned char field0;
	unsigned char pad0[3];
	int field4;
};

struct LocalEvt021d24a8 {
	unsigned char tag;
	unsigned char pad0[3];
	Payload021d24a8 payload;
	unsigned char pad1[8];
};

// USA: func_ov017_021d24a8
ARM void EnqueueEventTag30_021d24a8(int a) {
	void* p = LinkMessageQueue_GetInstance();

	LocalEvt021d24a8 buf;
	Payload021d24a8* q2 = &buf.payload;
	q2->field0 = a;
	buf.tag = 0x1e;
	unsigned short* q = Zone3D_GetInstance();
	q2->field4 = *q;
	func_0205e330(p, &buf, 0);
}
