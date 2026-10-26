#include <globaldefs.h>

struct Struct020478bc {
    char pad0[0xc];
    char* table;
    char pad1[0x14 - 0x10];
    int count;
    char pad2[0x70 - 0x18];
    int unknown_70_;
    int index;
    int unknown_78_;
    int field7c;
    char pad3[0x84 - 0x80];
    unsigned char unknown_84_0_ : 1;
    unsigned char unknown_84_1_ : 7;
};

extern int data_02114e50;

// USA: func_020478bc
extern "C" ARM void func_020478bc(struct Struct020478bc* o, int arg1) {
    if (!o->unknown_84_0_) {
        return;
    }
    if (o->count <= 0) {
        return;
    }
    if (o->index == arg1 || arg1 == 0) {
        return;
    }

    o->unknown_70_ = 0;
    o->index = arg1;
    o->unknown_78_ = data_02114e50;
    o->field7c = *(int*)(*(char**)(o->table + o->index * 8 + 4) + o->unknown_70_ * 0xc + 4);
}
