#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_02236174(void);

struct Struct_ov031_02290cfc_5 { void* field0; };
extern Struct_ov031_02290cfc_5 data_ov031_02290cfc;

struct Struct_ov031_02236364 { unsigned char mode : 2; unsigned char unknown_0_2_ : 6; };

// USA: func_ov031_02236364
extern "C" ARM void func_ov031_02236364(unsigned char* dst) {
	unsigned char* src = (unsigned char*)data_ov031_02290cfc.field0 + 0x400;

	VectorizedMemset(src, 0, 0xef);
	VectorizedInvertedMemcpy(dst, src + 0xd1, 5);
	VectorizedInvertedMemcpy(dst + 0x6, src + 0xd6, 5);
	VectorizedInvertedMemcpy(dst + 0xc, src + 0xdb, 5);
	VectorizedInvertedMemcpy(dst + 0x12, src + 0xe0, 5);
	VectorizedInvertedMemcpy(dst + 0x18, src + 0x60, 0x20);
	VectorizedInvertedMemcpy(dst + 0x39, src + 0x80, 0xd);
	VectorizedInvertedMemcpy(dst + 0x47, src + 0x90, 0xd);
	VectorizedInvertedMemcpy(dst + 0x55, src + 0xa0, 0xd);
	VectorizedInvertedMemcpy(dst + 0x63, src + 0xb0, 0xd);
	VectorizedInvertedMemcpy(dst + 0x71, src + 0x40, 0x20);

	Struct_ov031_02236364* f = (Struct_ov031_02236364*)(src + 0xe6);
	f->mode = 2;
	f->unknown_0_2_ = 0;
	src[0xe7] = 1;

	VectorizedMemset(src + 0xf0, 0, 4);
	src[0xf5] = 1;
	src[0xf6] = 1;
	func_ov031_02236174();
}
