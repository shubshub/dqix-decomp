#include <globaldefs.h>

// USA: func_ov031_02241540
extern "C" ARM int func_ov031_02241540(const char* a, const char* b, int n) {
	if (n > 0) {
		do {
			signed char c1 = *a++;
			signed char c2 = *b++;
			if (c1 == 0 || c2 == 0) {
				if (c1 == 0 && c2 == 0) {
					n = 0;
				}
				break;
			}
			int v2 = c2;
			if (v2 >= 'A' && v2 <= 'Z') {
				v2 += 0x20;
			}
			int v1 = c1;
			if (v1 >= 'A' && v1 <= 'Z') {
				v1 += 0x20;
			}
			if (v1 != v2) {
				break;
			}
			n--;
		} while (n > 0);
	}
	return n;
}
