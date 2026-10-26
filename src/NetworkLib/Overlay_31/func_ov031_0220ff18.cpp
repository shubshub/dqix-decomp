#include <globaldefs.h>

extern "C" int func_ov031_0221032c(void* obj);

// USA: func_ov031_0220ff18
extern "C" ARM int func_ov031_0220ff18(void* obj) {
	int field0 = *(int*)obj;
	return field0 == func_ov031_0221032c(obj);
}
