#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c840c {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
	unsigned char pad1;
	int field8;
};

struct Struct_ov017_021c840c_2 {
	unsigned char pad0[5];
	unsigned char field5;
	unsigned char pad1[2];
	unsigned short field8;
	unsigned char pad2[0x20];
	signed char field2a;
};

// USA: func_ov017_021c840c
extern "C" ARM void func_ov017_021c840c(int unused0, Struct_ov017_021c840c* src, GameState* battleStruct, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	Struct_ov017_021c840c_2* r = (Struct_ov017_021c840c_2*)func_ov017_021b8478(h);
	if (!r) return;
	void* work = func_ov017_021b8470(h);
	if (!work) return;
	int val = GameState_GetProtagonistIndex(battleStruct);
	if (r->field2a == val) return;
	if (r->field8 == src->field4) {
		*(int*)((unsigned char*)work + 0x8000 + 0xe20) = src->field8;
		r->field5 = src->field6;
	}
}
