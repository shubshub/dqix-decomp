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

struct Struct_0208e35c {
    struct {
        unsigned int unknown_0_0_ : 16;
        unsigned int val1 : 7;
        unsigned int val2 : 2;
        unsigned int pad0 : 7;
    } unknown_0_;
    struct {
        unsigned int fieldA : 4;
        unsigned int unknown_0_4_ : 13;
        unsigned int fieldB : 4;
        unsigned int fieldC : 8;
        unsigned int pad1 : 3;
    } unknown_4_;
    unsigned int unknown_8_;
    int vec[7][3];
    char pad2[0xc];
    struct Struct_0208e0c4_2* next;
};

// USA: func_0208e35c
extern "C" ARM int func_0208e35c(char* v) {
    SafeAllocator* alloc = (SafeAllocator*)((int)GetGameResources() + 0x1a0);
    struct Struct_0208e35c* node = (struct Struct_0208e35c*)alloc->Allocate(0x70);
    node->next = NULL;
    int tag = ((Script::Parameter*)((struct Variant02030b0c*)v))->ToInt();
    node->unknown_0_.val1 = tag;
    node->unknown_4_.fieldB = 8;
    node->unknown_0_.val2 = 1;
    v += 8;
    node->unknown_4_.fieldA = 9;
    node->unknown_0_.unknown_0_0_ = 0;
    for (int i = 0; i < 7; i++) {
        v = (char*)(Struct_0201d530*)((Script::Parameter*)((struct Struct_0201d530*)v))->ToVec3fix((Vector3i*)node->vec[i]);
    }
    node->unknown_8_ = 0;
    node->unknown_4_.fieldC = 0;
    func_0208e778((struct Struct_0208e0c4*)&data_02108fe4, (struct Struct_0208e0c4_2*)node);
    return 1;
}
