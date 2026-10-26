#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_021fa76c;
extern "C" int func_ov024_021fa76c(struct Struct_021fa76c* combatant);

struct Struct_02088418;
extern "C" int func_02088418(struct Struct_02088418* c, int index, int arg2);

struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);

struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);

struct Struct_ov024_021fd1bc_2 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd1bc_3 {
	char pad0[4];
	unsigned int unknown_4_0_ : 12;
	char pad1[0x14 - 8];
	struct Struct_ov024_021fd1bc_2 bits;
	char pad2[0x30 - 0x18];
	short unknown_30_;
	short field32;
};

struct Struct_ov024_021fd1bc_4 {
	char pad[0xa];
	unsigned short : 11;
	unsigned short flag11 : 1;
	unsigned short : 4;
};

struct Struct_ov024_021fd1bc_5 {
	char pad0[0x64c];
	struct Struct_ov024_021fd1bc_3* unknown_64c_;
	char pad2[0x668 - 0x64c - 4];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd1bc
extern "C" ARM void func_ov024_021fd1bc(struct Struct_ov024_021fd1bc_5* obj) {
	GameObject* c = obj->unknown_668_;
	if (!func_ov024_021fa76c((struct Struct_021fa76c*)c)) return;
	struct Struct_ov024_021fd1bc_3* state = obj->unknown_64c_;
	int index = state->field32 & 0xff;
	unsigned short var3 = state->unknown_4_0_;
	if (!func_02088418((struct Struct_02088418*)c->currentStats_, index, var3)) return;
	if (func_ov024_021da9c8((struct Struct_ov024_021da670_8*)c)) return;
	state = obj->unknown_64c_;
	if (state->unknown_30_ == 2 && (c->obj3D_.unknown_0_ & 0x400)) {
		struct Struct_ov024_021fd1bc_4* p = *(struct Struct_ov024_021fd1bc_4**)((char*)c + 0x144);
		if (p && p->flag11) return;
	}
	float var5 = (float)state->bits.val;
	unsigned char var6 = *(unsigned char*)((char*)c->currentStats_ + 0x4c);
	float var7 = var5 * ((float)var6 / 100.0f);
	if (var7 > 100.0f) var7 = 100.0f;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 1);
	func_ov024_021fd088(obj, var7, 8);
}
