#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021c9cd8
ARM void EnqueueEventTag125_021c9cd8(unsigned char a0) {
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0x7d;
	buf[4] = a0;
	func_0205e330(p, buf, 0);
}
