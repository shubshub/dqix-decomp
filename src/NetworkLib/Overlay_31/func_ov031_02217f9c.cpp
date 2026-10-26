#include <globaldefs.h>
extern "C" int func_ov031_02204c84(int a);

// USA: func_ov031_02217f9c
extern "C" ARM int func_ov031_02217f9c(void* obj) {
	return func_ov031_02204c84(*(int*)((char*)obj + 0x1124));
}
