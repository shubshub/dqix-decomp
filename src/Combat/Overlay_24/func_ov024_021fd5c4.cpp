#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_021fa76c;
extern "C" int func_ov024_021fa76c(struct Struct_021fa76c* combatant);
extern "C" int func_020883ac(unsigned char* obj);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
extern "C" void func_ov024_021fd088(void* obj, float arg1, int a2);
struct Struct_ov024_021fd1bc;
extern "C" void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val);

struct Struct_ov024_021fd5c4 { unsigned int lo : 7; unsigned int val : 7; };
struct Struct_ov024_021fd5c4_2 { char pad[0x14]; struct Struct_ov024_021fd5c4 bits; };

struct Struct_ov024_021fd5c4_3 {
	char pad0[0x64c];
	struct Struct_ov024_021fd5c4_2* unknown_64c_;
	char pad2[0x668 - 0x64c - 4];
	GameObject* unknown_668_;
};

// USA: func_ov024_021fd5c4
extern "C" ARM void func_ov024_021fd5c4(struct Struct_ov024_021fd5c4_3* obj) {
	GameObject* c = obj->unknown_668_;
	if (!func_ov024_021fa76c((struct Struct_021fa76c*)c)) return;
	if (!func_020883ac((unsigned char*)c->currentStats_)) return;
	if (func_ov024_021de25c((struct Struct_ov024_021de124*)c)) return;
	float var1 = (float)obj->unknown_64c_->bits.val;
	unsigned char var2 = *(unsigned char*)((char*)c->currentStats_ + 0x4a);
	float var3 = var1 * ((float)var2 / 100.0f);
	if (var3 > 100.0f) var3 = 100.0f;
	func_ov024_021fe6b4((struct Struct_ov024_021fd1bc*)obj, 1);
	func_ov024_021fd088(obj, var3, 7);
}
