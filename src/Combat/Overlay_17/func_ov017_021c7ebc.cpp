#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c7ebc {
	unsigned char pad0[8];
	unsigned short field8;
	unsigned char pad1[0x20];
	signed char field2a;
};

struct Struct_ov017_021c7ebc_2 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned short field6;
	unsigned int v1;
	unsigned int v2;
	unsigned char selector;
};

struct Struct_ov017_021c7ebc_3 {
	unsigned int s0:3, s1:3, s2:3, s3:3, unknown_1_4_:3, unknown_1_7_:3, unknown_2_2_:3, unknown_2_5_:3, unknown_3_0_:3, unknown_3_3_:3;
};

struct Struct_ov017_021c7ebc_4 {
	unsigned int s0:3, s1:3, s2:3, s3:3, unknown_1_4_:4;
};

struct Struct_ov017_021c7ebc_5 {
	unsigned char levels[15];
};

// USA: func_ov017_021c7ebc
extern "C" ARM void func_ov017_021c7ebc(int unused0, Struct_ov017_021c7ebc_2* src, GameState* battleStruct, unsigned char* arg3) {
	unsigned char* base = arg3 + 0x3000;
#if defined(jpn)
	void* h = *(void**)(base + 0x508);
#else
	void* h = *(void**)(base + 0x718);
#endif
	Struct_ov017_021c7ebc* r = (Struct_ov017_021c7ebc*)func_ov017_021b8478(h);
	if (!r) return;
	if (!func_ov017_021b8468(h)) return;
	if (!func_ov017_021b8470(h)) return;
	int val = GameState_GetProtagonistIndex(battleStruct);
	if (r->field2a == val) return;
	if (r->field8 != src->field4) return;
	GameObject* c = battleStruct->GetCombatantByIndex(src->field6);
	if (!c) return;
	Struct_ov017_021c7ebc_3* low = (Struct_ov017_021c7ebc_3*)&src->v1;
	Struct_ov017_021c7ebc_4* high = (Struct_ov017_021c7ebc_4*)&src->v2;
	if (src->selector == 1) {
#if defined(jpn)
		Struct_ov017_021c7ebc_5* out = (Struct_ov017_021c7ebc_5*)((unsigned char*)(c->currentStats_) + 0x70);
#else
		Struct_ov017_021c7ebc_5* out = (Struct_ov017_021c7ebc_5*)((unsigned char*)c->currentStats_ + 0x70);
#endif
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->unknown_1_4_;
		out->levels[5] = low->unknown_1_7_;
		out->levels[6] = low->unknown_2_2_;
		out->levels[7] = low->unknown_2_5_;
		out->levels[8] = low->unknown_3_0_;
		out->levels[9] = low->unknown_3_3_;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->unknown_1_4_;
	} else {
#if defined(jpn)
		Struct_ov017_021c7ebc_5* out = (Struct_ov017_021c7ebc_5*)((unsigned char*)(c->currentStats_) + 0x93);
#else
		Struct_ov017_021c7ebc_5* out = (Struct_ov017_021c7ebc_5*)((unsigned char*)c->currentStats_ + 0x93);
#endif
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->unknown_1_4_;
		out->levels[5] = low->unknown_1_7_;
		out->levels[6] = low->unknown_2_2_;
		out->levels[7] = low->unknown_2_5_;
		out->levels[8] = low->unknown_3_0_;
		out->levels[9] = low->unknown_3_3_;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->unknown_1_4_;
	}
}
