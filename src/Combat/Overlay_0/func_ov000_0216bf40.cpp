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

struct Struct_ov000_0216bf40 {
    int tag;
    int unused;
    short unknown_8_;
};

// USA: func_ov000_0216bf40
extern "C" ARM int func_ov000_0216bf40(struct Variant02030b0c* v) {
    struct Struct_ov000_0216bf40* node = (struct Struct_ov000_0216bf40*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216bf40));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x57;
    node->unknown_8_ = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)v))->ToFloat());
    func_ov000_02169b78(node);
    return 1;
}
