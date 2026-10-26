#include <globaldefs.h>

extern "C" int func_ov031_0223da38(int idx);
extern "C" int func_ov031_0223bdb0(int, int, int);

// USA: func_ov031_0223be44
extern "C" ARM int func_ov031_0223be44(int a, int b) {
	int v = func_ov031_0223da38(a);
	func_ov031_0223bdb0(a, b, v);
	return v;
}
