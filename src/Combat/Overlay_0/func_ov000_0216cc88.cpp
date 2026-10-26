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

struct Struct_ov000_0216cc88 {
    int tag;
    int unused;
    unsigned char value;
};

// USA: func_ov000_0216cc88
extern "C" ARM int func_ov000_0216cc88(struct Variant02030b0c* v) {
    struct Struct_ov000_0216cc88* node = (struct Struct_ov000_0216cc88*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216cc88));
    node->tag = 0x77;
    node->value = (unsigned char)(((Script::Parameter*)v)->ToInt() != 0);
    func_ov000_02169b78(node);
    return 1;
}
