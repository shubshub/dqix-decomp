#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_ov031_02203164(int v);
extern "C" void func_ov031_02203178(void);
extern "C" int func_ov031_02204c84(int a);

struct Struct_ov031_02206e0c {
	char pad[0x18];
	void* (*alloc)(int size);
	void (*unknown_1c_)(void* p);
};
extern Struct_ov031_02206e0c* data_ov031_022496a4;

// USA: func_ov031_02206e0c
extern "C" ARM int func_ov031_02206e0c(int a) {
	char buf[0x64];
	if (a == 0) return 0;

	void* p = data_ov031_022496a4->alloc(0xfd0);
	if (p == 0) return 0;

	VectorizedMemset(buf, 0, 0x64);
	char* var2 = (char*)p + 0x368;
	char* var3 = var2 + 0x800;
	*(int*)(buf + 0x40) = (int)p;
	*(int*)(buf + 0x3c) = 0xb68;
	*(int*)(buf + 0x4c) = (int)var3;
	*(int*)(buf + 0x48) = 0x466;
	func_ov031_02203164((int)buf);

	int result = func_ov031_02204c84(a);
	func_ov031_02203178();
	data_ov031_022496a4->unknown_1c_(p);
	return result;
}
