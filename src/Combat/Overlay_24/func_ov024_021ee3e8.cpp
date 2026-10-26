#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);

extern unsigned short data_ov024_021feafc;

// USA: func_ov024_021ee3e8
extern "C" ARM int func_ov024_021ee3e8(int* a0, int a1, int a2, int* out, void* dst) {
	unsigned short buf[4];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021feafc;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int result = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (result <= 0) return 0;
	*out = result;
	memcpy(dst, buf, 8);
	return 1;
}
