#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Struct_020d8484 {
    signed char byte0;
    signed char unknown_1_;
    signed char unknown_2_;
    signed char unknown_3_;
};
struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
struct Obj020d8484 {
    struct Struct_020d8484 header;
    int field4;
    int field8;
    struct Struct_020727d8 list;
    SafeAllocator allocator;
};

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);
extern "C" void func_020727ec(struct Struct_020727d8* list);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

// USA: func_020d8484
extern "C" ARM void func_020d8484(struct Obj020d8484* self) {
    func_020a27ac((void*)GameState_GetFollowCamera((char*)GameState::GetInstance()));
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Reset();
        self->allocator.Destroy();
        func_020727ec(&self->list);
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    self->header.unknown_1_ = 1;
}
