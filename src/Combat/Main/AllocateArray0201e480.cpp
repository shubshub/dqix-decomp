#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

// USA: func_0201e480
// Main, originally ZoneFeatures::AllocateOpcode66Entries_0201e480 (USA 0x0201e480, EUR 0x0201e490, JPN 0x0201e20c)
ARM void ZoneFeatures::AllocateOpcode66Entries(int count, SafeAllocator* alloc) {
    entries66_ = (Opcode66Entry*)alloc->Allocate(count * sizeof(Opcode66Entry));
    arraySize66_ = 0;
    arrayCapacity66_ = count;
}
