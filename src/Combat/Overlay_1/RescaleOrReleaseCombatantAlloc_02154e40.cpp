#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void SetFlag0x2IfByte0xd4Not3_0208beb4(unsigned char* obj);
extern "C" void func_0208bb78(void* obj, int count);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct Obj02154e40 {
    char pad0[0xa];
    unsigned short field0xa;
    char pad1[0x13 - 0xc];
    unsigned char field0x13;
    char pad2[0x50 - 0x14];
    unsigned short flags0x50;
#if defined(jpn)
    char pad3[0x11c - 0x52];
#else
    char pad3[0x120 - 0x52];
#endif
    void* field0x120;
    char pad4[0x138 - 0x124];
    SafeAllocator* field0x138;
};

// USA: func_ov001_02154e40  (semantic: RescaleOrReleaseCombatantAlloc_02154e40)
extern "C" ARM int func_ov001_02154e40(struct Obj02154e40* self) {
    GameState* battle = GameState::GetInstance();

    if (!(self->flags0x50 & 0x8) && self->field0x138 != 0 && self->field0x120 != 0) {
        SetFlag0x2IfByte0xd4Not3_0208beb4((unsigned char*)self->field0x120);
        unsigned int scaleCount = battle->GetTickCount();
        func_0208bb78(self->field0x120, scaleCount);

        if (*(short*)((char*)self->field0x120 + 0xd2) >= 0) {
            return self->field0xa;
        }

        void* signedAlloc = (void*)self->field0x138->GetSignedAllocator();
        if (signedAlloc) {
            self->field0x138->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
            self->field0x138 = 0;
        }
        self->field0x120 = 0;
    }

    FontBankLoader* val = FontBankLoader_GetInstance();
    unsigned char flag = 1;
    if (self->field0x13 != 0) {
        flag = 0;
    }
    BlankFunction02094b40(val);
    FontBankLoader_CancelLoads(val);
    BlankFunction02094b2c(val, 0x6f, (char*)self + 0x62, 1, flag);
    return 0xd;
}
