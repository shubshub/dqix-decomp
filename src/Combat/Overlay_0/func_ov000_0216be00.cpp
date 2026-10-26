#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530;

struct Struct_ov000_02184264_19 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_19 data_ov000_02184264;

struct Struct_ov000_0216be00 {
    int type;
    int unused4;
    short field8;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216be00*);

// USA: func_ov000_0216be00
extern "C" ARM int func_ov000_0216be00(struct Struct_0201d530* obj) {
    struct Struct_ov000_0216be00* e = (struct Struct_ov000_0216be00*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x54;
    e->field8 = (short)(int)(4096.0f * ((Script::Parameter*)obj)->ToFloat());
    func_ov000_02169b78(e);
    return 1;
}
