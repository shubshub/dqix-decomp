#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
extern "C" int func_ov017_0218db14(void* obj, int* vec, int c, int d, unsigned char e);

// USA: func_ov017_0218daa8
ARM int GetDeltaAndForward_0218daa8(void* obj, struct Vec3* otherVec, int c, int d, unsigned char e) {
	struct Vec3 diff;
	GameObject* combatant = GameState::GetInstance()->GetLeader();
	if (!otherVec) return 0;
	if (!combatant) return 0;
	Vector3fix_Subtract((const Vector3fix*)((struct Vec3*)((char*)combatant + 0x44)), (const Vector3fix*)otherVec, (Vector3fix*)&diff);
	return func_ov017_0218db14(obj, (int*)&diff, c, d, e);
}
