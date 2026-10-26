#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Memory/SafeAllocator.h"

// Main, originally AllocateArray0204af38 (USA 0x0204af38, EUR 0x0204af48, JPN 0x0204bd58)
extern "C" ARM void Background_AllocateScreens(struct BackgroundGraphics* layer, int count, SafeAllocator* alloc) {
    if (alloc == NULL) return;
    layer->screens_ = (BackgroundScreen*)alloc->Allocate(count * sizeof(BackgroundScreen));
    layer->screenCapacity_ = count;
}
