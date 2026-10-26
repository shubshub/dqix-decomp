#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Rec0204acdc {
    unsigned short f0;
    unsigned short f2;
    unsigned char  f4;
    unsigned char  unknown_5_;
    unsigned short unknown_6_;
    unsigned int   f8;
    void*          fc;
};

// USA: func_0204acdc
extern "C" ARM int func_0204acdc(Rec0204acdc* dst, void* unused, unsigned char* src, SafeAllocator* alloc) {
    int local0;
    memcpy(&local0, src, 4);
    memcpy(&dst->f0, src + 4, 2);
    memcpy(&dst->f2, src + 6, 2);
    memcpy(&dst->f4, src + 8, 1);
    memcpy(&dst->unknown_5_, src + 9, 1);
    memcpy(&dst->unknown_6_, src + 0xa, 2);
    memcpy(&dst->f8, src + 0xc, 4);
    void* p = alloc->Allocate(dst->f8);
    dst->fc = p;
    memcpy(p, src + 0x10, dst->f8);
    return 0;
}
