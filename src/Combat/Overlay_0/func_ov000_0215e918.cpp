#include <globaldefs.h>

// USA: func_ov000_0215e918
extern "C" ARM void* func_ov000_0215e918(void* p) {
	unsigned char idx = *((unsigned char*)p + 0x8e00);
	if (idx >= 0x48) {
		return 0;
	}
	return (char*)p + 0x20 + idx * 0x34;
}
