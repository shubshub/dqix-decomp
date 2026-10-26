#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0206cad8;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206cad8 {
    unsigned char pad0[0xb];
    unsigned char unknown_b_;
    unsigned char pad1[0x38];
    unsigned short unknown_44_;
    unsigned char pad2[0x2a];
    struct Struct_0206cad8* next;
};

// USA: func_0206cad8
extern "C" ARM int func_0206cad8(void* param0) {
    struct Struct_0206cad8* node;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    node = (Struct_0206cad8*)func_0206db20(data_02108cec.unknown_10_, key);
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
    node->unknown_b_ = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)param0 + 8)))->ToInt();
    return 1;
}
