#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void* func_ov031_022133f8(unsigned int flags);

// USA: func_ov031_0221314c
extern "C" ARM void func_ov031_0221314c(unsigned char* name, void* src, int mode) {
	unsigned char* obj = (unsigned char*)func_ov031_022133f8(0x10);

	obj[0xd0c] = (obj[0xd0c] & ~0xf) | 1;
	VectorizedMemset(obj, 0, 0xf0);

	for (int i = 0; i < 0x20; i++) {
		if (name[i] == 0) break;
		obj[0x40 + i] = name[i];
	}

	if (src == 0 || mode == 0) {
		obj[0xe6] = obj[0xe6] & ~3;
		return;
	}

	int size;
	if (mode == 1) {
		size = 5;
	} else if (mode == 2) {
		size = 0xd;
	} else {
		size = 0x10;
	}
	VectorizedInvertedMemcpy(src, obj + 0x80, size);
	obj[0xe6] = (obj[0xe6] & ~3) | ((unsigned char)mode & 3);
}
