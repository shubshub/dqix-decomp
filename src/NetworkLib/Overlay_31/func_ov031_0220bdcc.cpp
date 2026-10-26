#include <globaldefs.h>

// USA: func_ov031_0220bdcc
extern "C" ARM int func_ov031_0220bdcc(unsigned short* a, unsigned short* b, int count) {
	int i = count - 1;
	if (i >= 0) {
		do {
			unsigned short var1 = b[i];
			unsigned short var2 = a[i];
			if (var2 > var1) return 1;
			if (var2 < var1) return -1;
			i--;
		} while (i >= 0);
	}
	return 0;
}
