#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_14 {
    char pad[8];
    SafeAllocator* allocator;
};
extern Struct_ov000_02184264_14 data_ov000_02184264;

struct Struct_0201d530 {
    int type;
    union { int i; float f; } value;
};
struct Vector3i;

struct Struct_ov000_0216b26c {
    int type;
    int next;
    int vec[3];
};

// USA: func_ov000_0216b26c
extern "C" ARM int func_ov000_0216b26c(struct Struct_0201d530* obj) {
    struct Struct_ov000_0216b26c* node = (struct Struct_ov000_0216b26c*)data_ov000_02184264.allocator->Allocate(0x14);
    node->type = 0;
    node->next = 0;
    node->type = 0x30;
    (Struct_0201d530*)((Script::Parameter*)obj)->ToVec3fix((Vector3i*)node->vec);
    func_ov000_02169b78(node);
    return 1;
}
