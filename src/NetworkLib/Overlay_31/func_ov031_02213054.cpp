#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02213054 { unsigned char pad[0x17]; unsigned char unknown_17_; unsigned char unknown_18_[10]; };
struct Struct_ov031_0224e5c4_4 { unsigned char pad[0xc]; Struct_ov031_02213054* unknown_c_; };
extern Struct_ov031_0224e5c4_4 data_ov031_0224e5c4;
extern "C" int func_ov031_022134b0(void);

// USA: func_ov031_02213054
extern "C" ARM int func_ov031_02213054(void* buf) {
	int result = 0;
	unsigned int v = func_ov031_022134b0();
	if (v >= 0xa && v <= 0x10) {
		Struct_ov031_02213054* p = data_ov031_0224e5c4.unknown_c_;
		if (p->unknown_17_ == 4 || p->unknown_17_ == 8) {
			VectorizedInvertedMemcpy(p->unknown_18_, buf, 0xa);
			result = 1;
		}
	}
	return result;
}
