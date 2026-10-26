#include <globaldefs.h>

extern "C" int func_ov031_02243850(void*);
extern "C" void func_ov031_022439d8(void*);

// USA: func_ov031_022436c0
extern "C" ARM void func_ov031_022436c0(void* a) {
	if (func_ov031_02243850(a) < 0) {
		func_ov031_022439d8(a);
	}
}
