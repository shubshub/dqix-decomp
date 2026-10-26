#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// USA: func_ov031_0223fb74
extern "C" ARM void func_ov031_0223fb74(void* dst, const void* src, unsigned int length) {
	VectorizedInvertedMemcpy(src, dst, length);
}
