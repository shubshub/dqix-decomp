#include <globaldefs.h>

struct Struct_ov004_021537e0 {
    unsigned char pad0[2];
    short f2;
    unsigned char pad4;
    unsigned char unknown_5_;
};

extern Struct_ov004_021537e0* data_ov004_021707c0;

// USA: func_ov004_021537e0
extern "C" ARM int func_ov004_021537e0() {
    short accum = 0;
    short lr = 0;
    Struct_ov004_021537e0* elem;
    Struct_ov004_021537e0* arr;
    while (lr <= 0xb) {
        unsigned char idx = 0;
        arr = data_ov004_021707c0;
        while (idx < 20) {
            elem = &arr[idx];
            if (elem->f2 == lr) goto found;
            idx = (unsigned char)(idx + 1);
        }
        elem = 0;
found:
        if (elem) accum = (short)(accum + elem->unknown_5_);
        lr = (short)(lr + 1);
    }
    return accum;
}
