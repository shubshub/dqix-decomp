#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021c9ad4
ARM void EnqueueEventTag86_021c9ad4(unsigned short a0) {
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0x56;
	*(unsigned short*)(buf + 6) = a0;
	func_0205e330(p, buf, 0);
}
