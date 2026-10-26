#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

// USA: func_0201e518
// Main, originally ZoneFeatures::AllocateOpcode68Entries_0201e518 (USA 0x0201e518, EUR 0x0201e528, JPN 0x0201e2a4)
ARM void ZoneFeatures::AllocateExits(int count, SafeAllocator* alloc) {
    entries68_ = (Opcode68Entry*)alloc->Allocate(count * sizeof(Opcode68Entry));
    arraySize68_ = 0;
    arrayCapacity68_ = count;
}
