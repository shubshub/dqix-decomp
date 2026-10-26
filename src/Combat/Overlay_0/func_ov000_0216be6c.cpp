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

struct Struct_ov000_0216be6c {
    int tag;
    int unused;
    unsigned char value;
    int unknown_c_[3];
    int unknown_18_[3];
    unsigned char flag;
};

// USA: func_ov000_0216be6c
extern "C" ARM int func_ov000_0216be6c(struct Variant02030b0c* v, int count) {
    struct Struct_ov000_0216be6c* node = (struct Struct_ov000_0216be6c*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216be6c));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x56;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    struct Struct_0201d530* next = (extern Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)((char*)v + 8)))->ToVec3fix((Vector3i*)node->unknown_c_);
    node->unknown_18_[0] = (int)(4096.0f * ((Script::Parameter*)(next + 0))->ToFloat());
    node->unknown_18_[1] = (int)(4096.0f * ((Script::Parameter*)(next + 1))->ToFloat());
    node->unknown_18_[2] = (int)(4096.0f * ((Script::Parameter*)(next + 2))->ToFloat());
    node->flag = 0;
    if (count >= 8) {
        node->flag = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)(next + 3)))->ToInt();
    }
    func_ov000_02169b78(node);
    return 1;
}
