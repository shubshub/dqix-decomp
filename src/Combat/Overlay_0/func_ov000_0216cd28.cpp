#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Struct_ov000_02184264_30 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_30 data_ov000_02184264;

struct Struct_ov000_0216cd28 {
    int type;
    int field4;
    int field8;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216cd28*);

// USA: func_ov000_0216cd28
extern "C" ARM int func_ov000_0216cd28(struct Struct_0201d530* obj, int flag) {
    struct Struct_ov000_0216cd28* e = (struct Struct_ov000_0216cd28*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7b;
    int result = 0xf000;
    if (flag > 0) {
        float val = ((Script::Parameter*)obj)->ToFloat();
        result = (int)(val * 4096.0f);
    }
    e->field8 = result;
    func_ov000_02169b78(e);
    return 1;
}
