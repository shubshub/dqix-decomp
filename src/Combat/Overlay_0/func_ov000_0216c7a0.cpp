#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct Struct_ov000_02184264_27 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct Struct_ov000_02184264_27 data_ov000_02184264;

struct Struct_ov000_0216c7a0 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Struct_ov000_0216c7a0*);

// USA: func_ov000_0216c7a0
extern "C" ARM int func_ov000_0216c7a0(struct Struct_0201d530* obj) {
    struct Struct_ov000_0216c7a0* e = (struct Struct_ov000_0216c7a0*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x71;
    e->fielda = (unsigned short)(int)(((Script::Parameter*)obj)->ToFloat() * 4096.0f);
    e->field8 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
