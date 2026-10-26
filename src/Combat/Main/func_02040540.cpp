#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0203cec4;
extern "C" void func_0203ceb4(unsigned char* obj);
extern "C" void func_0203cec4(struct Struct_0203cec4* obj, int enable);

struct Struct_0203fc84;
extern "C" void func_0203fc84(struct Struct_0203fc84* obj, int value);

struct S02037418;

struct Struct_02040540_2 {
    char pad[0x50];
    unsigned int unknown_50_;
};

struct Struct_02040540_3 {
    char pad[0xac];
    unsigned short unknown_ac_;
};

struct Struct_02040540 {
    char pad[0xc];
    unsigned int val;
};

struct Struct_0203d028_17 {
    unsigned int flags;
    unsigned int unk4;
    unsigned int unknown_8_;
    struct Struct_02040540* child;
    unsigned int unk10;
    struct Struct_0203cec4* b;
    struct S02037418* c;
};

// USA: func_02040540
extern "C" ARM void func_02040540(struct Struct_0203d028_17* obj) {
    if (obj->child == NULL) return;
    obj->flags |= obj->child->val;

    if (obj->b != NULL) {
        if (obj->flags & 0x4) func_0203ceb4((unsigned char*)obj->b);
        if (obj->flags & 0x10) func_0203cec4(obj->b, 1);
        if (obj->flags & 0x20) func_0203fc84((struct Struct_0203fc84*)obj->b, 0x10);
        if (obj->flags & 0x100) ((struct Struct_02040540_2*)obj->b)->unknown_50_ |= 2;
        if (obj->flags & 0x400) ((struct Struct_02040540_2*)obj->b)->unknown_50_ |= 4;
        if (obj->flags & 0x800) ((struct Struct_02040540_2*)obj->b)->unknown_50_ |= 8;
    } else if (obj->c != NULL) {
        if (obj->flags & 0x4) ((struct Struct_02040540_3*)obj->c)->unknown_ac_ |= 4;
        if (obj->flags & 0x20) ((Object3D*)obj->c)->SetInheritedAlpha(0x10);
    }

    if (obj->flags & 0x8) obj->unk4 = 0;
}
