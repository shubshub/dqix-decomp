#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530;

struct Struct_ov000_02184264_18 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_18 data_ov000_02184264;

struct Struct_ov000_0216bc54 {
    int type;
    int unused4;
    int field8;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216bc54*);

// USA: func_ov000_0216bc54
extern "C" ARM int func_ov000_0216bc54(struct Struct_0201d530* obj) {
    struct Struct_ov000_0216bc54* e = (struct Struct_ov000_0216bc54*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x4d;
    e->field8 = (int)(4096.0f * ((Script::Parameter*)obj)->ToFloat());
    func_ov000_02169b78(e);
    return 1;
}
