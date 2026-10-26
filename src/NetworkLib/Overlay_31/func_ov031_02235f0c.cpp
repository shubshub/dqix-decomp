#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02290cfc_2 { unsigned char* field0; };
extern struct Struct_ov031_02290cfc_2 data_ov031_02290cfc;

// USA: func_ov031_02235f0c
extern "C" ARM void func_ov031_02235f0c(void* src) {
	VectorizedInvertedMemcpy(data_ov031_02290cfc.field0 + 0x440, src, 0x20);
}
