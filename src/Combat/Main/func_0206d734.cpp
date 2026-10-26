#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;

struct Struct_0206d734;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206d734 {
    unsigned char pad0[0xa];
    unsigned char unknown_a_;
    unsigned char pad1[0x44 - 0xb];
    unsigned short unknown_44_;
    unsigned char pad2[0x60 - 0x46];
    int unknown_60_;
    unsigned char pad3[0x70 - 0x64];
    struct Struct_0206d734* next;
};

// USA: func_0206d734
extern "C" ARM int func_0206d734(void* param0, int param1) {
    struct Struct_0206d734* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206d734*)func_0206db20(data_02108cec.unknown_10_, key);
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
    {
        unsigned char v = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
        node->unknown_a_ = (node->unknown_a_ & ~0x38) | ((v & 7) << 3);
    }
    if (param1 > 2) {
        node->unknown_60_ = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x10)))->ToFloat());
    }
    return 1;
}
