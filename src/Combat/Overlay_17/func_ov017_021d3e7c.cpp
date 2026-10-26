#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d3e7c_6208 = 0x1860 };
#else
enum { Enum_ov017_021d3e7c_6208 = 0x1840 };
#endif

extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021a01bc(unsigned char* self);

// USA: func_ov017_021d3e7c
extern "C" ARM void func_ov017_021d3e7c(void* a, unsigned char* b, int c, unsigned char* d, void* e) {
	if (LinkSession_IsGuest(e) == 0) return;
	int p = (int)Zone3D_GetInstance();
	unsigned char* base = (unsigned char*)(p + Enum_ov017_021d3e7c_6208);
	*(int*)(base + 0xb3c) = b[4];
	func_ov017_021a01bc(d);
}
