#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

// USA: AllocateOpcode6aEntries
// Main, originally ZoneFeatures::AllocateOpcode6aEntries_0201e634 (USA 0x0201e634, EUR 0x0201e644, JPN 0x0201e3c0)
ARM void ZoneFeatures::AllocateOpcode6aEntries(int count, SafeAllocator* alloc) {
    entries6a_ = (Opcode6aEntry*)alloc->Allocate(count * sizeof(Opcode6aEntry));
    arraySize6a_ = 0;
    arrayCapacity6a_ = count;
}
