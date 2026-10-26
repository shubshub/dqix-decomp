#include <globaldefs.h>

// USA: func_ov000_0215e938
extern "C" ARM void* func_ov000_0215e938(void* p) {
	unsigned char idx = *((unsigned char*)p + 0x8e01);
	if (idx >= 0x88) {
		return 0;
	}
	return (char*)p + 0xec0 + idx * 0x24;
}
