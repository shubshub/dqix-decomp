#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Struct_ov000_0216d110 {
    int tag;
    int unused;
    unsigned char value;
    int angle;
};

// USA: func_ov000_0216d110
extern "C" ARM int func_ov000_0216d110(struct Variant02030b0c* v) {
    struct Struct_ov000_0216d110* node = (struct Struct_ov000_0216d110*)data_ov000_02184264.alloc->Allocate(0x10);
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x8c;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    float var1 = ((Script::Parameter*)((struct Struct_0201d530*)((char*)v + 8)))->ToFloat();
    node->angle = (int)(var1 * 3.14159274f / 180.0f * 4096.0f);
    func_ov000_02169b78(node);
    return 1;
}
