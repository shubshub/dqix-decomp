#include <globaldefs.h>

// USA: func_ov031_02211644
extern "C" ARM int func_ov031_02211644(void* obj) {
	return (*(unsigned int*)((char*)obj + 0x20) & 1) != 0;
}
