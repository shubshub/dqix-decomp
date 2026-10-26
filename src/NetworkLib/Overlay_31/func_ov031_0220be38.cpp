#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb24(unsigned short* arr, int len);
extern "C" void func_ov031_0220be04(unsigned short* arr, int arg1, int i, int count);

// USA: func_ov031_0220be38
extern "C" ARM void func_ov031_0220be38(unsigned short* dst, unsigned short* b, unsigned short* c, int n) {
	VectorizedMemset(dst, 0, n * 2);
	int var0;
	int var1 = func_ov031_0220bb24(b, n);
	var0 = func_ov031_0220bb24(c, n);
	int i = 0;
	if (var0 <= 0) return;
	do {
		int j;
		int limit = n - i;
		for (j = 0; j < var1 && j < limit; j++) {
			int var5 = b[j] * c[i];
			func_ov031_0220be04(dst, var5, i + j, n);
		}
		i++;
	} while (i < var0);
}
