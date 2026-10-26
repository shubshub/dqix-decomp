#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

// USA: func_020da150
// Duplicates a string into memory obtained from a SafeAllocator.
extern "C" ARM char* func_020da150(SafeAllocator* allocator, const char* src) {
    unsigned int len;
    unsigned int size;
    char* dst;
    if (src == NULL) return NULL;
    len = strlen(src);
    size = len + 1;
    dst = (char*)allocator->Allocate(size);
    if (dst == NULL) return NULL;
    strncpy(dst, src, len);
    (dst + size)[-1] = 0;
    return dst;
}
