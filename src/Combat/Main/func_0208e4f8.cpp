#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct Struct_0208e4f8 {
    int field0;
    int field4;
    short field8;
    short fielda;
    int fieldc;
};

// USA: func_0208e4f8
extern "C" ARM void func_0208e4f8(struct Struct_0208e4f8* p) {
    int base = (int)GetGameResources();
    SafeAllocator* alloc = (SafeAllocator*)(base + 0x1a0);
    alloc->Reset();
    p->field4 = 0;
    p->field8 = 0;
    p->fieldc = 0;
}
