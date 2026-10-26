#include <globaldefs.h>

extern "C" ARM int fix32_Divide(unsigned int arg0, unsigned int arg1);

struct Struct_ov001_021598f0 { char pad0[0x10]; int f10; int f14; };
struct Struct_ov001_021598f0_2 { char pad0[0x68]; int f68; char pad1[0x90 - 0x6c]; int f90; char pad2[0x118 - 0x94]; int unknown_118_; };

// USA: func_ov001_021598f0
extern "C" ARM int func_ov001_021598f0(struct Struct_ov001_021598f0* arg0, struct Struct_ov001_021598f0_2* obj2) {
    int total = arg0->f14;
    int cur = obj2->f68;
    if (cur >= total) {
        obj2->f90 = arg0->f10;
        obj2->f68 = 0;
        return 0;
    }
    if (cur <= 0) {
        int delta = arg0->f10 - obj2->f90;
        if (total == 0) {
            return 0;
        }
        obj2->unknown_118_ = fix32_Divide(delta, total << 12);
    } else {
        obj2->f90 += obj2->unknown_118_;
    }
    obj2->f68 = obj2->f68 + 1;
    return 1;
}
