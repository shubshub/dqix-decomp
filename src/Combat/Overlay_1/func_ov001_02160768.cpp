#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern "C" int func_ov001_0215ad2c(int x);
extern SafeAllocator* data_ov001_021658b8[8];
extern "C" void* func_02010768(void* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_0204a120;
extern "C" void func_0204a120(struct Struct_0204a120* obj);

struct Struct_0204a3f0_2;
struct Struct_0204a3f0;
extern "C" void func_0204a3f0(struct Struct_0204a3f0_2* owner, struct Struct_0204a3f0* h);

extern "C" void func_0204a440(char* obj, const char* src);
extern "C" void func_0204a464(char* obj, const char* src);
extern "C" void func_0204a488(char* obj, const char* src);

struct Struct_0204a5dc;
extern "C" void func_0204a5dc(struct Struct_0204a5dc* p, int v);

// USA: func_ov001_02160768
extern "C" ARM int func_ov001_02160768(char* self) {
	GameState* bs = GameState::GetInstance();
	SafeAllocator* allocator = data_ov001_021658b8[0];
	void* fieldPtr = func_02010768(bs);

	int a = func_ov017_021d60f4(self);
	void* name = func_ov017_021d612c(self + 0x8);
	void* var5 = func_ov017_021d612c(self + 0x10);
	void* var6 = func_ov017_021d612c(self + 0x18);
	int b = func_ov017_021d60f4(self + 0x20);

	int var8 = func_ov001_0215ad2c(a);
	int id2 = func_ov001_0215ad2c(b);

	GameObject* var10 = bs->GetGameObjectByIndex(var8);
	if (var10 == NULL) return 0;

	GameObject* combatant2 = bs->GetGameObjectByIndex(id2);
	if (combatant2 == NULL) return 0;

	void* newObj = allocator->Allocate(0x268);

	*(void**)((char*)fieldPtr + 0x4) = bs->GetCamera();

	func_0204a120((struct Struct_0204a120*)newObj);
	func_0204a3f0((struct Struct_0204a3f0_2*)newObj, (struct Struct_0204a3f0*)var10);
	func_0204a440((char*)newObj, (const char*)name);
	func_0204a464((char*)newObj, (const char*)var5);
	func_0204a488((char*)newObj, (const char*)var6);
	func_0204a5dc((struct Struct_0204a5dc*)newObj, (int)combatant2);

	((Object3D*)((unsigned char*)var10))->EnableFlag(1);
	((Object3D*)((unsigned char*)var10))->EnableFlag(0x20);

	GameState_SetCamera(bs, (int)newObj);
	return 1;
}
