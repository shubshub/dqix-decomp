#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct Struct_ov000_02184264_29 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_29 data_ov000_02184264;

struct Struct_ov000_0216c8e4 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216c8e4*);

// USA: func_ov000_0216c8e4
extern "C" ARM int func_ov000_0216c8e4(struct Struct_0201d530* obj) {
    struct Struct_ov000_0216c8e4* e = (struct Struct_ov000_0216c8e4*)data_ov000_02184264.allocator->Allocate(0x10);
    if (e == 0) return 0;
    e->type = 0x74;
    e->field8 = (unsigned short)(int)(((Script::Parameter*)obj)->ToFloat() * 4096.0f);
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    e->fieldc = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
