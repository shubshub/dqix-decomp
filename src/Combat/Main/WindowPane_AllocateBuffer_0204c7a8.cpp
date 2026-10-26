#include <globaldefs.h>
#include "Graphics/Window.h"
#include "Memory/SafeAllocator.h"

// Main, originally AllocateBuffer0204c7a8 (USA 0x0204c7a8, EUR 0x0204c7b8, JPN 0x0204d5c4)
extern "C" ARM void WindowPane_AllocateBuffer(struct WindowPane* pane, SafeAllocator* allocator, int windowBuffer, unsigned int size) {
    pane->buffer_ = allocator->Allocate(size);
    pane->windowBuffer_ = (void*)windowBuffer;
}
