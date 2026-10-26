#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0221b158(void* p);
extern "C" void func_ov031_02236570(int v);

union Struct_ov031_02236174 {
	unsigned char raw[0xf0];
	struct {
		unsigned char pad0[0xc0];
		unsigned char idA[4];
		unsigned char unknown_c4_[4];
		unsigned char unknown_c8_[8];
		unsigned char unknown_d0_;
	};
};

struct Struct_ov031_02236174_2 {
	Struct_ov031_02236174 header;
	unsigned char key[4];
	unsigned char slot;
	unsigned char unknown_f5_;
	unsigned char unknown_f6_;
	unsigned char pad[9];
};

struct Struct_ov031_02290cfc_3 { Struct_ov031_02236174_2* entries; };
extern Struct_ov031_02290cfc_3 data_ov031_02290cfc;

// USA: func_ov031_02236174
extern "C" ARM void func_ov031_02236174(void) {
	Struct_ov031_02236174_2* var0 = &data_ov031_02290cfc.entries[4];
	Struct_ov031_02236174* dst = &data_ov031_02290cfc.entries[var0->slot].header;

	*dst = var0->header;

	if (var0->unknown_f5_ != 0) {
		VectorizedMemset(dst->idA, 0, 4);
		VectorizedMemset(dst->unknown_c4_, 0, 4);
		dst->unknown_d0_ = 0;
	} else {
		VectorizedInvertedMemcpy(var0->header.idA, dst->idA, 4);
		VectorizedInvertedMemcpy(var0->header.unknown_c4_, dst->unknown_c4_, 4);
		dst->unknown_d0_ = func_ov031_0221b158(var0->key);
	}

	if (var0->unknown_f6_ != 0) {
		VectorizedMemset(dst->unknown_c8_, 0, 8);
	} else {
		VectorizedInvertedMemcpy(var0->header.unknown_c8_, dst->unknown_c8_, 8);
	}

	func_ov031_02236570(var0->slot);
}
