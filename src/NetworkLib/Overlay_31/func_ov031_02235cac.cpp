#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02290cfc { unsigned char* field0; };
extern struct Struct_ov031_02290cfc data_ov031_02290cfc;

// USA: func_ov031_02235cac
extern "C" ARM void func_ov031_02235cac(void* p) {
	VectorizedInvertedMemcpy(p, data_ov031_02290cfc.field0 + 0x440, 0x20);
	data_ov031_02290cfc.field0[0x4e7] = 0;
}
