#include <globaldefs.h>

// USA: func_ov031_02242b5c
extern "C" ARM int func_ov031_02242b5c(const char* s) {
	int len = 0;
	signed char c = *s++;
	if (c != 0) {
		do {
			if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
				len += 1;
			} else {
				len += 3;
			}
			c = *s++;
		} while (c != 0);
	}
	return len;
}
