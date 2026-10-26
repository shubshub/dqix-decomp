#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021b0fe0_1788 = 0x4ec, Enum_ov017_021b0fe0_1816 = 0x508, Enum_ov017_021b0fe0_1096 = 0x488 };
#else
enum { Enum_ov017_021b0fe0_1788 = 0x6fc, Enum_ov017_021b0fe0_1816 = 0x718, Enum_ov017_021b0fe0_1096 = 0x448 };
#endif

extern "C" void func_ov017_021c45b4(int combatantId);
extern "C" void func_ov017_021cc97c(int id);
extern "C" void func_ov017_021cee78(int id, unsigned char b);
extern "C" void func_ov017_021ce32c(int id);

extern "C" void func_ov017_021c41fc(int id, int a);
extern "C" void func_ov017_021c4418(int id, int a);
extern "C" void func_ov017_021c3fb4(int id, int a);
extern "C" void func_ov017_021ce704(int id);
extern "C" void func_ov017_021cf078(int id, unsigned char b, int c);
extern "C" void func_ov017_021cc730(int id, int a, int b, int c);
extern "C" void func_ov017_021cca5c(int id, int a);
extern "C" void func_ov017_021ccb58(int id, int a);
extern "C" void func_ov017_021ccc34(int id);
extern "C" void func_ov017_021ccdac(int id);
extern "C" void func_ov017_021ccfd0(int id);
extern "C" void func_ov017_021cff8c(int id, int a);
extern "C" void func_ov017_021d0e00(int id);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021d25f4(int id);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_0217616c(void* p);

extern "C" void* func_ov000_02160f08(void* obj);

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);

struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);

// USA: func_ov017_021b0fe0
extern "C" ARM void func_ov017_021b0fe0(int id) {
	func_ov017_021c41fc(id, -1);
	func_ov017_021c45b4(id);
	func_ov017_021c4418(id, -1);
	func_ov017_021c3fb4(id, 0);
	func_ov017_021ce704(id);

	for (int i = 0; i < 0xd; i++) {
		func_ov017_021cf078(id, (unsigned char)i, 0);
	}

	func_ov017_021cc730(id, 1, 1, 1);
	func_ov017_021cc97c(id);
	func_ov017_021cca5c(id, 0);
	func_ov017_021cca5c(id, 1);
	func_ov017_021ccb58(id, 1);
	func_ov017_021ccb58(id, 4);
	func_ov017_021ccb58(id, 7);
	func_ov017_021ccb58(id, 0xa);
	func_ov017_021ccc34(id);
	func_ov017_021ccdac(id);
	func_ov017_021ccfd0(id);
	func_ov017_021cff8c(id, 1);
	func_ov017_021ce32c(id);
	func_ov017_021cee78(id, 0);
	func_ov017_021d0e00(id);
	func_ov017_021c9e00(id, 1, 0, 1);
	func_ov017_021d25f4(id & 0xff);

	if (!func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), id)) {
		return;
	}

	int base = ((int)GetGameResources());
	struct ListHead02046b60* listA = *(struct ListHead02046b60**)((char*)base + 0x3000 + Enum_ov017_021b0fe0_1788);
	if (!func_02046b60(listA, 0xa)) {
		return;
	}

	void* var3 = *(void**)((char*)base + 0x3000 + Enum_ov017_021b0fe0_1816);
	void* p = func_ov017_021b8468(var3);
	void* result = func_ov000_02160f08(p);

	int flag = (id >= 0 && id <= 3) ? 1 : 0;

	if (flag) {
		for (int slot = 0; slot < 4; slot++) {
			int off = slot * Enum_ov017_021b0fe0_1096;
			int val = *(int*)((char*)result + off + 0x9a4);
			if (id == val) {
				result = (char*)result + 0x958 + off;
				goto lookupDone;
			}
		}
	}
	result = 0;
lookupDone:
	func_ov000_0217616c(result);
}
