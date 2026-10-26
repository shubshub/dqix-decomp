#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_020e7b24 { unsigned int v[3]; };
extern "C" const struct Struct_020e7b24 data_020e7b24;

struct Struct_02049e00 {
    unsigned char pad[0x10];
    unsigned int f10, f14, f18;
    unsigned char unknown_1c_[4];
    unsigned int flags;
};

struct Struct_02049e00_2 {
    unsigned char pad[0x44];
    unsigned int vec44[3];
    unsigned char unknown_50_[0xec];
    struct Struct_02049e00* sub;
};

// USA: func_02049e00
extern "C" ARM void func_02049e00(struct Struct_02049e00_2* self) {
    if (self->sub == NULL) return;
    self->sub->flags &= ~0x22;
    Struct_02049e00* p = self->sub;
    p->flags |= 1;
    struct Struct_020e7b24 t = data_020e7b24;
    t.v[0] = self->sub->f10;
    t.v[2] = self->sub->f18;
    unsigned int y = self->sub->f14;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    GameObject_SnapFacing((struct Obj02033874*)self, y);
}
