#include <globaldefs.h>

extern "C" int func_ov031_02206150(int, int, int, int, int, int);

// USA: func_ov031_02207380
extern "C" ARM int func_ov031_02207380(int a, int b, int c, int d) {
	return func_ov031_02206150(a, b, c, 0, 0, d);
}
