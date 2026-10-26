#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

extern int data_0210fcf4;
extern int data_0210fcb4;

struct Struct_020bcd30 {
    char pad0[0x20];
    int f20;
    char pad24[4];
    int f28;
    int unknown_2c_;
    int unknown_30_;
    int f34;
    int unknown_38_;
    char unknown_3c_[0x48 - 0x3c];
    int unknown_48_;
    unsigned char unknown_4c_[1];
};

struct Struct_020bcd30_2 {
    int a;
    int b;
};

typedef int (*Type_020bcd30)(void*, int, int*, unsigned int, int, int);

// USA: func_020bcd30
extern "C" ARM void func_020bcd30(Struct_020bcd30* obj, void* param2) {
    unsigned int var0 = _u32_div_f(obj->f28, obj->unknown_2c_);
    int var1 = var0 * obj->unknown_38_;
    int i = 0;
    if (obj->unknown_48_ > 0) {
        do {
            unsigned char idx = obj->unknown_4c_[i];
            int word = ((Struct_020bcd30_2*)&data_0210fcf4)[idx].a;
            ((int*)&data_0210fcb4)[i] = word + var1;
            i++;
        } while (i < obj->unknown_48_);
    }
    Type_020bcd30 cb = (Type_020bcd30)obj->unknown_30_;
    cb(param2, obj->unknown_48_, (int*)&data_0210fcb4, var0, obj->f20, obj->f34);

    int var6 = obj->unknown_38_ + 1;
    obj->unknown_38_ = var6;
    if (var6 >= obj->unknown_2c_) {
        obj->unknown_38_ = 0;
    }
}
