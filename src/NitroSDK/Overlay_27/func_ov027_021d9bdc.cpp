#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

struct Struct_ov027_021e33ec_4 {
	void *field0;
};

extern struct Struct_ov027_021e33ec_4 data_ov027_021e33ec;

extern "C" int func_ov027_021d96c4(unsigned char type, int value);
extern "C" int func_ov027_021d9704(void);
extern "C" int func_ov027_021d9940(void);
extern "C" void func_020ca390(int val, void *dst, unsigned int nBytes);

// USA: func_ov027_021d9bdc
#pragma optimize_for_size off
extern "C" ARM int func_ov027_021d9bdc(void) {
	unsigned short counts[5];
	func_020ca390(0, counts, 0xa);

	unsigned short i = 1;
	char *base = (char*)data_ov027_021e33ec.field0;
	do {
		int category = *(int*)(base + (i << 2) + 0x14e4);
		switch (category) {
		case 2: counts[0] |= 1 << i; break;
		case 5: counts[1] |= 1 << i; break;
		case 4: counts[2] |= 1 << i; break;
		case 8: counts[3] |= 1 << i; break;
		case 11: counts[4] |= 1 << i; break;
		default: break;
		}
		i++;
	} while (i <= 0xf);

	int result;
	if (counts[3] != 0) {
		result = func_ov027_021d96c4(5, counts[3]);
	} else if (counts[0] != 0) {
		result = func_ov027_021d96c4(1, counts[0]);
	} else if (counts[4] != 0) {
		result = func_ov027_021d96c4(6, counts[4]);
	} else if (counts[2] != 0) {
		result = func_ov027_021d96c4(2, counts[2]);
	} else if (counts[1] != 0) {
		result = func_ov027_021d9704();
	} else {
		result = func_ov027_021d9940();
	}

	if (result == 0x15) {
		return func_ov027_021d96c4(0, 0xffff);
	}
	return result;
}
