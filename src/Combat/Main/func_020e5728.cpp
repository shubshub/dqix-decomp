#include <globaldefs.h>
#include "Resource/Script.h"

class SafeAllocator;
struct Variant02030b0c;
struct Struct_020e5728;
extern "C" void func_020e5850(struct Struct_020e5728* self, SafeAllocator* alloc, int count);

extern void* data_021536c4[2];

// USA: func_020e5728
extern "C" ARM int func_020e5728(struct Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    func_020e5850((struct Struct_020e5728*)data_021536c4[1],
                                 (SafeAllocator*)data_021536c4[0], count);
    return 1;
}
