#if defined(jpn)
enum {regionalOffset0=0x1f9cc};
#else
enum {regionalOffset0=0x1f7dc};
#endif
#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Struct_ov017_021b71d8 {
    unsigned char pad0[0x8e44];
    unsigned char pending[3];
    unsigned char unknown_8e47_;
    unsigned char unknown_8e48_[0x8eb4 - 0x8e48];
};

struct Holder021b71d8 {
    unsigned short id;
};

struct Struct_ov017_021b71d8_3 {
    unsigned char pad0[0x8];
    SafeAllocator allocator;
    unsigned char unknown_1c_[0x1c - 0x8 - sizeof(SafeAllocator)];
    unsigned short id;
    unsigned char pad1e[0x6b0 - 0x1e];
    Struct_ov017_021b71d8* context;
    unsigned char unknown_6b4_[0x6c0 - 0x6b4];
    unsigned char pending[3];
    unsigned char unknown_6c3_;
};

extern "C" Holder021b71d8* Zone3D_GetInstance(void);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;
extern "C" void func_ov000_0215ce80(Struct_ov017_021b71d8* context);
extern "C" void func_ov000_0215fab0(Struct_ov017_021b71d8* context, unsigned char value);

// USA: func_ov017_021b71d8
extern "C" ARM void func_ov017_021b71d8(Struct_ov017_021b71d8_3* self) {
    GameState::GetInstance();
    Holder021b71d8* holder = Zone3D_GetInstance();
    func_02012de4(&g_mainAllocator);
    func_020a0cc4(regionalOffset0);
    self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, regionalOffset0), regionalOffset0);
    self->id = holder->id;
    self->context = (Struct_ov017_021b71d8*)self->allocator.Allocate(sizeof(Struct_ov017_021b71d8));
    func_ov000_0215ce80(self->context);
    for (int i = 0; i < self->unknown_6c3_; i++) {
        func_ov000_0215fab0(self->context, self->pending[i]);
    }
    memset(self->pending, 0, sizeof(self->pending));
    self->unknown_6c3_ = 0;
}
