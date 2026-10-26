#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0203d028_18;

struct Struct_020408c8 {
    char unknown_0_[0x1c];
    int a;
    int b;
    int c;
};
struct Struct_0203d028_19 {
    char pad[0x14];
    struct Struct_020408c8* f14;
    void* f18;
    void* f1c;
};

// USA: func_020408c8
extern "C" ARM void func_020408c8(struct Struct_0203d028_19* obj, short a, short b, short c) {
    struct Struct_020408c8* p = obj->f14;
    if (p != NULL) {
        p->a = a;
        p->b = b;
        p->c = c;
        return;
    }
    if (obj->f18 != NULL) {
        ((Object3D*)((struct Struct_0203d028_18*)obj->f18))->SetScale(a, b, c);
        return;
    }
    if (obj->f1c != NULL) {
        ((Object3D*)((struct Struct_0203d028_18*)obj->f1c))->SetScale(a, b, c);
    }
}
