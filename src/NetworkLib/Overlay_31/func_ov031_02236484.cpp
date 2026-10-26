#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern char* data_ov031_02290cfc;
extern "C" void func_ov031_02236570(int id);

// USA: func_ov031_02236484
extern "C" ARM void func_ov031_02236484(int id) {
	unsigned char* base = (unsigned char*)data_ov031_02290cfc + (id << 8);
	VectorizedMemset(base, 0, 0xef);
	base[0xe7] = 0xff;
	func_ov031_02236570(id);
}
