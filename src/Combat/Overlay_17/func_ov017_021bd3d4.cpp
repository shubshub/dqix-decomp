#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;

// USA: func_ov017_021bd3d4
extern "C" ARM void func_ov017_021bd3d4(void* self, int index) {
#if defined(jpn)
 enum {regionalOffset0=0x170, regionalOffset1=0x171, regionalOffset2=0x184, regionalOffset3=0x1b4};
#else
 enum {regionalOffset0=0x174, regionalOffset1=0x175, regionalOffset2=0x188, regionalOffset3=0x1b8};
#endif
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	base[regionalOffset0] |= mask;
	base[regionalOffset1] &= ~mask;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(index);
	if (combatant) {
		*(Vector3i*)((int*)(base + regionalOffset2 + index * 0xc)) = *(Vector3i const*)(&combatant->obj3D_.position_.x);
		*(int*)(base + regionalOffset3 + index * 4) = combatant->obj3D_.rotation_.y;
	}
}
