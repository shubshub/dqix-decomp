#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021a7dd8 func_ov017_021a8754
#endif
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
struct Obj021a7d78;
void InitObj_021a7d78(struct Obj021a7d78* p);

extern int g_mainAllocator;

struct Obj021a7dd8 {
    char pad[0x8];
    SafeAllocator allocator;
};

// USA: func_ov017_021a7dd8  (semantic: ResetOrDestroyObj_021a7dd8)
extern "C" ARM void func_ov017_021a7dd8(struct Obj021a7dd8* self) {
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
    }
    InitObj_021a7d78((struct Obj021a7d78*)self);
}
