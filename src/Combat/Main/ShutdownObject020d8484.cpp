#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct ByteHeader0204693c020d8484 {
    signed char byte0;
    signed char byte1;
    signed char byte2;
    signed char byte3;
};
struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
struct Obj020d8484 {
    struct ByteHeader0204693c020d8484 header;
    int field4;
    int field8;
    struct List020727d8 list;
    SafeAllocator allocator;
};

int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ResetListHeader020727ec(struct List020727d8* list);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

// USA: func_020d8484
ARM void ShutdownObject020d8484(struct Obj020d8484* self) {
    SetField0x23cTrue_020a27ac((void*)GetFieldIfFlag4_020100f8((char*)GameState::GetInstance()));
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Reset();
        self->allocator.Destroy();
        ResetListHeader020727ec(&self->list);
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    self->header.byte1 = 1;
}
