#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_02236174(void);

struct Struct_ov031_02290cfc_4 { void* field0; };
extern Struct_ov031_02290cfc_4 data_ov031_02290cfc;

struct Struct_ov031_02236250 { unsigned char mode : 2; unsigned char unknown_0_2_ : 6; };

// USA: func_ov031_02236250
extern "C" ARM void func_ov031_02236250(unsigned char* self) {
	unsigned char* base = (unsigned char*)data_ov031_02290cfc.field0;

	VectorizedMemset(base + 0x400, 0, 0xef);
	VectorizedInvertedMemcpy(self, base + 0x440, 0x20);

	int count;
	switch (*(int*)(self + 0x20)) {
	case 1:
		((Struct_ov031_02236250*)(base + 0x4e6))->mode = 1;
		count = 5;
		break;
	case 2:
		((Struct_ov031_02236250*)(base + 0x4e6))->mode = 2;
		count = 0xd;
		break;
	case 3:
		((Struct_ov031_02236250*)(base + 0x4e6))->mode = 3;
		count = 0x10;
		break;
	default:
		((Struct_ov031_02236250*)(base + 0x4e6))->mode = 0;
		count = 0;
		break;
	}
	((Struct_ov031_02236250*)(base + 0x4e6))->unknown_0_2_ = 0;

	int i = 0;
	unsigned char* s = base + 0x480;
	unsigned char* d = self + 0x28;
	do {
		VectorizedInvertedMemcpy(d, s, count);
		i++;
		s += 0x10;
		d += 0x20;
	} while (i < 4);

	base[0x4e7] = 2;
	VectorizedMemset(base + 0x4f0, 0, 4);
	base[0x4f5] = 1;
	base[0x4f6] = 1;
	func_ov031_02236174();
}
