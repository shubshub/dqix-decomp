#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" ARM int func_ov031_0220bb24(unsigned short* arr, int len);

// USA: func_ov031_0220bee4
extern "C" ARM void func_ov031_0220bee4(unsigned short* dst, unsigned short* src, int arg2, int len) {
	int n = func_ov031_0220bb24(src, len);
	int var1 = 0;
	int i = 0;
	if (n > 0) {
		do {
			int v = arg2 * src[i] + var1;
			dst[i] = (unsigned short)v;
			i++;
			var1 = (unsigned int)v >> 16;
		} while (i < n);
	}
	if (i < len) {
		dst[i] = (unsigned short)var1;
		i++;
	}
	VectorizedMemset(dst + i, 0, (len - i) * 2);
}
