#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cea34
ARM void EnqueueEventTag49_021cea34(int a0) {
	void* p = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0x31;
	*(int*)(buf + 4) = a0;
	func_0205e330(p, buf, 0);
}
