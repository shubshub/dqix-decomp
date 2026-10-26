#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kSceneHeapSize = 0x22c00, Enum_ov017_021c1404_828 = 0x338, Enum_ov017_021c1404_372 = 0x170 };
#else
enum { kSceneHeapSize = 0x24000, Enum_ov017_021c1404_828 = 0x33c, Enum_ov017_021c1404_372 = 0x174 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_020a1df8(int id);
extern "C" void func_020a1ef0(int id);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;
extern "C" void func_020a0cc4(unsigned int);
extern "C" void ROMFilesystem_InitFileTables(void);

extern "C" void func_ov003_02154720(void* mem, unsigned char b);
extern "C" void func_ov003_021544ec(void* mem, SafeAllocator* alloc);
extern "C" int func_ov003_02154af4(void* mem, unsigned int scaleCount);
extern "C" void func_ov003_021549a8(void* mem);

extern "C" ARM void func_ov017_021c1264(void);
extern "C" void func_ov017_021c1394(void* self);

extern int data_ov017_021d8478;

struct Obj021c1404 {
	unsigned char pad0;
	unsigned char flag1;
	char pad2[6];
	SafeAllocator allocator;
	unsigned char step;
	unsigned char pad3;
	unsigned char unknown_1e_;
};

// Overlay 17, originally func_ov017_021c1404 (USA/EUR 0x021c1404, JPN 0x021c19ac)
extern "C" ARM void FieldTask_ChangeVocation(struct Obj021c1404* obj) {
	GameState* battle = GameState::GetInstance();
	int* word0 = (int*)battle->GetResources();
	GameObject* combatant = battle->GetLeader();
	int fieldVal = GameState_GetFollowCamera((char*)battle);
	SetFlags04((GameResources*)word0, 0xc0);
	if (combatant) {
		GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
	}
	func_020a28a0((unsigned char*)fieldVal, 3);
	unsigned char step = obj->step;

	if (step == 0) {
		func_020a0cc4(kSceneHeapSize);
		void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, kSceneHeapSize);
		if (!buf) {
			ROMFilesystem_InitFileTables();
			obj->flag1 = 1;
			return;
		}
		obj->allocator.CreateTypeA(buf, kSceneHeapSize);
		obj->allocator.Reset();
		void* mem = obj->allocator.Allocate(Enum_ov017_021c1404_828);
		data_ov017_021d8478 = (int)mem;
		if (!mem) {
			ROMFilesystem_InitFileTables();
			obj->flag1 = 1;
			return;
		}
		func_020a1df8(3);
		func_020a1ef0(1);
		func_ov003_02154720((void*)data_ov017_021d8478, obj->unknown_1e_);
		func_ov003_021544ec((void*)data_ov017_021d8478, &obj->allocator);
		func_ov017_021c1264();
		obj->step = obj->step + 1;
		return;
	}
	if (step == 1) {
		unsigned int scaleCount = battle->GetTickCount();
		if (func_ov003_02154af4((void*)data_ov017_021d8478, scaleCount) == 0) return;
		FontBankLoader* val = FontBankLoader_GetInstance();
		func_02094b40(val);
		FontBankLoader_CancelLoads(val);
		func_02094b34(val, 0x6f, 0x1388, 1, 1);
		obj->step = obj->step + 1;
		return;
	}
	if (step == 2) {
		if (!func_02094b4c(FontBankLoader_GetInstance())) return;
		func_ov003_021549a8((void*)data_ov017_021d8478);
		obj->step = obj->step + 1;
		return;
	}
	if (step != 3) return;

	int* var9 = (int*)0x4000000;
	unsigned int var10 = *(unsigned int*)((char*)data_ov017_021d8478 + Enum_ov017_021c1404_372);
	*var9 = (var10 << 8) | (*var9 & ~0x1f00);
	ClearFlags04((GameResources*)word0, 0xc0);
	GameObject_EnableControl(combatant);
	func_020a28b0((unsigned char*)fieldVal, 3);
	func_ov017_021c1394(obj);
	ROMFilesystem_InitFileTables();
	obj->flag1 = 1;
	func_ov017_021c1264();
}
