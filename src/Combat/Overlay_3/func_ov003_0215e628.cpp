#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Struct_ov003_0215e4c8 {
    unsigned char kind;
    signed char width;
    signed char height;
    signed char count;
    short* values;
};
extern "C" void func_ov003_0215e4c8(struct Struct_ov003_0215e4c8* obj);

struct Struct_02000c9c_84;
extern "C" void func_ov003_0215e898(struct Struct_02000c9c_84* o, struct Struct_ov003_0215e4c8* e);

struct Globals02180cb8 {
    void* allocator;
    struct Struct_02000c9c_84* target;
};
extern struct Globals02180cb8 KeyboardLayout_scriptContext;

// USA: func_ov003_0215e628
extern "C" ARM int func_ov003_0215e628(struct Variant02030b0c* params) {
    struct Struct_ov003_0215e4c8 local;
    func_ov003_0215e4c8(&local);
    local.kind = ((Script::Parameter*)&params[0])->ToInt();
    local.width = ((Script::Parameter*)&params[1])->ToInt();
    struct Variant02030b0c* var1 = &params[2];
    params += 3;
    local.height = ((Script::Parameter*)var1)->ToInt();
    local.count = local.width * local.height;
    signed char count = local.count;
    short* dst = (short*)((SafeAllocator*)KeyboardLayout_scriptContext.allocator)->Allocate(count * 2);
    local.values = dst;
    if (dst != NULL) {
        for (int i = 0; i < count; i++) {
            *dst = ((Script::Parameter*)(params++))->ToInt();
            dst++;
        }
    }
    func_ov003_0215e898(KeyboardLayout_scriptContext.target, &local);
    return 1;
}
