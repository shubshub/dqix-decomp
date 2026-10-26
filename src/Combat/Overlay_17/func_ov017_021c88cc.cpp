#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
struct Vector3i;

struct Struct_ov017_021c88cc {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Struct_ov017_021c88cc_2 {
	unsigned char pad0[4];
	int vec[3];
	short field10;
	unsigned short field12;
};

// USA: func_ov017_021c88cc
extern "C" ARM void func_ov017_021c88cc(int unused0, Struct_ov017_021c88cc_2* src, GameState* battleStruct, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	Struct_ov017_021c88cc* r = (Struct_ov017_021c88cc*)func_ov017_021b8478(h);
	if (!r) return;
	if (!func_ov017_021b8468(h)) return;
	if (!func_ov017_021b8470(h)) return;
	if (r->field8 != src->field12) return;
	GameObject* c = battleStruct->GetCombatantByIndex(src->field10);
	if (!c) return;
	int* dst = *(int**)((unsigned char*)c + 0x13c);
	if (!dst) return;
	*(Vector3i*)((int*)((unsigned char*)dst + 0x10)) = *(Vector3i const*)src->vec;
}
