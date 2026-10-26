#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;

struct Struct_0206c614;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206c614 {
    unsigned char pad0[0x1f];
    unsigned char unknown_1f_;
    unsigned char pad1[0x24 - 0x20];
    int unknown_24_;
    int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
    unsigned char pad2[0x44 - 0x34];
    unsigned short unknown_44_;
    unsigned char pad3[0x70 - 0x46];
    struct Struct_0206c614* next;
};

// USA: func_0206c614
extern "C" ARM int func_0206c614(void* param0) {
    struct Struct_0206c614* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206c614*)func_0206db20(data_02108cec.unknown_10_, key);
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
    node->unknown_24_ = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 8)))->ToFloat());
    node->unknown_28_ = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x10)))->ToFloat());
    node->unknown_2c_ = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x18)))->ToFloat());
    node->unknown_30_ = (int)(4096.0f * ((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 0x20)))->ToFloat());
    node->unknown_1f_ = 7;
    return 1;
}
