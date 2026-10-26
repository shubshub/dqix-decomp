#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct FlagWord020466f4;

struct Struct_ov031_022439d8 {
	unsigned char pad0[0x28];
	SafeAllocator* f28;
	unsigned char pad1[0x30 - 0x2c];
	int unknown_30_;
	unsigned char pad2[0x44 - 0x34];
	unsigned char unknown_44_;
	unsigned char pad3[0x374 - 0x45];
	unsigned char unknown_374_;
	unsigned char pad4[0x37c - 0x375];
	void* unknown_37c_;
	unsigned char pad5[0x39c - 0x380];
	int unknown_39c_;
	int unknown_3a0_;
};

extern SafeAllocator data_ov031_02291e3c;
extern "C" void func_ov023_021f5b9c(void* a, void* b, int c, void* d);
extern "C" void GameObject_EnableControl(void* p);
extern "C" FlagWord020466f4* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* p, unsigned int flags);

// USA: func_ov031_022439d8
extern "C" ARM int func_ov031_022439d8(Struct_ov031_022439d8* ctx) {
	void* base = GetGameResources();
	BackgroundLoader* loader = BackgroundLoader::GetInstance();
	GameObject* obj = GameState::GetInstance()->GetLeader();
	if (obj != 0) {
		GameObject_EnableControl(obj);
	}
#if defined(jpn)
	*(int*)((char*)base + 0x41e4) = 0;
#else
	*(int*)((char*)base + 0x4494) = 0;
#endif
	if (ctx->unknown_39c_ >= 0) {
		loader->RemoveTask(ctx->unknown_39c_);
		ctx->unknown_39c_ = -1;
	}
	if (ctx->unknown_3a0_ >= 0) {
		loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(ctx->unknown_3a0_);
		ctx->unknown_3a0_ = -1;
	}
	SignedAllocatorHeader* p = data_ov031_02291e3c.GetSignedAllocator();
	if (p != 0) {
		data_ov031_02291e3c.Destroy();
		((SafeAllocator*)ctx)->Free(p);
	}
	p = ((SafeAllocator*)ctx)->GetSignedAllocator();
	if (p != 0) {
		((SafeAllocator*)ctx)->Destroy();
		ctx->f28->Free(p);
	}
	if (ctx->unknown_44_ & 1) {
		((SafeAllocator*)ctx)->ResetAllocatorPointer();
		void* buf = ctx->f28->Allocate(0xf000);
		if (buf != 0) {
			((SafeAllocator*)ctx)->CreateTypeA(buf, 0xf000);
			((SafeAllocator*)ctx)->Reset();
			func_ov023_021f5b9c(ctx->unknown_37c_, (char*)ctx + 0x50, 4, ctx);
		}
		p = ((SafeAllocator*)ctx)->GetSignedAllocator();
		if (p != 0) {
			((SafeAllocator*)ctx)->Destroy();
			ctx->f28->Free(p);
		}
	}
	if ((ctx->unknown_374_ & 0x20) == 0) {
		FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x80);
	}
	ctx->unknown_30_ = 1;
	return 2;
}
