#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_02156b38(int a0, int id, unsigned int idx);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

struct Struct_ov024_021f875c { unsigned short flags; unsigned short pad2; short id; };
struct Struct_ov024_021f875c_2 { char pad0[0x8]; int field8; char pad1[0x4]; int field10; char pad2[0x4]; int field18; };
struct Struct_ov024_021f875c_3 { char pad[0xa]; unsigned short unknown_a_0_ : 12; unsigned short unknown_b_4_ : 1; };

// USA: func_ov024_021f875c
extern "C" ARM int func_ov024_021f875c(int* arg0, struct Struct_ov024_021f875c* arg1, struct Struct_ov024_021f875c_2* obj2, int arg3) {
	GameState* bs = GameState::GetInstance();
	if (arg1->flags & 0x400) {
		GameObject* c = func_0200fea4(bs, arg1->id);
		if (c && *(void**)((char*)c + 0x144)) {
			struct Struct_ov024_021f875c_3* inner = *(struct Struct_ov024_021f875c_3**)((char*)c + 0x144);
			if (inner->unknown_b_4_) {
				if (!(obj2->field10 & 0x1000000)) {
					return 0;
				}
			}
		}
	}
	unsigned int idx;
	if (arg3 == 1) {
		idx = (unsigned int)obj2->field18 >> 27;
	} else {
		idx = (unsigned int)(obj2->field8 << 5) >> 27;
	}
	return func_ov000_02156b38(*arg0, arg1->id, idx);
}
