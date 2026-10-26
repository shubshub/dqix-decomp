#include <globaldefs.h>

extern "C" int func_ov031_02211aec(void);
extern "C" int func_ov031_0223f1e8(int);

// USA: func_ov031_02212c18
extern "C" ARM int func_ov031_02212c18(int a) {
	if (func_ov031_02211aec()) return 0;
	return func_ov031_0223f1e8(a);
}
