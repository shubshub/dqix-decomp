#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201c1c8 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Struct_ov003_0215e4c8 {
    unsigned char unknown_0_;
    signed char unknown_1_;
    signed char unknown_2_;
    signed char unknown_3_;
    short* unknown_4_;
};
extern "C" void func_ov003_0215e4c8(struct Struct_ov003_0215e4c8* arg0);

struct Struct_02000c9c_84;
extern "C" void func_ov003_0215e898(struct Struct_02000c9c_84* arg0, struct Struct_ov003_0215e4c8* arg1);

struct Struct_ov003_02180cb8 {
    void* unknown_0_;
    struct Struct_02000c9c_84* unknown_4_;
};
extern struct Globals02180cb8 KeyboardLayout_scriptContext;

// USA: func_ov003_0215e628
extern "C" ARM int func_ov003_0215e628(struct Variant02030b0c* params) {
    struct Obj0215e4c8 local;
    ClearStruct_0215e4c8(&local);
    local.kind = ((Script::Parameter*)&params[0])->ToInt();
    local.width = ((Script::Parameter*)&params[1])->ToInt();
    struct Variant02030b0c* heightParam = &params[2];
    params += 3;
    local.height = ((Script::Parameter*)heightParam)->ToInt();
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
