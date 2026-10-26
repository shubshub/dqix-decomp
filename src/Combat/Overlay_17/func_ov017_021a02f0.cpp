#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void NNS_GfdGetFrmTexVramState(int* out);
extern "C" void NNS_GfdGetFrmPlttVramState(int* dst);
extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int a, int b);
extern "C" void VramState_Reserve(void* pObj, int a, int b);
extern "C" void func_020542b4(void* a, void* b, void* c);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6984 {
    int index;
    unsigned int size;
};
extern Struct_ov017_021d6984 data_ov017_021d6984[];

struct Struct_ov017_021d6924 {
    int index;
    int a;
    int b;
};
extern Struct_ov017_021d6924 data_ov017_021d6924[];

struct Struct_02000c9c_57 {
    char data[0x70];
};

struct Struct_ov017_021a02f0 {
    short field_0x0;
    short id;
    char data[0x5ec - 0x4];
};

struct Struct_ov017_021a02f0_2 {
    int table[10];
    int pair[2];
};

struct Struct_ov017_021a02f0_3 {
    char pad0[0x38];
#if defined(jpn)
    SafeAllocator allocators[29];
#else
    SafeAllocator allocators[33];
#endif
#if defined(jpn)
    Struct_02000c9c_57 slots[32];
#else
    Struct_02000c9c_57 slots[36];
#endif
    char unknown_128c_[0x12c8 - 0x128c];
    Struct_ov017_021a02f0 groups[4];
    Struct_ov017_021a02f0_2 backups[3];
};

// USA: func_ov017_021a02f0
extern "C" ARM void func_ov017_021a02f0(Struct_ov017_021a02f0_3* self) {
    int i;
    unsigned int size;

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

    for (int j = 0; j < 4; j++) {
        func_020542b4(&self->groups[j], &self->allocators[j + 1], &self->slots[j + 1]);
        self->groups[j].id = j;
    }
}
