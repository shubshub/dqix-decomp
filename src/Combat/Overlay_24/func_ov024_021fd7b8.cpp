#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);

struct Struct_ov024_021fd7b8 { unsigned int w[3]; };

// USA: func_ov024_021fd7b8
extern "C" ARM void func_ov024_021fd7b8(void* objRaw) {
	char* obj = (char*)objRaw;
	float scale = 12.5f;
	GameObject* var2 = *(GameObject**)(obj + 0x668);
	int var3 = *(unsigned char*)((char*)var2->currentStats_ + 0x48);
	float var4 = scale * ((float)var3 / 100.0f);
	struct Struct_ov024_021fd7b8 local = *(struct Struct_ov024_021fd7b8*)(obj + 0x65c);
	short v = *(short*)(*(char**)(obj + 0x64c) + 0x32);
	*(float*)&local.w[0] = (float)v;
	unsigned char var7 = ((unsigned char*)&local)[7];
	float var8 = (float)var7 * var4 / 100.0f;
	((unsigned char*)&local)[7] = (unsigned char)(int)var8;
	((unsigned char*)&local)[8] = 2;
	func_ov024_021f6a1c(*(struct Struct_ov024_021f6a1c**)(obj + 0x658), &local);
}
