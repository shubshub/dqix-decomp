#include <globaldefs.h>

// USA: func_ov031_0223dd34
extern "C" ARM int func_ov031_0223dd34(unsigned char* s, int len) {
	int i = 0;
	if (len > 0) {
		do {
			if (s[i] == 0) {
				break;
			}
			i++;
		} while (i < len);
	}
	return i;
}
