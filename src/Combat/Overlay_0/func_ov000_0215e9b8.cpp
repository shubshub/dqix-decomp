#include <globaldefs.h>

// USA: func_ov000_0215e9b8
extern "C" ARM void* func_ov000_0215e9b8(void* p) {
	unsigned char idx = *((unsigned char*)p + 0x8e03);
	if (idx >= 0xfc) {
		return 0;
	}
	return (char*)p + 0x5480 + idx * 8;
}
