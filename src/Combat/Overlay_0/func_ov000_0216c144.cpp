#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };
struct Struct02030b7c { unsigned char pad[0x8]; };

struct Struct_ov000_0216c144 {
    int tag;
    int unused;
    unsigned char byte8;
    unsigned char byte9;
    char* str;
};

// USA: func_ov000_0216c144
extern "C" ARM int func_ov000_0216c144(struct Variant02030b0c* v, int argc) {
    struct Struct_ov000_0216c144* node = (struct Struct_ov000_0216c144*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216c144));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x5b;
    node->byte8 = (unsigned char)((Script::Parameter*)v)->ToInt();
    node->byte9 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    if (argc >= 3) {
        char* src = (char*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 0x10)))->ToString();
        char* dst = (char*)data_ov000_02184264.alloc->Allocate(strlen(src) + 1);
        node->str = dst;
        if (dst != 0) {
            strcpy(dst, src);
        }
    } else {
        node->str = 0;
    }
    func_ov000_02169b78(node);
    return 1;
}
