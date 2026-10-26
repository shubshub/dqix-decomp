#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201a300_8;

extern "C" void func_0202834c(struct Struct_0201a300_8* obj, SafeAllocator* alloc, int count);

struct Struct_020fdd30_3 {
    struct Struct_0201a300_8* obj;
    SafeAllocator* alloc;
};
extern struct Struct_020fdd30_3 data_020fdd30;

// USA: func_02027fe8
extern "C" ARM int func_02027fe8(struct Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    func_0202834c(data_020fdd30.obj, data_020fdd30.alloc, count);
    return 1;
}
