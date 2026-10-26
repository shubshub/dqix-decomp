#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_ov000_02184264_17 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_17 data_ov000_02184264;

struct Struct_ov000_0216ba68 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216ba68*);

// USA: func_ov000_0216ba68
extern "C" ARM int func_ov000_0216ba68(struct Variant02030b0c* obj) {
    struct Struct_ov000_0216ba68* e = (struct Struct_ov000_0216ba68*)data_ov000_02184264.allocator->Allocate(0xc);
    if (e == 0) return 0;
    e->type = 0;
    e->field4 = 0;
    e->type = 0x45;
    e->field8 = (unsigned short)((Script::Parameter*)obj)->ToInt();
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
