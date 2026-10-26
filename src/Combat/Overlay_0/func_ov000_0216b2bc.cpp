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

struct Struct_ov000_0216b2bc {
    int tag;
    int unused;
    int vec[3];
    unsigned char flag;
};

// USA: func_ov000_0216b2bc
extern "C" ARM int func_ov000_0216b2bc(struct Variant02030b0c* v, int count) {
    struct Struct_ov000_0216b2bc* node = (struct Struct_ov000_0216b2bc*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216b2bc));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x31;
    struct Struct_0201d530* tv = (extern Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)v))->ToVec3fix((Vector3i*)node->vec);
    unsigned char flag = 0;
    if (count >= 4) {
        flag = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)tv))->ToInt();
    }
    node->flag = flag;
    func_ov000_02169b78(node);
    return 1;
}
