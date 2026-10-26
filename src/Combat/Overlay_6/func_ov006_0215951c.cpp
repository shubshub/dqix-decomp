#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_0215951c {
    char pad0[R(0x48, 0x50)];
    unsigned short* table;
    char unknown_54_[0x362 - R(0x4c, 0x54)];
    short unknown_362_;
    char unknown_364_[0x388 - 0x364];
    unsigned char unknown_388_;
    unsigned char unknown_389_;
};

// USA: func_ov006_0215951c
extern "C" ARM void func_ov006_0215951c(struct Struct_ov006_0215951c* obj) {
    int q;
    short idx;
    obj->unknown_388_ = 0;
    idx = obj->unknown_362_ - 0x5b;
    q = (obj->table[idx] + 7) / 8;
    obj->unknown_389_ = q;
    if ((q & 0xff) == 0) {
        obj->unknown_389_ = 1;
    }
}
