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
void SetByteField0x253_020397c0(void* obj);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);

struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);

extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern AllocatorUnion data_02114e20;
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

// USA: func_ov017_021c1404  (semantic: AdvanceEncounterSequenceStep_021c1404)
extern "C" ARM void func_ov017_021c1404(struct Obj021c1404* obj) {
	GameState* battle = GameState::GetInstance();
	int* word0 = (int*)battle->GetResources();
	GameObject* combatant = battle->GetUnknownGameObject();
	int fieldVal = GetFieldIfFlag4_020100f8((char*)battle);
	SetFlags04((GameResources*)word0, 0xc0);
	if (combatant) {
		CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
	}
	func_020a28a0((unsigned char*)var3, 3);
	unsigned char var4 = arg0->unknown_1c_;

	if (var4 == 0) {
		func_020a0cc4(Enum_ov017_021c1404_147456);
		void* var5 = func_02012d88(&data_02114e20, Enum_ov017_021c1404_147456);
		if (!var5) {
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
	if (var4 == 1) {
		unsigned int var7 = var0->GetTickCount();
		if (func_ov003_02154af4((void*)data_ov017_021d8478, var7) == 0) return;
		Struct_0208cb08* var8 = func_02094a00();
		func_02094b40(var8);
		func_02094ab0(var8);
		func_02094b34(var8, 0x6f, 0x1388, 1, 1);
		arg0->unknown_1c_ = arg0->unknown_1c_ + 1;
		return;
	}
	if (var4 == 2) {
		if (!func_02094b4c(func_02094a00())) return;
		func_ov003_021549a8((void*)data_ov017_021d8478);
		arg0->unknown_1c_ = arg0->unknown_1c_ + 1;
		return;
	}
	if (var4 != 3) return;

	int* var9 = (int*)0x4000000;
	unsigned int var10 = *(unsigned int*)((char*)data_ov017_021d8478 + Enum_ov017_021c1404_372);
	*var9 = (var10 << 8) | (*var9 & ~0x1f00);
	ClearFlags04((GameResources*)var1, 0xc0);
	func_020397c0(var2);
	func_020a28b0((unsigned char*)var3, 3);
	func_ov017_021c1394(arg0);
	func_020a0c0c();
	arg0->unknown_1_ = 1;
	func_ov017_021c1264();
}
