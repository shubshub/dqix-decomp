#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_02038598_4;

struct Struct_ov031_022439d8 {
	unsigned char unknown_0_[0x28];
	SafeAllocator* unknown_28_;
	unsigned char unknown_2c_[0x30 - 0x2c];
	int unknown_30_;
	unsigned char unknown_34_[0x44 - 0x34];
	unsigned char unknown_44_;
	unsigned char unknown_45_[0x374 - 0x45];
	unsigned char unknown_374_;
	unsigned char unknown_375_[0x37c - 0x375];
	void* unknown_37c_;
	unsigned char unknown_380_[0x39c - 0x380];
	int unknown_39c_;
	int unknown_3a0_;
};

extern SafeAllocator data_ov031_02291e3c;
extern "C" void func_ov023_021f5b9c(void* a, void* b, int c, void* d);
void GameObject_EnableControl(void* p);
FlagWord020466f4* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(FlagWord020466f4* p, unsigned int flags);

// USA: func_ov031_022439d8
extern "C" ARM int func_ov031_022439d8(Struct022439d8* ctx) {
	void* base = GetGameResources();
	BackgroundLoader* loader = BackgroundLoader::GetInstance();
	GameObject* obj = GameState::GetInstance()->GetUnknownGameObject();
	if (obj != 0) {
		GameObject_EnableControl(obj);
	}
#if defined(jpn)
	*(int*)((char*)var0 + 0x41e4) = 0;
#else
	*(int*)((char*)var0 + 0x4494) = 0;
#endif
	if (arg0->unknown_39c_ >= 0) {
		var1->RemoveTask(arg0->unknown_39c_);
		arg0->unknown_39c_ = -1;
	}
	if (arg0->unknown_3a0_ >= 0) {
		var1 = BackgroundLoader::GetInstance();
		var1->RemoveTask(arg0->unknown_3a0_);
		arg0->unknown_3a0_ = -1;
	}
	SignedAllocatorHeader* var3 = data_ov031_02291e3c.GetSignedAllocator();
	if (var3 != 0) {
		data_ov031_02291e3c.Destroy();
		((SafeAllocator*)arg0)->Free(var3);
	}
	var3 = ((SafeAllocator*)arg0)->GetSignedAllocator();
	if (var3 != 0) {
		((SafeAllocator*)arg0)->Destroy();
		arg0->unknown_28_->Free(var3);
	}
	if (arg0->unknown_44_ & 1) {
		((SafeAllocator*)arg0)->ResetAllocatorPointer();
		void* var4 = arg0->unknown_28_->Allocate(0xf000);
		if (var4 != 0) {
			((SafeAllocator*)arg0)->CreateTypeA(var4, 0xf000);
			((SafeAllocator*)arg0)->Reset();
			func_ov023_021f5b9c(arg0->unknown_37c_, (char*)arg0 + 0x50, 4, arg0);
		}
		var3 = ((SafeAllocator*)arg0)->GetSignedAllocator();
		if (var3 != 0) {
			((SafeAllocator*)arg0)->Destroy();
			arg0->unknown_28_->Free(var3);
		}
	}
	if ((ctx->f374 & 0x20) == 0) {
		FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x80);
	}
	arg0->unknown_30_ = 1;
	return 2;
}
