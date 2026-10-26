#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_020e2ff8(void);
extern "C" void* func_020e3580(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_0202c778(unsigned char* obj);
extern "C" int func_0202b800(int* p);
extern "C" void LinkMessageQueue_Reset(void* p);
struct Struct_020e3004;
extern "C" void func_020e3004(struct Struct_020e3004* p);
struct Struct_020e358c;
extern "C" void func_020e358c(struct Struct_020e358c* s);
extern "C" void func_ov017_02195748(unsigned char* base);
extern "C" void GameState_CollectPartyObjectIndices(GameState* bs, int* outList, int* outCount);
extern "C" void __clear(void* buf, int len);
extern "C" int STD_GetStringLength(const char* s);
extern "C" void func_0202c360(void* obj, char* name);
extern "C" void func_ov017_021972cc(char* p);
extern "C" void func_ov017_02195520(void* obj);

// USA: func_ov017_021c36a0
extern "C" ARM void func_ov017_021c36a0(void) {
	GameState* bs = GameState::GetInstance();
	void* objA = (void*)(int)((int)GetGameResources());
	void* objB = LinkSession_GetInstance();
	GameObject* combatant = bs->GetProtagonist();
	void* d100044 = LinkMessageQueue_GetInstance();
	void* var5 = func_020e2ff8();
	void* var6 = func_020e3580();

	if (func_0202b000(objB) != 0) {
		func_ov017_021c37a4();
		return;
	}

#if !defined(jpn)
	func_0202c778((unsigned char*)objB);
#endif
	func_0202b800((int*)objB);
	LinkMessageQueue_Reset(d100044);
	func_020e3004((struct Struct_020e3004*)var5);
	func_020e358c((struct Struct_020e358c*)var6);
	func_ov017_02195748((unsigned char*)objA);

	int list[4];
	int count;
	GameState_CollectPartyObjectIndices(bs, list, &count);

	char buf[20];
	__clear(buf, 0x14);

	int len = STD_GetStringLength(*(char**)((char*)combatant + 0x134));
	if (len > 0x14) {
		len = 0x14;
	}
	memcpy(buf, *(char**)((char*)combatant + 0x134), len);
	buf[len] = 0;
	buf[0x13] = (char)count;

	func_0202c360(objB, *(char**)((char*)combatant + 0x134));
	func_ov017_021972cc((char*)objA);
	func_ov017_02195520(objA);
}
