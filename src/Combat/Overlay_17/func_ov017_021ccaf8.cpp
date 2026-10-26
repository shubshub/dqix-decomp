#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov017_021ccaf8 {
	unsigned short arr[6];
	unsigned short id;
	unsigned char idx;
};

// USA: func_ov017_021ccaf8
extern "C" ARM void func_ov017_021ccaf8(int unused0, char* arg1, GameState* bs) {
	struct Struct_ov017_021ccaf8* p1 = (struct Struct_ov017_021ccaf8*)(arg1 + 4);

	GameObject* c = func_0200ff1c(bs, p1->id);
	if (!c) return;

	int field150 = func_02053c6c((unsigned char*)c);
	if (!field150) return;

	unsigned char idx = p1->idx;
	for (unsigned char i = 0; i < 6; i++) {
		unsigned short v = p1->arr[i];
		short* dst = (short*)((char*)field150 + (i + idx) * 2 + 0x100 + 0x6c);
		*dst = v;
	}
}
