#include <globaldefs.h>

struct Struct_ov001_02159820 { char pad[0x10]; int f10; int f14; };
struct Struct_ov001_02159820_2 { char pad0[0x64]; int f64; char pad1[0x24]; float unknown_8c_; char pad2[0x84]; float unknown_114_; };

// USA: func_ov001_02159820
extern "C" ARM int func_ov001_02159820(Struct_ov001_02159820* a, Struct_ov001_02159820_2* b) {
    int limit = a->f14;
    int counter = b->f64;
    if (counter >= limit) {
        b->unknown_8c_ = (float)a->f10;
        b->f64 = 0;
        return 0;
    }
    float var2 = b->unknown_8c_;
    if (counter <= 0) {
        int diff = a->f10 - (int)var2;
        if (limit == 0) return 0;
        b->unknown_114_ = (float)diff / (float)limit;
    } else {
        b->unknown_8c_ = var2 + b->unknown_114_;
    }
    b->f64 = b->f64 + 1;
    return 1;
}
