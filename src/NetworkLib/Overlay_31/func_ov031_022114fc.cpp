#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" long long func_ov031_02212d20(void);
extern "C" void func_ov031_02211754(struct Struct_ov031_022114fc_2* obj);
extern "C" void func_ov031_02211678(void* dst, int lo, int hi);

struct Struct_ov031_022114fc_2;

struct Struct_ov031_022114fc {
	int field0;
	char pad4[0xc];
	char pad10[0xc];
	int field1c;
	char pad20[4];
	int field24;
	int field28;
	int field2c;
};

// USA: func_ov031_022114fc
extern "C" ARM void func_ov031_022114fc(Struct_ov031_022114fc* obj, int b) {
	VectorizedMemset(obj, 0, 0x40);
	obj->field0 = 0x40;
	long long pair = func_ov031_02212d20();
	func_ov031_02211678((char*)obj + 4, (int)pair, (int)(pair >> 32));
	func_ov031_02211678((char*)obj + 0x10, 0, 0);
	obj->field1c = 0;
	obj->field24 = b;
	obj->field28 = 0x41435753;
	obj->field2c = 0x10000;
	func_ov031_02211754((struct Struct_ov031_022114fc_2*)obj);
}
