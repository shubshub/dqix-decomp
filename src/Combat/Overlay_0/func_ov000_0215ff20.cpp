#include <globaldefs.h>

// USA: func_ov000_0215ff20
extern "C" ARM void func_ov000_0215ff20(void* obj, short val1, unsigned char val2) {
	unsigned char count = *((unsigned char*)obj + 0x17);
	if (count >= 3) {
		return;
	}
	*(short*)((char*)obj + 0xe + count * 2) = val1;
	count = *((unsigned char*)obj + 0x17);
	*((unsigned char*)obj + 0x14 + count) = val2;
	count = *((unsigned char*)obj + 0x17);
	count = count + 1;
	*((unsigned char*)obj + 0x17) = count;
}
