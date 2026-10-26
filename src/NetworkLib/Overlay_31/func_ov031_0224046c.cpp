#include <globaldefs.h>

// USA: func_ov031_0224046c
extern "C" ARM signed char func_ov031_0224046c(void* obj, void** arg1, int* counter) {
	if (*arg1 == 0) {
		if (*counter < 0x400) {
			int c = *counter;
			*counter = c + 1;
			return *((signed char*)obj + c + 0x20);
		}
		*counter = 0;
		*arg1 = *(void**)((char*)obj + 0x1c);
	} else {
		if (*counter == 0x200) {
			*counter = 0;
			*arg1 = *(void**)*arg1;
		}
	}
	int c = *counter;
	*counter = c + 1;
	return *((signed char*)*arg1 + c + 4);
}
