#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov027_021e3424_3 {
	unsigned char pad0[4];
	char* arr;
	unsigned int unknown_8_;
	int count;
};

extern Struct_ov027_021e3424_3 data_ov027_021e3424;

extern "C" int func_ov027_021dd864(int id);
extern "C" void* func_ov027_021dd7d8(void* dst, int id);

#pragma optimize_for_size off
// USA: func_ov027_021dd6bc
extern "C" ARM void* func_ov027_021dd6bc(unsigned char* src, unsigned char* dst, int id) {
	unsigned char type = src[0];
	dst[0] = type;
	unsigned char* result;
	switch (type) {
	case 7: {
		if (func_ov027_021dd864(id) == 0) goto notAllSet;
		return data_ov027_021e3424.arr + (id - 1) * 0x20;
	notAllSet:
		unsigned char field1 = src[1];
		dst[2] = field1;
		if (field1 > data_ov027_021e3424.count) {
			return 0;
		}
		VectorizedInvertedMemcpy(src + 2, dst + 3, data_ov027_021e3424.unknown_8_);
		result = (unsigned char*)func_ov027_021dd7d8(dst, id);
		break;
	}
	case 8: {
		result = src + 3;
		*(unsigned short*)(dst + 2) = src[1];
		*(unsigned short*)(dst + 2) = *(unsigned short*)(dst + 2) | ((src[2] << 8) & 0xff00);
		break;
	}
	case 9: {
		result = src + 3;
		*(unsigned short*)(dst + 2) = src[1];
		*(unsigned short*)(dst + 2) = *(unsigned short*)(dst + 2) | ((src[2] << 8) & 0xff00);
		VectorizedInvertedMemcpy(result, dst + 4, data_ov027_021e3424.unknown_8_);
		result = result + data_ov027_021e3424.unknown_8_;
		break;
	}
	default:
		return 0;
	}
	return result;
}
