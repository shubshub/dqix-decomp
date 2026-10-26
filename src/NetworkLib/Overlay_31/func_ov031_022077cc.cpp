#include <globaldefs.h>

extern "C" int func_ov031_02206ebc(int a);

// USA: func_ov031_022077cc
extern "C" ARM int func_ov031_022077cc(int a, unsigned int* out) {
	int v = func_ov031_02206ebc(a);
	if (v == 0) {
		return 0;
	}
	unsigned int w = (unsigned int)v;
	unsigned int s = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
	*out = s;
	return 1;
}
