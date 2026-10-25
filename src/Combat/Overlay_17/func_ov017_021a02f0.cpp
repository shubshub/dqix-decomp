#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void NNS_GfdGetFrmTexVramState(int* out);
void NNS_GfdGetFrmPlttVramState(int* dst);
extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int a, int b);
extern "C" void VramState_Reserve(void* pObj, int a, int b);
extern "C" void func_020542b4(void* a, void* b, void* c);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6984 {
    int unknown_0_;
    unsigned int unknown_4_;
};
extern Struct_ov017_021d6984 data_ov017_021d6984[];

struct Struct_ov017_021d6924 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};
extern Struct_ov017_021d6924 data_ov017_021d6924[];

struct Struct_02000c9c_57 {
    char unknown_0_[0x70];
};

struct Struct_ov017_021a02f0 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0x5ec - 0x4];
};

struct Struct_ov017_021a02f0_2 {
    int unknown_0_[10];
    int unknown_28_[2];
};

struct Struct_ov017_021a02f0_3 {
    char unknown_0_[0x38];
#if defined(jpn)
    SafeAllocator unknown_38_[29];
#else
    SafeAllocator unknown_38_[33];
#endif
#if defined(jpn)
    Struct_02000c9c_57 unknown_2cc_[32];
#else
    Struct_02000c9c_57 unknown_2cc_[36];
#endif
    char unknown_128c_[0x12c8 - 0x128c];
    Struct_ov017_021a02f0 unknown_12c8_[4];
    Struct_ov017_021a02f0_2 unknown_2a78_[3];
};

// USA: func_ov017_021a02f0
extern "C" ARM void func_ov017_021a02f0(Struct_ov017_021a02f0_3* arg0) {
    int var0;
    unsigned int var1;

    for (i = 0; (size = data_ov017_021d6984[i].size) != 0; i++) {
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        self->allocators[data_ov017_021d6984[i].index].CreateTypeA(buf, size);
    }

    NNS_GfdGetFrmTexVramState(self->backups[0].table);
    NNS_GfdGetFrmPlttVramState(self->backups[0].pair);
    NNS_GfdAllocFrmTexVram(0x20000, 0, 0);
    NNS_GfdAllocFrmTexVram(0x20000, 0, 0);

    for (i = 0; data_ov017_021d6924[i].a != 0; i++) {
        VramState_Reserve(&self->slots[data_ov017_021d6924[i].index], data_ov017_021d6924[i].a,
                      data_ov017_021d6924[i].b);
        if (i == 1) {
            NNS_GfdGetFrmTexVramState(self->backups[2].table);
            NNS_GfdGetFrmPlttVramState(self->backups[2].pair);
        }
    }

    NNS_GfdGetFrmTexVramState(self->backups[1].table);
    NNS_GfdGetFrmPlttVramState(self->backups[1].pair);

    for (int var3 = 0; var3 < 4; var3++) {
        func_020542b4(&arg0->unknown_12c8_[var3], &arg0->unknown_38_[var3 + 1], &arg0->unknown_2cc_[var3 + 1]);
        arg0->unknown_12c8_[var3].unknown_2_ = var3;
    }
}
