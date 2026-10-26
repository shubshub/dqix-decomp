#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;

struct Struct_0206c4e8;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206c4e8_2 {
    int tag;
    int f4;
    int f8;
    int fc;
    int f10;
    struct Struct_0206c4e8_2* next;
};

struct Struct_0206c4e8 {
    unsigned char pad0[0x40];
    struct Struct_0206c4e8_2* unknown_40_;
    unsigned short unknown_44_;
    unsigned char pad2[0x70 - 0x46];
    struct Struct_0206c4e8* next;
};

// USA: func_0206c4e8
extern "C" ARM int func_0206c4e8(void* param0) {
    struct Struct_0206c4e8* node;
    struct Struct_0206c4e8_2* var1;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206c4e8*)func_0206db20(data_02108cec.unknown_10_, key);
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

    var1 = (struct Struct_0206c4e8_2*)((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(0x18);
    var1->f4 = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 8)))->ToFloat());
    var1->f8 = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x10)))->ToFloat());
    var1->fc = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x18)))->ToFloat());
    var1->f10 = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x20)))->ToFloat());
    var1->tag = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x28)))->ToInt();
    var1->next = 0;

    if (node->unknown_40_ == 0) {
        node->unknown_40_ = var1;
        return 1;
    }
    {
        struct Struct_0206c4e8_2* tail = node->unknown_40_;
        while (tail->next != 0) {
            tail = tail->next;
        }
        tail->next = var1;
    }
    return 1;
}
