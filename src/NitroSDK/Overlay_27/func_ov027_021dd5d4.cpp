#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov027_021e3424 {
	unsigned char pad0[4];
	void* ptr;
};

extern Struct_ov027_021e3424 data_ov027_021e3424;

// USA: func_ov027_021dd5d4
extern "C" ARM void func_ov027_021dd5d4(void* obj) {
	data_ov027_021e3424.ptr = obj;
	VectorizedMemset(obj, 0, 0x21c);
}
