#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_ov017_0218f57c
extern "C" ARM void func_ov017_0218f57c(void* obj, int val) {
#if defined(jpn)
	enum { regionalOffset0 = 0x144 };
#else
	enum { regionalOffset0 = 0x150 };
#endif
	void* inner = *(void**)((char*)obj + regionalOffset0);
	if (!inner) return;
	unsigned char* p = (unsigned char*)inner + 0x56b;
	*p = (*p & ~0xf) | ((unsigned char)val & 0xf);
}
