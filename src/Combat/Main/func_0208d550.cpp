#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/ScriptElementList.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0208d550_2;
extern "C" void func_0208d8ec(struct Struct_0208d550_2* obj, SafeAllocator* alloc, int capacity);

// USA: func_0208d550
extern "C" ARM int func_0208d550(struct Variant02030b0c* v) {
    short val = (short)((Script::Parameter*)v)->ToInt();
    if (data_02108fc0.header->unknown_c_ != 0) {
        func_0208d8ec((struct Struct_0208d550_2*)data_02108fc0.header, data_02108fc0.allocator, data_02108fc0.header->unknown_c_);
    } else {
        func_0208d8ec((struct Struct_0208d550_2*)data_02108fc0.header, data_02108fc0.allocator, val);
    }
    return 1;
}
