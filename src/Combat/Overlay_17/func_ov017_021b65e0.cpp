#if defined(jpn)
enum { Enum_ov017_021b65e0_2816 = 0x8e0, RegionOffset6fc = 0x4ec };
#else
enum { Enum_ov017_021b65e0_2816 = 0xb00, RegionOffset6fc = 0x6fc };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* state);
struct SearchStruct;
extern "C" int LinkSession_IsSlotConnected(struct SearchStruct* obj, int value);

struct Struct_ov017_021b65e0;
extern "C" void func_ov017_021b6790(Struct_ov017_021b65e0* self);

struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021b65e0
extern "C" ARM void func_ov017_021b65e0(unsigned char* obj, int arg1) {
	GameState* bs = GameState::GetInstance();
	void* search = LinkSession_GetInstance();
	bool ok = true;
	if (arg1 == 0 && LinkSession_IsActive((int*)search) && LinkSession_IsHostOrSolo(search) != 0) {
		for (int i = 0; i < 4; i++) {
			if (LinkSession_IsSlotConnected((struct SearchStruct*)search, i)) {
				if (bs->GetGameObjectByIndex(i) == NULL) {
					ok = false;
				}
			}
		}
	}
	if (!ok) {
		return;
	}
	func_ov017_021b6790(*(Struct_ov017_021b65e0**)(obj + 0x3000 + Enum_ov017_021b65e0_2816));
	*(unsigned char*)((char*)(*(Struct_ov017_021b65e0**)(obj + 0x3000 + Enum_ov017_021b65e0_2816)) + 0x1c) = arg1;
	func_020469b4(*(struct TailList020469b4**)(obj + 0x3000 + RegionOffset6fc), (struct TailNode020469b4*)(*(Struct_ov017_021b65e0**)(obj + 0x3000 + Enum_ov017_021b65e0_2816)));
	search = LinkSession_GetInstance();
	if (LinkSession_IsHostOrSolo(search) == 0) {
		return;
	}
	if (arg1 == 0) {
		*(unsigned char*)((char*)search + 0x1000 + 0x11) = 0;
	}
}
