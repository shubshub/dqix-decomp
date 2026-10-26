#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_ov000_02184264_32 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_32 data_ov000_02184264;

struct Struct_ov000_0216cdec {
    int type;
    int unused4;
    signed short field8;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216cdec*);

// USA: func_ov000_0216cdec
extern "C" ARM int func_ov000_0216cdec(struct Variant02030b0c* obj, int count) {
    struct Struct_ov000_0216cdec* e = (struct Struct_ov000_0216cdec*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7d;
    signed short v = -1;
    if (count > 0) {
        v = (signed short)((Script::Parameter*)obj)->ToInt();
    }
    e->field8 = v;
    func_ov000_02169b78(e);
    return 1;
}
