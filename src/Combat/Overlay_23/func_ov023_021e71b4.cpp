#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov023_021e71b4
// JPN: func_ov023_021e7414
extern "C" ARM void func_ov023_021e71b4(void* obj, SafeAllocator* src) {
    if (src == NULL) return;
    SafeAllocator* var0 = static_cast<SafeAllocator*>(obj);

    void* buf = src->Allocate(0x5000);
    var0[0].CreateTypeA(buf, 0x5000);

    buf = src->Allocate(0x3400);
    var0[1].CreateTypeA(buf, 0x3400);

#if defined(jpn)
    const unsigned int var2 = 0xc00;
#else
    const unsigned int var2 = 0xccc;
#endif
    buf = src->Allocate(var2);
    var0[2].CreateTypeA(buf, var2);
}
