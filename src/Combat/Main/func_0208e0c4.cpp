#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Resource/GameResources.h"

struct Variant02030b0c;
struct Struct_0201d530;
struct Vector3i;

struct Struct_0208e0c4;
struct Struct_0208e0c4_2;
extern "C" void func_0208e778(struct Struct_0208e0c4*, struct Struct_0208e0c4_2*);

extern int data_02108fe4;

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};
extern Entry02108ff4 data_02108ff4[];

struct Struct_0208e0c4_3 {
    unsigned int fieldA : 4;
    unsigned int unknown_0_4_ : 9;
    unsigned int unknown_1_5_ : 4;
    unsigned int fieldB : 4;
    unsigned int fieldC : 8;
    unsigned int pad1 : 3;
};

struct Struct_0208e0c4_4 {
    struct {
        unsigned int unknown_0_0_ : 16;
        unsigned int val1 : 7;
        unsigned int val2 : 2;
        unsigned int pad0 : 7;
    } unknown_0_;
    union {
        unsigned int raw;
        struct Struct_0208e0c4_3 b;
    } unknown_4_;
    int unknown_8_;
    int vec[8][3];
    struct Struct_0208e0c4_2* next;
};

// USA: func_0208e0c4
extern "C" ARM int func_0208e0c4(char* v) {
    SafeAllocator* alloc = (SafeAllocator*)((int)GetGameResources() + 0x1a0);
    struct Struct_0208e0c4_4* node = (struct Struct_0208e0c4_4*)alloc->Allocate(0x70);
    node->next = 0;
    node->unknown_0_.val1 = (unsigned short)((Script::Parameter*)((Variant02030b0c*)v))->ToInt();
    node->unknown_0_.unknown_0_0_ = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(v + 8)))->ToInt();
    node->unknown_0_.val2 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(v + 0x10)))->ToInt();
    node->unknown_4_.b.fieldA = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(v + 0x20)))->ToInt();
    if (node->unknown_4_.b.fieldA == 8) {
        node->unknown_4_.b.unknown_0_4_ = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(v + 0x28)))->ToInt();
        node->unknown_4_.b.unknown_1_5_ = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(v + 0x30)))->ToInt();
        Variant02030b0c* var2 = (Variant02030b0c*)(v + 0x38);
        v += 0x40;
        node->unknown_4_.b.fieldB = (unsigned char)((Script::Parameter*)var2)->ToInt();
    } else {
        unsigned char* tbl = (unsigned char*)data_02108ff4;
        node->unknown_4_.b.unknown_0_4_ = *(unsigned short*)(tbl + node->unknown_4_.b.fieldA * 4);
        node->unknown_4_.b.unknown_1_5_ = ((Entry02108ff4*)(tbl + node->unknown_4_.b.fieldA * 4))->b;
        v += 0x40;
        node->unknown_4_.b.fieldB = ((Entry02108ff4*)(tbl + node->unknown_4_.b.fieldA * 4))->c;
    }
    for (int i = 0; i < 8; i++) {
        v = (char*)(Struct_0201d530*)((Script::Parameter*)((Struct_0201d530*)v))->ToVec3fix((Vector3i*)node->vec[i]);
    }
    node->unknown_8_ = 0;
    node->unknown_4_.raw &= 0xe01fffff;
    func_0208e778((Struct_0208e0c4*)&data_02108fe4, (Struct_0208e0c4_2*)node);
    return 1;
}
