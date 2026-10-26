#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_02203288
extern "C" ARM void func_ov031_02203288(int value) {
	void* obj = *(void**)((char*)&data_02111304 + 0x4);
	obj = *(void**)((char*)obj + 0xa4);
	if (obj != NULL) {
		*(int*)((char*)obj + 0x38) = value;
	}
}
