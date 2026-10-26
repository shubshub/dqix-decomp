#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02053f7c_3;
extern "C" void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b);

// USA: func_ov017_02192594
extern "C" ARM void func_ov017_02192594(unsigned char* base) {
	GameState* bs = GameState::GetInstance();
	int i;
	for (i = 0; i < 4; i++) {
		GameObject* c = bs->GetPartyMemberByIndex(i);
		if (c) {
			func_02053f7c((struct Struct_02053f7c_3*)c, 0, 1);
		}
	}
}
