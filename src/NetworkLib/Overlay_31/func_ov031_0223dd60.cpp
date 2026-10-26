#include <globaldefs.h>

// USA: func_ov031_0223dd60
extern "C" ARM int func_ov031_0223dd60(unsigned short* dst, unsigned char* src, int maxLen) {
	int limit = maxLen - 1;
	int i = 0;
	if (limit > 0) {
		do {
			unsigned char c = src[i];
			if (c == 0) break;
			dst[i] = c;
			i++;
		} while (i < limit);
	}
	dst[i] = 0;
	return i;
}
