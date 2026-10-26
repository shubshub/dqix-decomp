#include <globaldefs.h>

// USA: func_ov024_021f6fec
extern "C" ARM int func_ov024_021f6fec(void* self) {
	void* p = *(void**)((char*)self + 0x8);
	if (p != NULL) {
		unsigned int h = *(unsigned short*)((char*)p + 0xa);
		unsigned int bits = (h << 0x15) >> 0x1c;
		if (bits == 6) {
			*(float*)((char*)self + 0x1c) = *(float*)((char*)self + 0x14) * 1.5f;
			*(float*)((char*)self + 0x20) = *(float*)((char*)self + 0x18) * 1.5f;
		}
	}
	return 1;
}
