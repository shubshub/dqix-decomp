#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_20 {
    char pad[8];
    SafeAllocator* allocator;
};
extern Struct_ov000_02184264_20 data_ov000_02184264;

struct Struct_ov000_0216c28c {
    int type;
    int next;
    int unused;
};

// USA: func_ov000_0216c28c
extern "C" ARM int func_ov000_0216c28c(void) {
    struct Struct_ov000_0216c28c* node = (struct Struct_ov000_0216c28c*)data_ov000_02184264.allocator->Allocate(0xc);
    node->type = 0;
    node->next = 0;
    node->type = 0x5e;
    func_ov000_02169b78(node);
    return 1;
}
