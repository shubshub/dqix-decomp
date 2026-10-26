#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"


extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int a, unsigned char* b, int c);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_020103c8(int val, int arg);
struct Struct_ov017_0218d0ec_4;

struct Struct_ov017_021c51c0 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned short field6;
	unsigned short field8;
	int fieldc;
	unsigned short field10;
	unsigned short field12;
};

// USA: func_ov017_021c51c0
extern "C" ARM void func_ov017_021c51c0(int flag, Struct_ov017_021c51c0* evt, GameState* battleStruct, unsigned char* obj, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset=0x4fc};
#else
 enum {regionalOffset=0x70c};
#endif
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + regionalOffset);
	void* ctx = GameState_GetZoneTransition(battleStruct);
	signed char cur = LinkSession_GetOwnSlot(search);
	if (evt->field4 != cur) return;

	*(unsigned char*)((char*)h + 0xb) = 1;

	if (evt->field5 == 1) {
		void* work = Scenario_GetInstance();
		if (Scenario_TestFlag((int)work, (unsigned char*)work + 0x8c, evt->field8 + 0x38e) == 0) {
			*(int*)((char*)ctx + 0x24) = evt->field6;
		}
	} else if (evt->field5 == 2) {
		*(int*)((char*)ctx + 0x28) = evt->field6;
		*(int*)((char*)ctx + 0x2c) = evt->field8;
	}

	if (LinkSession_IsGuest(search) != 0 && flag == 0) {
		func_020103c8((int)battleStruct, evt->fieldc);
		LightingManager::GetInstance();
	}

	*(unsigned short*)((char*)h + 0xe) = evt->field10;
	*(unsigned short*)((char*)h + 0x10) = evt->field12;
}
