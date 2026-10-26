#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);
extern "C" void func_ov024_021fd104(void* obj, int mode);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

struct Struct_ov024_021fd504 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd504_2 { char pad[0x14]; struct Struct_ov024_021fd504 bits; char pad2[0x1a]; short field32; };

struct Struct_ov024_021fd504_3 {
	char pad0[0x64c];
	struct Struct_ov024_021fd504_2* unknown_64c_;
	char pad2[0x661 - 0x64c - 4];
	unsigned char unknown_661_;
	char pad3[0x668 - 0x661 - 1];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd504
extern "C" ARM void func_ov024_021fd504(struct Struct_ov024_021fd504_3* obj) {
	struct ModifiableCombatStats* stats = obj->unknown_668_->currentStats_;
	if (stats->defenseBuff <= -2) return;
	unsigned char var1 = *(unsigned char*)((char*)stats + 0x50);
	if (var1 == 0) return;
	if (obj->unknown_661_) {
		struct Struct_ov024_021fd504_2* state = obj->unknown_64c_;
		float var3 = (float)state->bits.val;
		float var4 = var3 * ((float)var1 / 100.0f);
		if (var4 > 100.0f) var4 = 100.0f;
		if (state->field32 >= 0) return;
		func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 0xd);
		func_ov024_021fd088(obj, var4, 0x12);
	} else {
		func_ov024_021fd104(obj, 0x12);
	}
}
