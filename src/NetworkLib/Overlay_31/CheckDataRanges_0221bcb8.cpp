#include <globaldefs.h>

extern "C" int memcmp(unsigned char*, void*, int);
int HasNonZeroByte32_0221b1cc(unsigned char*);
int CheckRange_0221b258(unsigned char*);
void WriteMaskBytes_0221b19c(int numBits, unsigned char* buf);
extern "C" int func_ov031_0221b1f4(unsigned char*, unsigned char*);

extern int data_ov031_022460c0;

// USA: func_ov031_0221bcb8  (semantic: CheckDataRanges_0221bcb8)
extern "C" ARM int func_ov031_0221bcb8(unsigned char* obj) {
	unsigned char v = obj[0xe7];
	if (v == 0xff) return 1;
	if (v > 2) return 0;
	if (!HasNonZeroByte32_0221b1cc(obj + 0x40)) return 0;

	if (memcmp(obj + 0xc0, &data_ov031_022460c0, 4) != 0) {
		if (!CheckRange_0221b258(obj + 0xc4)) return 0;
		if (obj[0xd0] > 0x20) return 0;
		unsigned char local;
		WriteMaskBytes_0221b19c(obj[0xd0], &local);
		if (!func_ov031_0221b1f4(obj + 0xc0, &local)) return 0;
	}

	if (memcmp(obj + 0xc8, &data_ov031_022460c0, 4) != 0) {
		if (CheckRange_0221b258(obj + 0xc8) == 0) {
			if (!CheckRange_0221b258(obj + 0xcc)) return 0;
		}
	}

	return 1;
}
