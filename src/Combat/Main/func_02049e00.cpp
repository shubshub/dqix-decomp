#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* arg0, int* arg1);

struct Obj02033874;
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_020e7b24 { unsigned int unknown_0_[3]; };
extern "C" const struct Struct_020e7b24 data_020e7b24;

struct Struct_02049e00 {
    unsigned char unknown_0_[0x10];
    unsigned int unknown_10_, unknown_14_, unknown_18_;
    unsigned char unknown_1c_[4];
    unsigned int unknown_20_;
};

struct Struct_02049e00_2 {
    unsigned char unknown_0_[0x44];
    unsigned int unknown_44_[3];
    unsigned char unknown_50_[0xec];
    struct Struct_02049e00* unknown_13c_;
};

// USA: func_02049e00
extern "C" ARM void func_02049e00(struct Obj02049e00* self) {
    if (self->sub == NULL) return;
    self->sub->flags &= ~0x22;
    Sub02049e00* p = self->sub;
    p->flags |= 1;
    struct Triple02049e00 t = data_020e7b24;
    t.v[0] = self->sub->f10;
    t.v[2] = self->sub->f18;
    unsigned int y = self->sub->f14;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    GameObject_SnapFacing((struct Obj02033874*)self, y);
}
