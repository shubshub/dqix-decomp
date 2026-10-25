#if defined(jpn)
enum {Enum_ov017_021b71d8_128988=0x1f9cc};
#else
enum {Enum_ov017_021b71d8_128988=0x1f7dc};
#endif
#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Struct_ov017_021b71d8 {
    unsigned char unknown_0_[0x8e44];
    unsigned char unknown_8e44_[3];
    unsigned char unknown_8e47_;
    unsigned char unknown_8e48_[0x8eb4 - 0x8e48];
};

struct Struct_ov017_021b71d8_2 {
    unsigned short unknown_0_;
};

struct Struct_ov017_021b71d8_3 {
    unsigned char unknown_0_[0x8];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_[0x1c - 0x8 - sizeof(SafeAllocator)];
    unsigned short unknown1_1c_;
    unsigned char unknown_1e_[0x6b0 - 0x1e];
    Struct_ov017_021b71d8* unknown_6b0_;
    unsigned char unknown_6b4_[0x6c0 - 0x6b4];
    unsigned char unknown_6c0_[3];
    unsigned char unknown_6c3_;
};

extern "C" Holder021b71d8* Zone3D_GetInstance(void);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;
extern "C" void func_ov000_0215ce80(Context021b71d8* context);
extern "C" void func_ov000_0215fab0(Context021b71d8* context, unsigned char value);

// USA: func_ov017_021b71d8
extern "C" ARM void func_ov017_021b71d8(Struct_ov017_021b71d8_3* arg0) {
    GameState::GetInstance();
    Holder021b71d8* holder = Zone3D_GetInstance();
    EmptyStub02012de4(&g_mainAllocator);
    func_020a0cc4(regionalOffset0);
    self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, regionalOffset0), regionalOffset0);
    self->id = holder->id;
    self->context = (Context021b71d8*)self->allocator.Allocate(sizeof(Context021b71d8));
    func_ov000_0215ce80(self->context);
    for (int i = 0; i < self->pendingCount; i++) {
        func_ov000_0215fab0(self->context, self->pending[i]);
    }
    memset(arg0->unknown_6c0_, 0, sizeof(arg0->unknown_6c0_));
    arg0->unknown_6c3_ = 0;
}
