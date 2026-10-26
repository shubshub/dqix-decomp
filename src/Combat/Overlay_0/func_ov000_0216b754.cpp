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

struct Struct_ov000_0216b754 {
    int tag;
    int unused;
    int value;
};

// USA: func_ov000_0216b754
extern "C" ARM int func_ov000_0216b754(struct Variant02030b0c* v, int flag) {
    struct Struct_ov000_0216b754* node = (struct Struct_ov000_0216b754*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216b754));
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x3a;
    int value;
    if (flag == 0) {
        value = 1;
    } else {
        value = ((Script::Parameter*)v)->ToInt();
    }
    node->value = value;
    func_ov000_02169b78(node);
    return 1;
}
