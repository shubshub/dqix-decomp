#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0206ca3c;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206ca3c {
    unsigned char pad0[0xc];
    unsigned int unknown_c_;
    unsigned char pad1[0x44 - 0x10];
    unsigned short unknown_44_;
    unsigned char pad2[0x70 - 0x46];
    struct Struct_0206ca3c* next;
};

// USA: func_0206ca3c
extern "C" ARM int func_0206ca3c(void* param0, int count) {
    struct Struct_0206ca3c* node;
    void* var1 = param0;
    int i;
    param0 = (char*)param0 + 8;
    int key = ((Script::Parameter*)((struct Variant02030b0c*)var1))->ToInt();
    node = (Struct_0206ca3c*)func_0206db20(data_02108cec.unknown_10_, key);
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
    for (i = 0; i < count - 1; i++) {
        node->unknown_c_ |= ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
        param0 = (char*)param0 + 8;
    }
    return 1;
}
