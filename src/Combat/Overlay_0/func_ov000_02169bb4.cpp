#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Struct_ov000_02169bb4 {
    int tag;
    int unused;
};

// USA: func_ov000_02169bb4
extern "C" ARM void func_ov000_02169bb4(int tag) {
    struct Struct_ov000_02169bb4* node = (struct Struct_ov000_02169bb4*)data_ov000_02184264.alloc->Allocate(8);
    if (node == NULL) return;
    node->tag = 0;
    node->unused = 0;
    node->tag = tag;
    func_ov000_02169b78(node);
}
