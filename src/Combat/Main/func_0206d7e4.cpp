#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct02030b7c;

struct Struct_0206d7e4;

struct Struct_02108cec_6 {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec_6 data_02108cec;

struct Struct_0206d7e4 {
    unsigned char pad0[0x44];
    unsigned short unknown_44_;
    unsigned char pad1[0x54 - 0x46];
    void* unknown_54_;
    void* unknown_58_;
    unsigned char pad2[0x70 - 0x5c];
    struct Struct_0206d7e4* next;
};

// USA: func_0206d7e4
extern "C" ARM int func_0206d7e4(void* param0) {
    struct Struct_0206d7e4* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206d7e4*)func_0206db20(data_02108cec.unknown_10_, key);
    if (node == 0) {
        return 0;
    }
    while (node != 0) {
        if (node->unknown_44_ == data_02108cec.unknown_a_) {
            break;
        }
        node = node->next;
    }
    if (node == 0) {
        return 0;
    }

    char* str;
    unsigned short len;

    str = (char*)(extern void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)param0 + 8)))->ToString();
    len = (unsigned short)strlen(str);
    node->unknown_54_ = ((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(len + 1);
    if (node->unknown_54_ != 0) {
        memset(node->unknown_54_, 0, len + 1);
        memcpy(node->unknown_54_, str, len);
    }

    str = (char*)(extern void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)param0 + 0x10)))->ToString();
    len = (unsigned short)strlen(str);
    node->unknown_58_ = ((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(len + 1);
    if (node->unknown_58_ != 0) {
        memset(node->unknown_58_, 0, len + 1);
        memcpy(node->unknown_58_, str, len);
    }

    return 1;
}
