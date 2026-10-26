#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_02203164(int v);

// USA: func_ov031_02217f44
extern "C" ARM void func_ov031_02217f44(void* self) {
	char* base = (char*)self;
	VectorizedMemset(base + 0x1138, 0, 0x64);
	*(int*)(base + 0x1000 + 0x174) = 0xb68;
	*(int*)(base + 0x1000 + 0x178) = *(int*)(base + 0x1000 + 0x9cc);
	*(int*)(base + 0x1000 + 0x180) = 0x5ea;
	*(int*)(base + 0x1000 + 0x184) = *(int*)(base + 0x1000 + 0x9d0);
	func_ov031_02203164((int)(base + 0x1138));
}
