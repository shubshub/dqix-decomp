#include <globaldefs.h>

extern "C" int memcmp(unsigned char*, void*, int);
extern "C" int func_ov031_0221b1cc(unsigned char*);
extern "C" int func_ov031_0221b258(unsigned char*);
extern "C" void func_ov031_0221b19c(int arg0, unsigned char* buf);
extern "C" int func_ov031_0221b1f4(unsigned char*, unsigned char*);

extern int data_ov031_022460c0;

// USA: func_ov031_0221bcb8
extern "C" ARM int func_ov031_0221bcb8(unsigned char* obj) {
	unsigned char v = obj[0xe7];
	if (v == 0xff) return 1;
	if (v > 2) return 0;
	if (!func_ov031_0221b1cc(obj + 0x40)) return 0;

	if (memcmp(obj + 0xc0, &data_ov031_022460c0, 4) != 0) {
		if (!func_ov031_0221b258(obj + 0xc4)) return 0;
		if (obj[0xd0] > 0x20) return 0;
		unsigned char local;
		func_ov031_0221b19c(obj[0xd0], &local);
		if (!func_ov031_0221b1f4(obj + 0xc0, &local)) return 0;
	}

	if (memcmp(obj + 0xc8, &data_ov031_022460c0, 4) != 0) {
		if (func_ov031_0221b258(obj + 0xc8) == 0) {
			if (!func_ov031_0221b258(obj + 0xcc)) return 0;
		}
	}

	return 1;
}
