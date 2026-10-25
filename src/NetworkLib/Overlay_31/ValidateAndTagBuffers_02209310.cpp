#include <globaldefs.h>

extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);
extern "C" void func_ov031_02209158(void* obj, void* out, int mode);
extern "C" void func_ov031_02209234(void* obj, void* out, int mode);
extern "C" int memcmp(void* a, void* b, int n);

// USA: func_ov031_02209310  (semantic: ValidateAndTagBuffers_02209310)
extern "C" ARM void func_ov031_02209310(char* obj, char* buf) {
	char scratch[0x14];
	VectorizedInvertedMemcpy(obj + 0x3a4, obj + 0x3fc, 0x58);
	func_ov031_02209158(obj, scratch, 1);
	VectorizedInvertedMemcpy(obj + 0x3fc, obj + 0x3a4, 0x58);
	if (memcmp(buf, scratch, 0x10) != 0) {
		obj[0x455] = 9;
		return;
	}
	VectorizedInvertedMemcpy(obj + 0x2ec, obj + 0x348, 0x5c);
	func_ov031_02209234(obj, scratch, 1);
	VectorizedInvertedMemcpy(obj + 0x348, obj + 0x2ec, 0x5c);
	if (memcmp(buf + 0x10, scratch, 0x14) != 0) {
		obj[0x455] = 9;
	} else {
		obj[0x455] = 6;
	}
}
