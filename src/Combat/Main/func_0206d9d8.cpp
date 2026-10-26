#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0206d9d8;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206d9d8 {
    unsigned char pad0[0xa];
    unsigned char unknown_a_;
    unsigned char pad1[0x20 - 0xb];
    unsigned short unknown_20_;
    unsigned char pad2[0x44 - 0x22];
    unsigned short unknown_44_;
    unsigned char pad3[0x70 - 0x46];
    struct Struct_0206d9d8* next;
};

// USA: func_0206d9d8
extern "C" ARM int func_0206d9d8(void* param0) {
    struct Struct_0206d9d8* node;
    int a;
    int b;
    int c;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206d9d8*)func_0206db20(data_02108cec.unknown_10_, key);
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
    a = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    b = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x10)))->ToInt();
    c = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 0x18)))->ToInt();
    node->unknown_20_ = (unsigned short)(a | (b << 5) | (c << 10));
    node->unknown_a_ |= 0x80;
    return 1;
}
