#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217726c_4100 = 0xf80 };
enum { kRegion103a = 0xfb6 };
enum { Enum_ov003_0217726c_4156 = 0xfb8 };
enum { kRegion874 = 0x7f0 };
enum { kRegion89c = 0x818 };
#else
enum { Enum_ov003_0217726c_4100 = 0x1004 };
enum { kRegion103a = 0x103a };
enum { Enum_ov003_0217726c_4156 = 0x103c };
enum { kRegion874 = 0x874 };
enum { kRegion89c = 0x89c };
#endif

#include "Combat/Main/BattleList.h"

struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" unsigned int func_ov003_02175898(char* obj, void* s);
struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_0217726c
extern "C" ARM void func_ov003_0217726c(char* obj) {
	int key = *(short*)(obj + kRegion103a);
	struct ItemTable* c = (struct ItemTable*)(obj + kRegion874);
	struct Struct_0207fdcc_2* o = *(struct Struct_0207fdcc_2**)(obj + kRegion89c);
	struct Element020de650* elem = ItemTable_Find(c, key);
	int mode = *(short*)(obj + Enum_ov003_0217726c_4100);
	int val = 0;
	int var6;
	if (mode != 4) {
		if (mode == 5) val = *(unsigned short*)((char*)elem + 0x1a);
	} else {
		val = func_ov003_02175898(obj, elem);
	}
	var6 = val * (*(unsigned char*)(obj + Enum_ov003_0217726c_4156));
	func_02080c20(o, 10);
	func_02080c68(o, 10, 0);
	func_02080fa8((struct Struct_02080fa8*)o, 0x5b, var6);
	func_020813ec(o, 10);
}
