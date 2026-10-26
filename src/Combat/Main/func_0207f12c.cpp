#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct Struct_0207f12c;

extern "C" void func_0207f594(struct Struct_0207f12c* obj, SafeAllocator* alloc, int count);

extern void* data_02108ee0[2];

// USA: func_0207f12c
extern "C" ARM int func_0207f12c(Script::Parameter* p) {
    const Script::Parameter* parameters = p;
    func_0207f594((struct Struct_0207f12c*)data_02108ee0[1], (SafeAllocator*)data_02108ee0[0], (short)parameters[0].ToInt());
    return 1;
}
