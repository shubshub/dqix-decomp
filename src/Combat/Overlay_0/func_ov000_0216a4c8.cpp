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

struct Struct02030b7c;

extern char data_ov000_02183fbc[];
extern char data_ov000_02183fc1[];

struct Struct_ov000_0216a4c8 {
    int tag;
    void* field4;
    char* unknown_8_;
};

// USA: func_ov000_0216a4c8
extern "C" ARM int func_ov000_0216a4c8(struct Struct02030b7c* p) {
    struct Struct_ov000_0216a4c8* node = (struct Struct_ov000_0216a4c8*)data_ov000_02184264.alloc->Allocate(sizeof(struct Struct_ov000_0216a4c8));
    node->tag = 0;
    node->field4 = 0;
    node->tag = 0x12;
    char* name = (char*)(extern void*)((Script::Parameter*)p)->ToString();
    node->unknown_8_ = (char*)data_ov000_02184264.alloc->Allocate(strlen(name) + 1);
    strcpy(node->unknown_8_, name);
    char* found = strstr(node->unknown_8_, data_ov000_02183fbc);
    if (found != NULL) {
        strcpy(found, data_ov000_02183fc1);
    }
    func_ov000_02169b78(node);
    return 1;
}
