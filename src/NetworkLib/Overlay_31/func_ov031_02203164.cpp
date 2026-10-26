#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_02203164
extern "C" ARM void func_ov031_02203164(int v) {
	void* p = *((void**)&data_02111304 + 1);
	*(int*)((char*)p + 0xa4) = v;
}
