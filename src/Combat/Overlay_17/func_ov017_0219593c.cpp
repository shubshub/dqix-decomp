#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021b8d1c(void*);
struct Struct_0206528c;
extern "C" struct Struct_0206528c_2* func_0206528c(struct Struct_0206528c* list, int key);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203cff4(void* obj);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_0219593c {
	char pad[0x114];
	void* unknown_114_;
	char pad2[0x124 - 0x118];
	int field124;
};

struct S021b6b8c { unsigned char pad[0x24]; void* f24; };
extern "C" void func_ov017_021b6b8c(S021b6b8c* obj);

// USA: func_ov017_0219593c
extern "C" ARM void func_ov017_0219593c(void) {
#if defined(jpn)
 enum {regionalOffset0=0x500, regionalOffset1=0x4ec, regionalOffset2=0x8e0};
#else
 enum {regionalOffset0=0x710, regionalOffset1=0x6fc, regionalOffset2=0xb00};
#endif
	char* base = (char*)(int)GetGameResources();
	struct Struct_ov017_0219593c* node = *(struct Struct_ov017_0219593c**)(base + 0x3000 + regionalOffset0);
	unsigned char* flagObj;

	void* ptr = func_0203cff4(func_0203cf4c());
	func_ov017_021b8d1c(node);
	node->unknown_114_ = func_0206528c((struct Struct_0206528c*)ptr, 0x63);
	node->field124 = 0xd7;
	if (node->unknown_114_ != 0) {
		func_020469b4(*(struct TailList020469b4**)(base + 0x3000 + regionalOffset1), (struct TailNode020469b4*)node);
	}
	flagObj = *(unsigned char**)(base + 0x3000 + regionalOffset2);
	if (flagObj[2] == 0) return;
	func_ov017_021b6b8c((S021b6b8c*)flagObj);
}
