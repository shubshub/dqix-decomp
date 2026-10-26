#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02088540(unsigned char* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

struct Struct_ov024_021fd358 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd358_2 { char pad[0x14]; struct Struct_ov024_021fd358 bits; };

struct Struct_ov024_021fd358_3 {
	char pad0[0x64c];
	struct Struct_ov024_021fd358_2* unknown_64c_;
	char pad2[0x668 - 0x64c - 4];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd358
extern "C" ARM void func_ov024_021fd358(struct Struct_ov024_021fd358_3* obj) {
	GameObject* c = obj->unknown_668_;
	if (!func_02088540((unsigned char*)c->currentStats_)) return;
	if (func_02088514((struct Struct_02088514*)c->currentStats_)) return;
	float var1 = (float)obj->unknown_64c_->bits.val;
	unsigned char var2 = *(unsigned char*)((char*)c->currentStats_ + 0x4d);
	float var3 = var1 * ((float)var2 / 100.0f);
	if (var3 > 100.0f) var3 = 100.0f;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 1);
	func_ov024_021fd088(obj, var3, 2);
}
