#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { Enum_ov017_021c1404_147456 = 0x22c00, Enum_ov017_021c1404_828 = 0x338, Enum_ov017_021c1404_372 = 0x170 };
#else
enum { Enum_ov017_021c1404_147456 = 0x24000, Enum_ov017_021c1404_828 = 0x33c, Enum_ov017_021c1404_372 = 0x174 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

int GetFieldIfFlag4_020100f8(char* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void GameObject_EnableControl(void* obj);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);

extern "C" void func_ov003_02154720(void* arg0, unsigned char arg1);
extern "C" void func_ov003_021544ec(void* arg0, SafeAllocator* arg1);
extern "C" int func_ov003_02154af4(void* arg0, unsigned int arg1);
extern "C" void func_ov003_021549a8(void* arg0);

extern "C" ARM void func_ov017_021c1264(void);
extern "C" void func_ov017_021c1394(void* arg0);

extern int data_ov017_021d8478;

struct Struct_ov017_021c1404 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	char unknown_2_[6];
	SafeAllocator unknown_8_;
	unsigned char unknown_1c_;
	unsigned char unknown_1d_;
	unsigned char unknown_1e_;
};

// Overlay 17, originally func_ov017_021c1404 (USA/EUR 0x021c1404, JPN 0x021c19ac)
extern "C" ARM void FieldTask_ChangeVocation(struct Obj021c1404* obj) {
	GameState* battle = GameState::GetInstance();
	int* word0 = (int*)battle->GetResources();
	GameObject* combatant = battle->GetUnknownGameObject();
	int fieldVal = GetFieldIfFlag4_020100f8((char*)battle);
	SetFlags04((GameResources*)word0, 0xc0);
	if (combatant) {
		GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
	}
	func_020a28a0((unsigned char*)var3, 3);
	unsigned char var4 = arg0->unknown_1c_;

	if (step == 0) {
		func_020a0cc4(kSceneHeapSize);
		void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, kSceneHeapSize);
		if (!buf) {
			func_020a0c0c();
			arg0->unknown_1_ = 1;
			return;
		}
		arg0->unknown_8_.CreateTypeA(var5, Enum_ov017_021c1404_147456);
		arg0->unknown_8_.Reset();
		void* var6 = arg0->unknown_8_.Allocate(Enum_ov017_021c1404_828);
		data_ov017_021d8478 = (int)var6;
		if (!var6) {
			func_020a0c0c();
			arg0->unknown_1_ = 1;
			return;
		}
		func_020a1df8(3);
		func_020a1ef0(1);
		func_ov003_02154720((void*)data_ov017_021d8478, arg0->unknown_1e_);
		func_ov003_021544ec((void*)data_ov017_021d8478, &arg0->unknown_8_);
		func_ov017_021c1264();
		arg0->unknown_1c_ = arg0->unknown_1c_ + 1;
		return;
	}
	if (step == 1) {
		unsigned int scaleCount = battle->GetTickCount();
		if (func_ov003_02154af4((void*)data_ov017_021d8478, scaleCount) == 0) return;
		FontBankLoader* val = FontBankLoader_GetInstance();
		BlankFunction02094b40(val);
		FontBankLoader_CancelLoads(val);
		BlankFunction02094b34(val, 0x6f, 0x1388, 1, 1);
		obj->step = obj->step + 1;
		return;
	}
	if (step == 2) {
		if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
		func_ov003_021549a8((void*)data_ov017_021d8478);
		arg0->unknown_1c_ = arg0->unknown_1c_ + 1;
		return;
	}
	if (var4 != 3) return;

	int* dispReg = (int*)0x4000000;
	unsigned int memField = *(unsigned int*)((char*)data_ov017_021d8478 + kSceneFieldOffset);
	*dispReg = (memField << 8) | (*dispReg & ~0x1f00);
	ClearFlags04((GameResources*)word0, 0xc0);
	GameObject_EnableControl(combatant);
	ClearFlagBits_020a28b0((unsigned char*)fieldVal, 3);
	func_ov017_021c1394(obj);
	func_020a0c0c();
	arg0->unknown_1_ = 1;
	func_ov017_021c1264();
}
