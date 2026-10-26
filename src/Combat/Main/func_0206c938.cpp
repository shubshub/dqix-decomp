#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0201d530;
struct Vector3i;

struct Struct_0206c938;

struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char pad1[0x10 - 0xc];
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec data_02108cec;

struct Struct_0206c938_2 {
    int vec[3];
    int unknown_c_;
    struct Struct_0206c938_2* next;
};

struct Struct_0206c938 {
    unsigned char pad0[0x1f];
    unsigned char unknown_1f_;
    unsigned char pad1[0x34 - 0x20];
    struct Struct_0206c938_2* unknown_34_;
    unsigned char pad2[0x44 - 0x38];
    unsigned short unknown_44_;
    unsigned char pad3[0x70 - 0x46];
    struct Struct_0206c938* next;
};

// USA: func_0206c938
extern "C" ARM int func_0206c938(void* param0, int param1) {
    struct Struct_0206c938* node;
    int count;
    struct Struct_0206c938_2* prev;
    int i;
    struct Struct_0206c938_2* var4;
    void* var5 = param0;
    int key;

    param0 = (char*)param0 + 8;
    key = ((Script::Parameter*)((struct Variant02030b0c*)var5))->ToInt();
    node = (Struct_0206c938*)func_0206db20(data_02108cec.unknown_10_, key);
    if (node == 0) {
        return 0;
    }
    if ((param1 - 1) % 3 != 0) {
        return 0;
    }
    while (node != 0) {
        if (node->unknown_44_ == data_02108cec.unknown_a_) break;
        node = node->next;
    }
    if (node == 0) {
        return 0;
    }
    node->unknown_1f_ = 10;
    count = (param1 - 1) / 3;
    prev = 0;
    for (i = 0; i < count; i++) {
        var4 = (struct Struct_0206c938_2*)((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(0x14);
        if (var4 == 0) {
            return 0;
        }
        param0 = (void*)(Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)param0))->ToVec3fix((Vector3i*)var4->vec);
        var4->unknown_c_ = 0;
        if (prev == 0) {
            node->unknown_34_ = var4;
        } else {
            prev->next = var4;
        }
        prev = var4;
    }
    prev->next = node->unknown_34_;
    prev->unknown_c_ = 1;
    return 1;
}
