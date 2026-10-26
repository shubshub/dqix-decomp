#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" void func_0200fd38(GameState* battleStruct, int id, GameObject* combatant);

struct Struct_ov001_02160c78 {
	unsigned char pad[0xd4];
	unsigned char unknown_d4_0_ : 1;
};

// USA: func_ov001_02160c78
extern "C" ARM int func_ov001_02160c78(char* self) {
	GameState* bs = GameState::GetInstance();
	void* global = func_0203cf4c();
	int var2 = func_ov017_021d60f4(self);
	int id2 = func_ov001_0215ad2c(func_ov017_021d60f4(self + 0x8));
	if (id2 < 0xa0 || id2 > 0xbf) return 0;
	void* entry = func_0203df78(global, var2);
	if (entry == 0) return 0;
	struct Struct_ov001_02160c78* combatant = *(struct Struct_ov001_02160c78**)((char*)entry + 0x18);
	if (combatant == 0) return 0;
	combatant->unknown_d4_0_ = 1;
	func_0200fd38(bs, id2, *(GameObject**)((char*)entry + 0x18));
	return 1;
}
