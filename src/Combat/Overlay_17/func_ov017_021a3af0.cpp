#include <globaldefs.h>

extern "C" void func_ov017_021a3b00(int unused, char* obj);

// USA: func_ov017_021a3af0
extern "C" ARM void func_ov017_021a3af0(int obj) {
	func_ov017_021a3b00(obj, *(char**)obj);
}
