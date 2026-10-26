#include <globaldefs.h>

struct Struct_020e1674 {
    char pad[0x3e];
    unsigned char flag;
};
struct Struct_020e1674_2 {
    char pad[4];
    struct Struct_020e1674* ptr;
};
extern "C" void func_020e1674(struct Struct_020e1674_2* obj, int idx, int sel);

extern "C" void func_020e1a74(struct Struct_020e1674_2* obj);

struct Struct_020e2834 {
    char pad[0x10];
    struct Struct_020e1674_2* obj;
    signed char unknown_14_;
    char pad2[0x17 - 0x15];
    unsigned char unknown_17_;
};

// USA: func_020e2834
extern "C" ARM void func_020e2834(struct Struct_020e2834* self)
{
    *(short*)((char*)self->obj + 0x22) = 0x7fff;
    *(short*)((char*)self->obj + 0x24) = 0xf0a;

    if (self->unknown_17_ != 0) {
        if (self->unknown_14_ == 0) {
            func_020e1674(self->obj, 9, 1);
            func_020e1674(self->obj, 0xb, 0);
        } else {
            func_020e1674(self->obj, 9, 0);
            func_020e1674(self->obj, 0xb, 1);
        }
    } else {
        func_020e1674(self->obj, 9, 0);
        func_020e1674(self->obj, 0xb, 0);
    }

    func_020e1a74(self->obj);
}
