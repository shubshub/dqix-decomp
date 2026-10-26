#include <globaldefs.h>

struct ShortArrays0204c654 {
    char unk0[0xc];
    short unknown_c_[18]; // 0xc
    short arr1[18]; // 0x30
    short arr2[18]; // 0x54
    short unknown_78_[18]; // 0x78
};

// USA: func_0204c654
extern "C" ARM void func_0204c654(struct ShortArrays0204c654* base, int index, short v0, short v1, short v2, short v3) {
    if (index < 0) return;
    if (index >= 18) return;
    base->unknown_c_[index] = v0;
    base->arr1[index] = v1;
    base->arr2[index] = v2;
    base->unknown_78_[index] = v3;
}
