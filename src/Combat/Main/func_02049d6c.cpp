#include <globaldefs.h>

struct Obj02033874;
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_02048cf0(void* obj, int flag);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_020e7b18 { unsigned int v[3]; };
extern "C" const struct Struct_020e7b18 data_020e7b18;

struct Struct_02049d6c {
    unsigned int f0, f4, f8, fc;
    unsigned char pad10[0x10];
    unsigned int flags;
};

struct Struct_02049d6c_2 {
    unsigned char unknown_0_[0x44];
    unsigned int vec44[3];
    unsigned char unknown_50_[0xec];
    struct Struct_02049d6c* sub;
};

// USA: func_02049d6c
extern "C" ARM void func_02049d6c(struct Struct_02049d6c_2* self) {
    if (self->sub == NULL) return;
    func_02048cf0(self, 0);
    self->sub->flags &= ~0x21;
    struct Struct_02049d6c* p = self->sub;
    p->flags |= 2;
    struct Struct_020e7b18 t = data_020e7b18;
    t.v[0] = self->sub->f4;
    t.v[2] = self->sub->fc;
    unsigned int y = self->sub->f8;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    GameObject_SnapFacing((struct Obj02033874*)self, y);
}
