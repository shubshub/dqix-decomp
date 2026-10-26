#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021cc320 { unsigned char pad0[4]; unsigned char combatantId; };
struct Struct_020535f4 { char pad[0x184]; unsigned char counter; };
extern "C" void func_020535f4(struct Struct_020535f4* p);

// USA: func_ov017_021cc320
extern "C" ARM void func_ov017_021cc320(void* unused0, Struct_ov017_021cc320* src, GameState* battleStruct) {
	GameObject* c = func_0200ff1c(battleStruct, src->combatantId);
	if (c != 0) {
		func_020535f4((struct Struct_020535f4*)c);
	}
}
