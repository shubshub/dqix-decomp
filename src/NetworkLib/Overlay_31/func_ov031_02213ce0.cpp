#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" unsigned char func_ov031_02213f14(void* e);
extern "C" bool func_ov031_022140e8(void* obj, int arg1, void* buf);

// USA: func_ov031_02213ce0
extern "C" ARM int func_ov031_02213ce0(void* e) {
	unsigned char* base = (unsigned char*)e;
	unsigned char idx = base[0xd13];
	unsigned char* arr = base + 0x470 + idx * 0xc0;

	base[0xd0d] = func_ov031_02213f14(e);

	VectorizedMemset(base + 0xb8 + 0xc00, 0, 0x52);

	bool var3 = func_ov031_022140e8(e, base[0xd0d], base + 0xb8 + 0xc00);

	if (var3) {
		base[0xd0b] = (base[0xd0b] & ~0xc) | 4;
		int bits = *(unsigned short*)(arr + 0x2c) >> 4;
		if (!(bits & 1)) {
			unsigned char* p = base + base[0xd13] * 4;
			p[0x444] = 3;
			return 9;
		} else {
			if (base[0xd0d] == 6 && arr[0x15] == 0) {
				unsigned char* p = base + base[0xd13] * 4;
				p[0x444] = 3;
				return 9;
			}
		}
	} else {
		base[0xd0b] = base[0xd0b] & ~0xc;
		int bits = *(unsigned short*)(arr + 0x2c) >> 4;
		unsigned int bit0 = bits & 1;
		if (bit0 == 1) {
			unsigned char* p = base + base[0xd13] * 4;
			p[0x444] = 3;
			return 9;
		}
	}

	base[0xd15] = 0;
	base[0xd14] = 0;
	return 8;
}
