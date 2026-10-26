#include <globaldefs.h>

// USA: func_ov017_0219219c
extern "C" ARM void* func_ov017_0219219c(char* base, int idx) {
#if defined(jpn)
 enum {regionalOffset0=0xcc, regionalOffset1=0xd1, regionalOffset2=0x3400};
#else
 enum {regionalOffset0=0x2dc, regionalOffset1=0xe1, regionalOffset2=0x3600};
#endif
	int var0 = (idx >= 0 && idx <= 3);
	if (var0) {
		return base + regionalOffset0 + 0x3400 + idx;
	}
	int var1 = (idx >= 0xc0 && idx <= 0xc7);
	if (var1) {
		return base + regionalOffset1 + regionalOffset2 + (idx - 0xc0);
	}
	return NULL;
}
