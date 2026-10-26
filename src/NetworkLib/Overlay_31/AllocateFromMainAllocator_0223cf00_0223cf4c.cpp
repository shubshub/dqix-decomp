#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" ARM void* func_ov031_0223cf00(unsigned int len, int align);

// USA: func_ov031_0223cf4c
extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align) {
	void* p = func_ov031_0223cf00(len, align);
	VectorizedMemset(p, 0, len);
	return p;
}
