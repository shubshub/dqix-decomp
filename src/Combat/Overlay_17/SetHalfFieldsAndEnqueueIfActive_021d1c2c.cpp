#include <globaldefs.h>

extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" void* Zone3D_GetInstance(void);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d1c2c
ARM void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a0, unsigned short a1) {
	LinkSession_GetInstance();
	if (!LinkSession_IsHostOrSolo()) return;
	unsigned char* base = (unsigned char*)Zone3D_GetInstance();
#if defined(jpn)
	*(unsigned short*)(base + 0x27f4) = a0;
	*(unsigned short*)(base + 0x27f6) = a1;
#else
	*(unsigned short*)(base + 0x27b4) = a0;
	*(unsigned short*)(base + 0x27b6) = a1;
#endif
	void* d = LinkMessageQueue_GetInstance();
	unsigned char buf[0x14];
	buf[0] = 0xb3;
	buf[4] = (unsigned char)a0;
	buf[5] = (unsigned char)a1;
	func_0205e330(d, buf, 0);
}
