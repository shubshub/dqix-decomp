#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern "C" int func_ov001_0215ad2c(int arg0);
extern SafeAllocator* data_ov001_021658b8[8];
void* GetFieldPtrAt0x5ca4_02010768(void* obj);
void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_0204a120;
extern "C" void func_0204a120(struct Struct_0204a120* arg0);

struct Struct_0204a3f0_2;
struct Struct_0204a3f0;
extern "C" void func_0204a3f0(struct Struct_0204a3f0_2* arg0, struct Struct_0204a3f0* arg1);

extern "C" void func_0204a440(char* arg0, const char* arg1);
extern "C" void func_0204a464(char* arg0, const char* arg1);

// USA: func_ov001_0215f854
extern "C" ARM int func_ov001_0215f854(char* arg0) {
	GameState* var0 = GameState::GetInstance();
	SafeAllocator* var1 = data_ov001_021658b8[0];
	void* var2 = func_02010768(var0);

	int var3 = func_ov017_021d60f4(arg0);
	void* var4 = func_ov017_021d612c(arg0 + 0x8);
	void* var5 = func_ov017_021d612c(arg0 + 0x10);

	int var6 = func_ov001_0215ad2c(var3);

	GameObject* var7 = var0->GetGameObjectByIndex(var6);
	if (var7 == NULL) return 0;

	void* var8 = var1->Allocate(0x268);

	*(void**)((char*)fieldPtr + 0x4) = bs->GetCamera();

	func_0204a120((struct Struct_0204a120*)var8);
	func_0204a3f0((struct Struct_0204a3f0_2*)var8, (struct Struct_0204a3f0*)var7);
	func_0204a440((char*)var8, (const char*)var4);
	func_0204a464((char*)var8, (const char*)var5);

	((Object3D*)((unsigned char*)var7))->EnableFlag(1);
	((Object3D*)((unsigned char*)var7))->EnableFlag(0x20);

	GameState_SetCamera(bs, (int)newObj);
	return 1;
}
