#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };

struct Struct02030b7c;

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_6 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_6 data_ov000_02184264;

struct Struct_ov000_0216b7b8 {
    int tag;
    int unused;
    unsigned char b8;
    unsigned char unknown_9_;
    char pad[2];
    char* str;
};

// USA: func_ov000_0216b7b8
extern "C" ARM int func_ov000_0216b7b8(char* arg) {
    struct Struct_ov000_0216b7b8* node = (struct Struct_ov000_0216b7b8*)data_ov000_02184264.alloc->Allocate(0x10);
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x3b;
    node->b8 = (((Script::Parameter*)((struct Variant02030b0c*)arg))->ToInt() & 0xff) - 0x1a;
    node->unknown_9_ = (((Script::Parameter*)((struct Variant02030b0c*)(arg + 0x8)))->ToInt() & 0xff) - 0x1a;
    char* text = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)(arg + 0x10)))->ToString();
    if (text != NULL) {
        char* buf = (char*)data_ov000_02184264.alloc->Allocate(strlen(text) + 1);
        node->str = buf;
        if (buf != NULL) {
            strcpy(buf, text);
        }
    } else {
        node->str = 0;
    }
    func_ov000_02169b78(node);
    return 1;
}
