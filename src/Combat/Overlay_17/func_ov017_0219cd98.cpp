#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219cd98_14012 = 0x34ac };
#else
enum { Enum_ov017_0219cd98_14012 = 0x36bc };
#endif

extern "C" void* func_ov017_0219c6f4(void*);

// USA: func_ov017_0219cd98
extern "C" ARM void func_ov017_0219cd98(void* obj) {
	void* p = *(void**)((char*)obj + Enum_ov017_0219cd98_14012);
	if (!p) return;
	void* r = func_ov017_0219c6f4(p);
	if (r) *((unsigned char*)r + 0x2) = 1;
}
