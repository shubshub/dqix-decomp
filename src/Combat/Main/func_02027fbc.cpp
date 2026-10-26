#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201a300_7;

extern "C" void func_02028754(struct Struct_0201a300_7* obj, SafeAllocator* alloc, int count);

struct Struct_020fdd30_2 {
    struct Struct_0201a300_7* obj;
    SafeAllocator* alloc;
};
extern struct Struct_020fdd30_2 data_020fdd30;

// USA: func_02027fbc
extern "C" ARM int func_02027fbc(struct Variant02030b0c* p) {
    int count = ((Script::Parameter*)p)->ToInt();
    func_02028754(data_020fdd30.obj, data_020fdd30.alloc, count);
    return 1;
}
