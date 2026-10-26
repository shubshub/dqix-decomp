#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201a300_6;

extern "C" void func_020286fc(struct Struct_0201a300_6* obj, SafeAllocator* alloc, int count);

struct Struct_020fdd30 {
    struct Struct_0201a300_6* obj;
    SafeAllocator* alloc;
};
extern struct Struct_020fdd30 data_020fdd30;

// USA: func_02027f90
extern "C" ARM int func_02027f90(struct Variant02030b0c* p) {
    func_020286fc(data_020fdd30.obj, data_020fdd30.alloc, ((Script::Parameter*)p)->ToInt());
    return 1;
}
