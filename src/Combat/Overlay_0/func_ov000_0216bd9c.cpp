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

struct Struct_ov000_0216bd9c {
    int tag;
    int unused;
    short unknown_8_;
    short unknown_a_;
};

// USA: func_ov000_0216bd9c
extern "C" ARM int func_ov000_0216bd9c(struct Variant02030b0c* v) {
    struct Struct_ov000_0216bd9c* node = (struct Struct_ov000_0216bd9c*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216bd9c));
    node->tag = 0x50;
    node->unknown_a_ = (short)(int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)v))->ToFloat());
    node->unknown_8_ = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    func_ov000_02169b78(node);
    return 1;
}
