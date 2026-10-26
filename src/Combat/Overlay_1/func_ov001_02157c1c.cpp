#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov001_02157c1c
extern "C" ARM int func_ov001_02157c1c(void* a, void* b) {
	memcpy((char*)b + 0x58, (char*)a + 0x10, 0xc);
	return 0;
}
