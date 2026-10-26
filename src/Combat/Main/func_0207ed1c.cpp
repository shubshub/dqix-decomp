#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0207ed1c;

extern "C" void func_0207efdc(struct Struct_0207ed1c* obj, SafeAllocator* alloc, int count);

extern void* data_02108ed8[2];

// USA: func_0207ed1c
extern "C" ARM int func_0207ed1c(struct Variant02030b0c* p) {
    func_0207efdc((struct Struct_0207ed1c*)data_02108ed8[1], (SafeAllocator*)data_02108ed8[0], (short)((Script::Parameter*)p)->ToInt());
    return 1;
}
