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

struct Struct_ov000_0216ac90 {
    int tag;
    int unused;
    unsigned char value;
    char* str;
};

// USA: func_ov000_0216ac90
extern "C" ARM int func_ov000_0216ac90(struct Variant02030b0c* v) {
    struct Struct_ov000_0216ac90* node = (struct Struct_ov000_0216ac90*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216ac90));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x21;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    char* src = (char*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 8)))->ToString();
    char* dst = (char*)data_ov000_02184264.alloc->Allocate(strlen(src) + 1);
    node->str = dst;
    strcpy(dst, src);
    func_ov000_02169b78(node);
    return 1;
}
