#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern unsigned int data_ov023_021fd6d4[10];

// Overlay 23, originally CreateTenAndOne_021e4f64 (USA/EUR 0x021e4f64, JPN 0x021e5148)
ARM void CharacterModel_CreateAllocators(void* obj, SafeAllocator* src) {
    for (int i = 0; i < 10; i++) {
        unsigned int size = data_ov023_021fd6d4[i];
        void* buf = src->Allocate(size);
        ((SafeAllocator*)((char*)obj + 0x6b8 + i * 0x14))->CreateTypeA(buf, size);
    }
    void* buf = src->Allocate(0x1000);
    ((SafeAllocator*)((char*)obj + 0x780))->CreateTypeA(buf, 0x1000);
}
