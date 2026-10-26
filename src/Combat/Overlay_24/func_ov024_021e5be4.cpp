#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215fd24(int unused, int id);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);

struct Struct_ov024_021e5be4 { char pad[0x10]; void* unknown_10_; };
struct Struct_ov024_021e5be4_2 { char pad[0x32]; short unknown_32_; };

// USA: func_ov024_021e5be4
extern "C" ARM void func_ov024_021e5be4(struct Struct_ov024_021e5be4* obj, int id, struct Struct_ov024_021e5be4_2* p2, int arg3) {
	GameState* bs = GameState::GetInstance();
	void* field2a04 = GameState_GetParty(bs);
	if (func_ov000_0215fd24((int)obj->unknown_10_, id)) {
		*(int*)((char*)field2a04 + 0xf6c) -= p2->unknown_32_;
		return;
	}
	int base;
	int* arr;
	int idx;
	if (func_0200ff58(bs, id) != 0) {
		idx = 0;
		base = *(int*)((char*)obj->unknown_10_ + 0x8000 + 0xe84);
		arr = (int*)((char*)obj->unknown_10_ + 0x284 + 0x8c00);
	} else {
		arr = (int*)((char*)obj->unknown_10_ + 0x284 + 0x8c00);
		base = arr[id];
		idx = id;
	}
	arr[(short)idx] = base - p2->unknown_32_;
}
