#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;

struct Struct_0206d8e8;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206d8e8_2 {
    int f0;
    int f4;
    int f8;
    int fc;
};

struct Struct_0206d8e8 {
    unsigned char pad0[0x44];
    unsigned short unknown_44_;
    unsigned char pad1[0x5c - 0x46];
    struct Struct_0206d8e8_2* unknown_5c_;
    unsigned char pad2[0x70 - 0x60];
    struct Struct_0206d8e8* next;
};

// USA: func_0206d8e8
extern "C" ARM int func_0206d8e8(void* param0) {
    struct Struct_0206d8e8* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206d8e8*)func_0206db20(data_02108cec.unknown_10_, key);
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
    node->unknown_5c_ = (struct Struct_0206d8e8_2*)((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(0x10);
    if (node->unknown_5c_ != 0) {
        node->unknown_5c_->fc = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 8)))->ToFloat());
        node->unknown_5c_->f0 = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x10)))->ToFloat());
        node->unknown_5c_->f4 = 0;
        node->unknown_5c_->f8 = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x18)))->ToFloat());
    }
    return 1;
}
