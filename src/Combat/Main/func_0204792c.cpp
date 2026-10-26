#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0204792c_3;
extern "C" int func_020480b8(struct Struct_0204792c_3* table, char* key);
extern "C" unsigned long long _u32_div_f(unsigned int a, unsigned int b);
extern int data_02114e50;

struct Struct_0204792c { int f0; int value; int f8; };
struct Struct_0204792c_2 { int f0; struct Struct_0204792c* rows; };

struct SelfObj792c {
    char pad0[0xc];
    struct Struct_0204792c_2* entries;
    char pad10[0x70 - 0x10];
    int row;
    int index;
    int unknown_78_;
    int range;
    char unknown_80_[0x84 - 0x80];
    unsigned char unknown_84_0_ : 1;
};

// USA: func_0204792c
extern "C" ARM void func_0204792c(struct SelfObj792c* self, char* name) {
    if (!self->unknown_84_0_) {
        return;
    }
    int idx = func_020480b8((struct Struct_0204792c_3*)((char*)self + 0x14), name);
    if (self->index == idx || idx == 0) {
        return;
    }
    self->index = idx;
    self->row = 0;
    self->unknown_78_ = data_02114e50;
    self->range = self->entries[self->index].rows[self->row].value;
    unsigned long long var1 = _u32_div_f((unsigned int)rand(), (unsigned int)self->range);
    self->unknown_78_ = self->unknown_78_ - (unsigned int)(var1 >> 32);
}
