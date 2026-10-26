#include <globaldefs.h>
#include "GameState/GameState.h"

struct S02037418;
extern "C" void func_02039d48(unsigned char* obj);

struct Struct_ov017_021d2c78 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
};

// USA: func_ov017_021d2c78
extern "C" ARM void func_ov017_021d2c78(void* unused, Struct_ov017_021d2c78* src) {
	GameState* bs = GameState::GetInstance();
	GameObject* c = bs->GetPartyMemberByIndex(src->field4);
	if (c == NULL) return;

	((Object3D*)((struct S02037418*)c))->SetInheritedAlpha(src->field5);
	if (src->field5 != 0) return;
	if (src->field6 == 0) return;

	func_02039d48((unsigned char*)c);
}
