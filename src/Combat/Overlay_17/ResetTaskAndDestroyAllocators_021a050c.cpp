#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Combat/MapDisplay.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

class AllocatorUnion;
int AllocatorUnion_Free(AllocatorUnion*, void*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion g_mainAllocator;
extern int data_ov017_021d669c[];

// USA: func_ov017_021a050c
ARM void ResetTaskAndDestroyAllocators_021a050c(GameResources* self) {
    MapDisplay* display = self->unknown_ptr_36d0;
    func_02020720(display);

    for (int i = 0; data_ov017_021d669c[i] >= 0; i++) {
        int index = data_ov017_021d669c[i];
        void* p = self->allocator_array_38[index].GetSignedAllocator();
        self->allocator_array_38[index].Destroy();
        self->allocator_array_38[index].ResetAllocatorPointer();
        if (p != NULL) {
            AllocatorUnion_Free(&g_mainAllocator, p);
        }
    }

    void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x6f78);
    self->allocator_array_38[5].CreateTypeA(buf, 0x6f78);
}
