#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_0220c8d0
extern "C" ARM void func_ov031_0220c8d0(unsigned short* dst, unsigned char* src, int len, int outLen) {
	VectorizedMemset(dst, 0, outLen * 2);
	src = src + (len - 1);
	if (len > 1) {
		do {
			unsigned char hi = *src;
			unsigned char lo = *(src - 1);
			len -= 2;
			*dst++ = hi + (lo << 8);
			src -= 2;
		} while (len > 1);
	}
	if (len > 0) {
		*dst = *src;
	}
}
