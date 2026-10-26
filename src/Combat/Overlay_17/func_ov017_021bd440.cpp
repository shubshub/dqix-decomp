#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;

// USA: func_ov017_021bd440
extern "C" ARM void func_ov017_021bd440(void* self, int arg1) {
	unsigned char* base = (unsigned char*)self;
	unsigned char var1 = 1 << arg1;
	int var2 = 0;
#if defined(jpn)
	if (base[0x170] & var1) var2 = 1;
	base[0x170] &= ~var1;
	base[0x171] |= var1;
#else
	if (base[0x174] & var1) var2 = 1;
	base[0x174] &= ~var1;
	base[0x175] |= var1;
#endif
	if (!var2) return;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(arg1);
	if (!combatant) return;
#if defined(jpn)
	*(Vector3i*)(&combatant->obj3D_.position_.x) = *(Vector3i const*)((int*)(base + 0x184 + arg1 * 0xc));
	int var4 = *(int*)(base + 0x1b4 + arg1 * 4);
#else
	*(Vector3i*)(&combatant->obj3D_.position_.x) = *(Vector3i const*)((int*)(base + 0x188 + arg1 * 0xc));
	int var4 = *(int*)(base + 0x1b8 + arg1 * 4);
#endif
	combatant->obj3D_.rotation_.x = 0;
	combatant->obj3D_.rotation_.y = var4;
	combatant->obj3D_.rotation_.z = 0;
}
