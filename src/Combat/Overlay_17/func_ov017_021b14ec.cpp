#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

struct Struct_020979c0;
extern "C" void func_020979f4(struct Struct_020979c0* p);
extern "C" void func_020a1e54(int flag);
extern "C" void func_020a1f4c(int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);

extern int g_mainAllocator;
extern int data_ov017_021d83ec;

struct Struct_ov017_021b14ec {
    char pad0[0x8];
    SafeAllocator allocator;
    struct Struct_020979c0* field1c;
};

// USA: func_ov017_021b14ec
extern "C" ARM void func_ov017_021b14ec(struct Struct_ov017_021b14ec* self) {
    if (self->field1c != NULL) func_020979f4(self->field1c);
    data_ov017_021d83ec = 0;

    void* p = self->allocator.GetSignedAllocator();
    if (p) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }

    func_020a1e54(1);
    func_020a1f4c(1);
    int field = GameState_GetFollowCamera((char*)GameState::GetInstance());
    if (field != 0) func_020a27ac((void*)field);
}
