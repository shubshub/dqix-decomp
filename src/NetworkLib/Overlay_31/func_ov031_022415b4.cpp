#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_022415b4
extern "C" ARM void func_ov031_022415b4(void* obj, unsigned int len) {
	VectorizedMemset(obj, 0, len);
}
