#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

// USA: func_0201e25c
// Main, originally ZoneFeatures::AllocateOpcode64Entries_0201e25c (USA 0x0201e25c, EUR 0x0201e26c, JPN 0x0201dfe8)
ARM void ZoneFeatures::AllocateOpcode64Entries(int count, SafeAllocator* alloc) {
    entries64_ = (Opcode64Entry*)alloc->Allocate(count * sizeof(Opcode64Entry));
    arraySize64_ = 0;
    arrayCapacity64_ = count;
}
