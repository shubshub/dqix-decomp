#include <globaldefs.h>

struct ShortArrays0204c610 {
    char unk0[0xc];
    short unknown_c_[18]; // 0xc
    short arr1[18]; // 0x30
    short arr2[18]; // 0x54
    short unknown_78_[18]; // 0x78
};

// USA: func_0204c610
extern "C" ARM void func_0204c610(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3) {
    if (index < 0) return;
    if (index >= 18) return;
    *out0 = base->unknown_c_[index];
    *out1 = base->arr1[index];
    *out2 = base->arr2[index];
    *out3 = base->unknown_78_[index];
}
