#include <globaldefs.h>

extern unsigned char data_02114e00;
extern unsigned int data_02114e50;

struct Struct_0204724c {
    void* field0;
    unsigned char* field4;
};

struct Obj0204724C {
    unsigned char pad0[0xc];
    struct Struct_0204724c* table;
    unsigned char pad10[0x70 - 0x10];
    unsigned int unknown_70_;
    unsigned int unknown_74_;
    unsigned int unknown_78_;
    unsigned int field7c;
    unsigned char unknown_80_[0x84 - 0x80];
    unsigned char bit0 : 1;
    unsigned char unknown_84_1_ : 1;
    unsigned char unknown_84_2_ : 6;
};

// USA: func_0204724c
extern "C" ARM void func_0204724c(struct Obj0204724C* obj) {
    unsigned char* base;
    unsigned int off;

    if (!obj->bit0) return;
    if (!obj->unknown_84_1_) return;

    if (data_02114e00 != 0) {
        obj->unknown_78_ = data_02114e50;
        return;
    }

    if (obj->field7c >= (data_02114e50 - obj->unknown_78_)) return;

    off = obj->unknown_70_ * 0xc;
    base = obj->table[obj->unknown_74_].field4;
    obj->unknown_70_ = *(unsigned int*)(base + off);
    base = base + off;
    obj->unknown_78_ = data_02114e50;
    obj->field7c = *(unsigned int*)(base + 4);
}
