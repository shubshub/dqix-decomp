#include <globaldefs.h>

// USA: func_ov031_0220bd64
extern "C" ARM void func_ov031_0220bd64(unsigned short* dst, unsigned short* src, int arg2, int count) {
	int i = 0;
	if (count > 0) {
		do {
			int v = src[i] - arg2;
			dst[i] = (unsigned short)v;
			arg2 = ((unsigned int)v >> 16) & 1;
			if (arg2 == 0) break;
			i++;
		} while (i < count);
	}
	if (dst == src) return;
	i++;
	if (i >= count) return;
	do {
		dst[i] = src[i];
		i++;
	} while (i < count);
}
