#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_0208beb4(unsigned char* obj);
extern "C" void func_0208bb78(void* obj, int count);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct Struct_ov001_02154e40 {
    char pad0[0xa];
    unsigned short unknown_a_;
    char pad1[0x13 - 0xc];
    unsigned char unknown_13_;
    char pad2[0x50 - 0x14];
    unsigned short unknown_50_;
#if defined(jpn)
    char pad3[0x11c - 0x52];
#else
    char pad3[0x120 - 0x52];
#endif
    void* unknown_120_;
    char pad4[0x138 - 0x124];
    SafeAllocator* unknown_138_;
};

// USA: func_ov001_02154e40
extern "C" ARM int func_ov001_02154e40(struct Struct_ov001_02154e40* self) {
    GameState* battle = GameState::GetInstance();

    if (!(self->unknown_50_ & 0x8) && self->unknown_138_ != 0 && self->unknown_120_ != 0) {
        func_0208beb4((unsigned char*)self->unknown_120_);
        unsigned int scaleCount = battle->GetTickCount();
        func_0208bb78(self->unknown_120_, scaleCount);

        if (*(short*)((char*)self->unknown_120_ + 0xd2) >= 0) {
            return self->unknown_a_;
        }

        void* signedAlloc = (void*)self->unknown_138_->GetSignedAllocator();
        if (signedAlloc) {
            self->unknown_138_->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
            self->unknown_138_ = 0;
        }
        self->unknown_120_ = 0;
    }

    FontBankLoader* val = FontBankLoader_GetInstance();
    unsigned char flag = 1;
    if (self->unknown_13_ != 0) {
        flag = 0;
    }
    func_02094b40(val);
    FontBankLoader_CancelLoads(val);
    func_02094b2c(val, 0x6f, (char*)self + 0x62, 1, flag);
    return 0xd;
}
