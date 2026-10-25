#include <globaldefs.h>

extern "C" int func_ov031_0221b6f0(int, int, int);
extern "C" int memcmp(int, int, int);

// USA: func_ov031_0221b7fc
ARM int CheckAndCompare_0221b7fc(int a, int b, int c, int d) {
	if (func_ov031_0221b6f0(b, c, d) == 0) return 0;
	return memcmp(a, d, c) == 0;
}
