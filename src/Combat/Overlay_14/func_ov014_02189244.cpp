#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov014_02188d48_4 { int unknown_0_; int w1; int w2; int unknown_c_; int w4; };

extern "C" int func_ov014_0218934c(Struct_ov014_02188d48_4* p0);
extern "C" void func_ov014_021891f0(Struct_ov014_02188d48_4* p0, int p3);

// USA: func_ov014_02189244
extern "C" ARM int func_ov014_02189244(Struct_ov014_02188d48_4* dst, Struct_ov014_02188d48_4* src, char* arg2, int p3) {
	*arg2 = 0;
	if (src == NULL) return 0;
	memcpy(dst, src, 0xc);
	dst->unknown_c_ = (int)src + 0xc;
	int r = func_ov014_0218934c(dst);
	dst->w4 = (int)src + (r + 0xc);
	if ((unsigned int)dst->w2 >> 31) {
		*arg2 = 1;
		return 1;
	}
	func_ov014_021891f0(dst, p3);
	dst->w2 = (dst->w2 & 0x7fffffff) | 0x80000000;
	src->w2 = (src->w2 & 0x7fffffff) | 0x80000000;
	return 1;
}
