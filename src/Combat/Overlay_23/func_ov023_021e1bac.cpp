#include <globaldefs.h>

struct Struct_ov023_021e1bac_2 {
    char pad0[0xa];
    unsigned short unknown_a_;
    char unknown_c_[0xe - 0xc];
    unsigned char unknown_e_0_ : 1;
    unsigned char unknown_e_1_ : 1;
    unsigned char category : 6;
    unsigned char unknown_f_;
};

struct Struct_ov023_021e1bac {
    char pad0[4];
    Struct_ov023_021e1bac_2* arr;
    short count;
};

// USA: func_ov023_021e1bac
extern "C" ARM void* func_ov023_021e1bac(Struct_ov023_021e1bac* obj, int b, int c, int d) {
    unsigned short var0 = 0xffff;
    Struct_ov023_021e1bac_2* el;
    Struct_ov023_021e1bac_2* best = 0;
    Struct_ov023_021e1bac_2* arr = obj->arr;
    short count = obj->count;
    for (short i = 0; i < count; i++) {
        el = &arr[i];
        if (el->unknown_e_0_) continue;
        if (var0 < el->unknown_a_) continue;
        if (b == 0) {
            int ok = (el->category <= 7);
            if (!ok) continue;
        } else if (c >= 0 && d >= 0) {
            if (el->unknown_f_ != d) continue;
            if (el->category != c) continue;
        } else if (c >= 0) {
            if (el->category != c) continue;
        } else if (d >= 0) {
            if (el->unknown_f_ != d) continue;
        }
        var0 = el->unknown_a_;
        best = el;
    }
    if (best != 0) {
        best->unknown_e_0_ = 1;
    }
    return best;
}
