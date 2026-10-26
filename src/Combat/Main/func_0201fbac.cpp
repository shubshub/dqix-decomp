#include <globaldefs.h>

struct Stopwatch0201fbac {
    unsigned char state;    // +0
    unsigned char b1;       // +1
    unsigned char b2;       // +2
    unsigned char b3;       // +3
    unsigned short unknown_4_;      // +4
    unsigned short unknown_6_;      // +6
    int w8;                 // +8
    int unknown_c_;                 // +0xc
    int unknown_10_;                // +0x10
};

// USA: func_0201fbac
extern "C" ARM void func_0201fbac(struct Stopwatch0201fbac* t) {
    unsigned char st = t->state;
    if (st == 1 || st == 4) {
        t->b1 = 3;
    } else if (st == 2) {
        t->unknown_10_ = 0x43080000;
    }
    t->unknown_4_ = 0;
}
