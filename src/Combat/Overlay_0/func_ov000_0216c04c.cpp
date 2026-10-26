#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
struct Struct_0201d530 { int type; union { int i; float f; } value; };
struct Vector3i;

struct Struct_ov000_0216c04c {
    int tag;
    int unused;
    int unknown_8_[3];
    int unknown_14_[3];
};

// USA: func_ov000_0216c04c
extern "C" ARM int func_ov000_0216c04c(struct Variant02030b0c* v) {
    struct Struct_ov000_0216c04c* node = (struct Struct_ov000_0216c04c*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216c04c));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x59;
    struct Struct_0201d530* tv = (extern Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)v))->ToVec3fix((Vector3i*)node->unknown_8_);
    node->unknown_14_[0] = (int)(4096.0f * ((Script::Parameter*)(tv + 0))->ToFloat());
    node->unknown_14_[1] = (int)(4096.0f * ((Script::Parameter*)(tv + 1))->ToFloat());
    node->unknown_14_[2] = (int)(4096.0f * ((Script::Parameter*)(tv + 2))->ToFloat());
    func_ov000_02169b78(node);
    return 1;
}
