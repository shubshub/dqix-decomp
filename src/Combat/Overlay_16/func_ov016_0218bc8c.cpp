#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int allocatorOffset = 0;
#else
static const int allocatorOffset = 8;
#endif

// USA: func_ov016_0218bc8c
extern "C" ARM void* func_ov016_0218bc8c(unsigned int arg0) {
    SafeAllocator* allocator = *(SafeAllocator**)(data_ov016_0219d0c0 + allocatorOffset);
    return allocator->Allocate(arg0);
}
