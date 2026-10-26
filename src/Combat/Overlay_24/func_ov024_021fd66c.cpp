#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_021fa76c;
extern "C" int func_ov024_021fa76c(struct Struct_021fa76c* combatant);
extern "C" int func_0208824c(unsigned char* obj);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" int func_ov000_02156068(void* obj, int id, int a2, int a3);
extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

struct Struct_ov024_021fd66c_2 { unsigned int code : 12; };
struct Struct_ov024_021fd66c_3 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd66c_4 {
	char pad0[4];
	struct Struct_ov024_021fd66c_2 unknown_4_;
	char pad8[0x14 - 8];
	struct Struct_ov024_021fd66c_3 unknown_14_;
};

struct Struct_ov024_021fd66c_5 {
	char pad[0xa];
	unsigned short unknown_a_0_ : 7;
	unsigned short nibble : 4;
	unsigned short bit11 : 1;
	unsigned short unknown_b_4_ : 1;
	unsigned short rest : 3;
};

struct Struct_ov024_021fd66c {
	void* field0;
	char pad4[0x2c - 4];
	unsigned char unknown_2c_;
	char unknown_2d_[0x64c - 0x2d];
	struct Struct_ov024_021fd66c_4* unknown_64c_;
	char unknown_650_[0x668 - 0x650];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd66c
extern "C" ARM void func_ov024_021fd66c(struct Struct_ov024_021fd66c* obj) {
	GameObject* c = obj->unknown_668_;
	if (!func_ov024_021fa76c((struct Struct_021fa76c*)c)) return;
	if (!func_0208824c((unsigned char*)c->currentStats_)) return;
	if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) return;
	struct Struct_ov024_021fd66c_4* state = obj->unknown_64c_;
	float var2 = (float)state->unknown_14_.val;
	unsigned char var3 = *(unsigned char*)((char*)c->currentStats_ + 0x4e);
	float var4 = var2 * ((float)var3 / 100.0f);
	unsigned int code = state->unknown_4_.code;
	if (code == 0x58) {
		if (c->obj3D_.unknown_0_ & 0x400) {
			struct Struct_ov024_021fd66c_5* inner = *(struct Struct_ov024_021fd66c_5**)((char*)c + 0x144);
			if (inner != NULL && inner->unknown_b_4_) {
				obj->unknown_2c_ = 1;
				var4 = 50.0f;
			}
		}
	} else if (code == 0x52) {
		if (!func_ov000_02156068(obj->field0, c->obj3D_.actorIndex_, 9, 0)) return;
	}
	if (var4 > 100.0f) var4 = 100.0f;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 1);
	func_ov024_021fd088(obj, var4, 3);
}
