#include <globaldefs.h>

extern "C" int STD_CompareString(const char* a, const char* b);

// USA: func_ov031_02241534
extern "C" ARM int func_ov031_02241534(const char* a, const char* b) {
	return STD_CompareString(a, b);
}
