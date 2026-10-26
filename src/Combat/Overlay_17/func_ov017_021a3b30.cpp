#include <globaldefs.h>

extern "C" void func_ov017_021a3b40(int obj, void* field0);

// USA: func_ov017_021a3b30
extern "C" ARM void func_ov017_021a3b30(int obj) {
	func_ov017_021a3b40(obj, *(void**)obj);
}
