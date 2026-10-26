#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Struct_ov000_0216c9fc {
    int tag;
    int unused;
    short x;
    short y;
    unsigned char type;
};

// USA: func_ov000_0216c9fc
extern "C" ARM int func_ov000_0216c9fc(struct Variant02030b0c* v) {
    struct Struct_ov000_0216c9fc* node = (struct Struct_ov000_0216c9fc*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216c9fc));
    if (node == 0) {
        return 0;
    }
    memset(node, 0, sizeof(struct Struct_ov000_0216c9fc));
    int type = ((Script::Parameter*)v)->ToInt();
    node->type = (unsigned char)type;
    switch (type & 0xff) {
    case 0:
        node->x = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)v + 8)))->ToFloat());
        node->y = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)v + 0x10)))->ToFloat());
        break;
    case 1:
        node->x = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
        node->y = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)v + 0x10)))->ToFloat());
        break;
    }
    node->tag = 0x75;
    func_ov000_02169b78(node);
    return 1;
}
