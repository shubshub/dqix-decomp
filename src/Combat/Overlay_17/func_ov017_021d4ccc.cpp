#include <globaldefs.h>

extern "C" void func_ov017_021d4e38(void* obj);

// USA: func_ov017_021d4ccc
extern "C" ARM void func_ov017_021d4ccc(void* obj) {
	if (*(int*)((char*)obj + 0x38))
		func_ov017_021d4e38(obj);
}
