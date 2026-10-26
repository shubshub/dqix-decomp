#include <globaldefs.h>

extern "C" int func_ov031_02207428(int, int);

// USA: func_ov031_02241518
extern "C" ARM int func_ov031_02241518(int a, int b) {
	if (b < 0) return a;
	return func_ov031_02207428(b, 2);
}
