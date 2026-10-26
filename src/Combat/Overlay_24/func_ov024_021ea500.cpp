#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021ea500_2 { char pad[0x4]; unsigned int kind : 12; };
struct Struct_ov024_021ea500 { unsigned int bit0 : 1; unsigned int unknown_0_1_ : 1; };

// USA: func_ov024_021ea500
extern "C" ARM int func_ov024_021ea500(void* unused, struct Struct_ov024_021ea500_2* obj, int id) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
	GameState* bs = GameState::GetInstance();
	if (obj->kind == 1) {
		int inRange = (id >= 0 && id <= 3);
		if (inRange) {
			GameObject* combatant = func_0200ff1c(bs, id);
			char* p = (char*)(*(int**)((char*)combatant + regionalOffset0)) + 0x2f4;
			if (p) {
				struct Struct_ov024_021ea500* flags = (struct Struct_ov024_021ea500*)p;
				if (flags->unknown_0_1_ || flags->bit0) {
					return 1;
				}
			}
		}
	}
	return 0;
}
