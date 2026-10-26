#include <globaldefs.h>

struct Struct_020e3b08 {
    unsigned char pad[5];
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char pad2;
};

// USA: func_020e3b08
extern "C" ARM void func_020e3b08(struct Struct_020e3b08* entries, int bit) {
    int i;
    for (i = 0; i < 4; i++, entries++) {
        entries->unknown_5_ &= ~(1 << bit);
        entries->unknown_6_ &= ~(1 << bit);
    }
}
