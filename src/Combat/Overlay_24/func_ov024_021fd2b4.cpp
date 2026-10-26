#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

struct Struct_ov024_021fd2b4 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd2b4_2 { char pad[0x14]; struct Struct_ov024_021fd2b4 bits; char pad2[0x1a]; short field32; };

struct Struct_ov024_021fd2b4_3 {
	char pad0[0x64c];
	struct Struct_ov024_021fd2b4_2* unknown_64c_;
	char pad2[0x668 - 0x64c - 4];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd2b4
extern "C" ARM void func_ov024_021fd2b4(struct Struct_ov024_021fd2b4_3* obj) {
	struct ModifiableCombatStats* stats = obj->unknown_668_->currentStats_;
	if (stats->attackBuff <= -2) return;
	short field32;
	unsigned char var2 = *(unsigned char*)((char*)stats + 0x4f);
	if (var2 == 0) return;
	struct Struct_ov024_021fd2b4_2* state = obj->unknown_64c_;
	field32 = state->field32;
	float var4 = (float)state->bits.val;
	float var5 = var4 * ((float)var2 / 100.0f);
	if (var5 > 100.0f) var5 = 100.0f;
	if (field32 >= 0) return;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 0xd);
	func_ov024_021fd088(obj, var5, 0x11);
}
