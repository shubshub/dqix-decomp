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

struct Struct_ov000_0216cf84 {
    int tag;
    int unused;
    unsigned char value;
};

// USA: func_ov000_0216cf84
extern "C" ARM int func_ov000_0216cf84(struct Variant02030b0c* v, int count) {
    struct Struct_ov000_0216cf84* node = (struct Struct_ov000_0216cf84*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216cf84));
    node->tag = 0x84;
    if (count >= 1) {
        node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    }
    func_ov000_02169b78(node);
    return 1;
}
