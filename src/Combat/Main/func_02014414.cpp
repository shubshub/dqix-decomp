#include <globaldefs.h>
#include "World/Zone3D.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: ProcessBATSFile
// Main, originally Zone3D::ProcessBATSFile_02014414 (USA 0x02014414, EUR 0x02014424, JPN 0x020141e0)
ARM int Zone3D::ProcessBATSFile(const void* source, unsigned int sourceLength) {
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    lighting_.Initialize();
    lighting_.LoadFromScript(script, size, allocator);
    return 1;
}
