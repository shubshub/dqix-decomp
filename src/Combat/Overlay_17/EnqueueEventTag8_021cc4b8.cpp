#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc4b8 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char field4;
	unsigned char field5;
	unsigned char pad1[2];
	int field8;
	unsigned char pad2[8];
};

// USA: func_ov017_021cc4b8
ARM void EnqueueEventTag8_021cc4b8(unsigned char a, unsigned char b, int c) {
	LocalEvt021cc4b8 buf;
	void* p = LinkMessageQueue_GetInstance();
	buf.tag = 8;
	buf.field4 = a;
	buf.field5 = b;
	buf.field8 = c;
	func_0205e330(p, &buf, 0);
}
