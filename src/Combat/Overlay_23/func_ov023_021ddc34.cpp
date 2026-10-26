#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov023_021ff9e0_9 {
	#if defined(jpn)
	unsigned int pad0[5];
#else
	unsigned int pad0;
#endif
	void* field4;
};

extern struct Struct_ov023_021ff9e0_9 data_ov023_021ff9e0;

// USA: func_ov023_021ddc34
extern "C" ARM int func_ov023_021ddc34(void* obj, short a, short b, short c, short d) {
	int result = 0;
	if (data_ov023_021ff9e0.field4) {
		if (obj) {
			memset(data_ov023_021ff9e0.field4, 0, 0x1800);
			*(void**)((char*)obj + 0x8) = data_ov023_021ff9e0.field4;
			*(short*)((char*)obj + 0xac) = a;
			*(short*)((char*)obj + 0xae) = b;
			*(short*)((char*)obj + 0xa8) = c;
			*(short*)((char*)obj + 0xaa) = d;
			result = 1;
		}
	}
	return result;
}
