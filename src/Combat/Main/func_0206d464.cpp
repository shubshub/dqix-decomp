#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0206d464;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0201d530;
struct Vector3i;

struct Struct_0206d464 {
    unsigned char pad0[0xc];
    int fieldC;
    unsigned char pad1[0x44 - 0x10];
    unsigned short unknown_44_;
    unsigned char pad2[0x48 - 0x46];
    int unknown_48_[3];
    unsigned char pad3[0x70 - 0x54];
    struct Struct_0206d464* next;
};

// USA: func_0206d464
extern "C" ARM int func_0206d464(void* param0) {
    int key = ((Script::Parameter*)((struct Variant02030b0c*)param0))->ToInt();
    struct Struct_0206d464* node = (Struct_0206d464*)func_0206db20(data_02108cec.unknown_10_, key);
    if (node == 0) return 0;
    while (node != 0) {
        if (node->unknown_44_ == data_02108cec.unknown_a_) break;
        node = node->next;
    }
    if (node == 0) return 0;
    node->fieldC = node->fieldC | 0x2000;
    (Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)((char*)param0 + 8)))->ToVec3fix((Vector3i*)node->unknown_48_);
    return 1;
}
