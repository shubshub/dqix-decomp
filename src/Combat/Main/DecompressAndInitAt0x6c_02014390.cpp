#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_02014390
// Main, originally Zone3D::ProcessBMBLFile_02014390 (USA 0x02014390, EUR 0x020143a0, JPN 0x0201415c)
ARM int Zone3D::ProcessBMBLFile(const void* source, unsigned int sourceLength) {
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    Zone3D_StructPtr_8* zoneEntry = pUnknownStruct_8_;
    substruct_6c_.Reset();
    substruct_6c_.LoadFromScript(allocator, script, size);
    pUnknownStruct_8_ = zoneEntry;
    return 1;
}
