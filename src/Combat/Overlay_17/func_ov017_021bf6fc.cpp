#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02033710;
struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);
struct Struct_02028460_3 { int x; int y; int z; };

// USA: func_ov017_021bf6fc
extern "C" ARM int func_ov017_021bf6fc(unsigned char* obj) {
	GameState* battle = GameState::GetInstance();
	GameObject* combatant = battle->GetLeader();
	unsigned char* target = *(unsigned char**)(obj + 0xc);
	struct Struct_02028460_3 pos = *(struct Struct_02028460_3*)((char*)combatant + 0x44);
	struct Struct_02028460_3 var4;
	var4.x = *(int*)(target + 0x8);
	var4.y = pos.y;
	var4.z = *(int*)(target + 0x10);
	int dist = Vector3fix_Distance((const Vector3fix*)&pos, (const Vector3fix*)&var4);
	*(short*)(obj + 0x14) -= 1;
	if (dist < 0x199 || (*(short*)(obj + 0x14) < 0 && !((Object3D*)((struct Struct_02033710*)combatant))->IsTransitioningAnimations())) {
		GameObject_SetMotionState((struct Obj02033b68*)combatant, 0);
		*(short*)(obj + 0x14) = -1;
		return 2;
	}
	return 1;
}
