#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_020972c8(int* p);
extern "C" void func_ov014_021845ec(void* self);

struct Struct_ov014_02186b30 {
    char pad0[0xa4];
    int unknown_a4_;
    char pad1[0xb4 - 0xa8];
    SafeAllocator* allocators;
    char pad2[0x168 - 0xb8];
    int unknown_168_;
};

static inline void inline_020dbf70(int& taskId) {
    BackgroundLoader::GetInstance()->RemoveTask(taskId);
    taskId = -1;
}

// USA: func_ov014_02186b30
extern "C" ARM void func_ov014_02186b30(struct Struct_ov014_02186b30* self) {
    if (self->unknown_168_ >= 0) {
        inline_020dbf70(self->unknown_168_);
    }
    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b40(g);
    FontBankLoader_CancelLoads(g);
    func_020972c8(&self->unknown_a4_);
    func_ov014_021845ec(self);
    if (self->allocators == 0) {
        return;
    }
    int i;
    for (i = 0; i < 5; i++) {
        if (self->allocators[i].GetSignedAllocator()) {
            self->allocators[i].Destroy();
        }
    }
}
