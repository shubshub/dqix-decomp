#include <globaldefs.h>

struct Struct_02088018 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 24;
    int stage : 3;
};

// USA: func_02088018
extern "C" ARM int func_02088018(struct Struct_02088018* p, int arg1) {
    if (p->flags & 1) return 0;
    if (arg1 == 0) {
        if (p->stage < 2) return 1;
    } else {
        if (p->stage > -2) return 1;
    }
    return 0;
}
