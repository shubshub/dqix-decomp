#include <globaldefs.h>

extern "C" int func_ov017_02191fec(int a, int b, int c);
extern "C" int func_ov017_0218fd34(int a, int b, int c);

// USA: func_ov017_0218fcf8
extern "C" ARM int func_ov017_0218fcf8(int a, int b, int c) {
	int ok = func_ov017_02191fec(a, b, c) != 0;
	if (!ok) {
		return ok;
	}
	return func_ov017_0218fd34(a, b, c);
}
