#include <globaldefs.h>

// USA: func_ov000_02171a60
extern "C" ARM int func_ov000_02171a60(void* obj) {
	return (*(int*)((char*)obj + 0x28) & 1) != 0;
}
