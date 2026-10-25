#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_021fa76c;
extern "C" int func_ov024_021fa76c(struct Struct_021fa76c* arg0);
extern "C" int func_0208824c(unsigned char* arg0);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* arg0);
extern "C" int func_ov000_02156068(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov024_021fd088(void* arg0, float arg1, int arg2);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* arg0, int arg1);

struct Struct_ov024_021fd66c_2 { unsigned int unknown_0_0_ : 12; };
struct Struct_ov024_021fd66c_3 { unsigned int unknown_0_0_ : 7; unsigned int unknown_0_7_ : 7; };
struct Struct_ov024_021fd66c_4 {
	char unknown_0_[4];
	struct Struct_ov024_021fd66c_2 unknown_4_;
	char unknown_8_[0x14 - 8];
	struct Struct_ov024_021fd66c_3 unknown_14_;
};

struct Struct_ov024_021fd66c_5 {
	char unknown_0_[0xa];
	unsigned short unknown_a_0_ : 7;
	unsigned short unknown_a_7_ : 4;
	unsigned short unknown_b_3_ : 1;
	unsigned short unknown_b_4_ : 1;
	unsigned short unknown_b_5_ : 3;
};

struct Struct_ov024_021fd66c {
	void* unknown_0_;
	char unknown_4_[0x2c - 4];
	unsigned char unknown_2c_;
	char unknown_2d_[0x64c - 0x2d];
	struct Struct_ov024_021fd66c_4* unknown_64c_;
	char unknown_650_[0x668 - 0x650];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd66c
extern "C" ARM void func_ov024_021fd66c(struct Struct_ov024_021fd66c* arg0) {
	GameObject* var0 = arg0->unknown_668_;
	if (!func_ov024_021fa76c((struct Struct_021fa76c*)var0)) return;
	if (!func_0208824c((unsigned char*)var0->currentStats_)) return;
	if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)var0)) return;
	struct Struct_ov024_021fd66c_4* var1 = arg0->unknown_64c_;
	float var2 = (float)var1->unknown_14_.unknown_0_7_;
	unsigned char var3 = *(unsigned char*)((char*)var0->currentStats_ + 0x4e);
	float var4 = var2 * ((float)var3 / 100.0f);
	unsigned int var5 = var1->unknown_4_.unknown_0_0_;
	if (var5 == 0x58) {
		if (var0->obj3D_.unknown_0_ & 0x400) {
			struct Struct_ov024_021fd66c_5* var6 = *(struct Struct_ov024_021fd66c_5**)((char*)var0 + 0x144);
			if (var6 != NULL && var6->unknown_b_4_) {
				arg0->unknown_2c_ = 1;
				var4 = 50.0f;
			}
		}
	} else if (code == 0x52) {
		if (!func_ov000_02156068(obj->field0, c->obj3D_.actorIndex_, 9, 0)) return;
	}
	if (var4 > 100.0f) var4 = 100.0f;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)arg0, 1);
	func_ov024_021fd088(arg0, var4, 3);
}
