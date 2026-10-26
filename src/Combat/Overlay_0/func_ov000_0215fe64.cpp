#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_0215fe64
extern "C" ARM void func_ov000_0215fe64(void* p) {
	memset(p, 0, 0x30);
	*(short*)((char*)p + 0x1c) = -1;
}
