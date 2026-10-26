#include <globaldefs.h>

extern "C" void func_ov017_021a4368(int obj, void* field0);

// USA: func_ov017_021a4358
extern "C" ARM void func_ov017_021a4358(int obj) {
	func_ov017_021a4368(obj, *(void**)obj);
}
