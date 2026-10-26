#include <globaldefs.h>

struct Obj02033874;
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_02048cf0(void* obj, int flag);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_020e7b18 { unsigned int unknown_0_[3]; };
extern "C" const struct Struct_020e7b18 data_020e7b18;

struct Struct_02049d6c {
    unsigned int unknown_0_, unknown_4_, unknown_8_, unknown_c_;
    unsigned char unknown_10_[0x10];
    unsigned int unknown_20_;
};

struct Struct_02049d6c_2 {
    unsigned char unknown_0_[0x44];
    unsigned int unknown_44_[3];
    unsigned char unknown_50_[0xec];
    struct Struct_02049d6c* unknown_13c_;
};

// USA: func_02049d6c
extern "C" ARM void func_02049d6c(struct Obj02049d6c* self) {
    if (self->sub == NULL) return;
    func_02048cf0(self, 0);
    self->sub->flags &= ~0x21;
    struct Sub02049d6c* p = self->sub;
    p->flags |= 2;
    struct Triple02049d6c t = data_020e7b18;
    t.v[0] = self->sub->f4;
    t.v[2] = self->sub->fc;
    unsigned int y = self->sub->f8;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    GameObject_SnapFacing((struct Obj02033874*)self, y);
}
