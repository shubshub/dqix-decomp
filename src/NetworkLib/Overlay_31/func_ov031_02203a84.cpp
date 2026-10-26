#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" int func_ov031_022039b0(void* a0, int a1, void* a2, int a3);
extern "C" void* memmove(void*, const void*, unsigned int);

// USA: func_ov031_02203a84
extern "C" ARM int func_ov031_02203a84(void* p0, int p1) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) goto ret0;
	int v = *(int*)((char*)mgr + 0x60);
	if (v == 0) goto zero_case;
	v = func_ov031_022039b0(*(void**)((char*)mgr + 0x5c), v, p0, p1);
	{
		int size = *(int*)((char*)mgr + 0x60);
		if ((unsigned int)v < (unsigned int)size) {
			memmove(*(void**)((char*)mgr + 0x5c), (char*)*(void**)((char*)mgr + 0x5c) + v, size - v);
			size = *(int*)((char*)mgr + 0x60);
			*(int*)((char*)mgr + 0x60) = size - v;
			return 0;
		}
		*(int*)((char*)mgr + 0x60) = 0;
		return v - size;
	}
zero_case:
	return func_ov031_022039b0(p0, p1, (void*)0, 0);
ret0:
	return 0;
}
