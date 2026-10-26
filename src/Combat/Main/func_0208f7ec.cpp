#include <globaldefs.h>

struct InitState0208f7ecStruct {
    int field0;                     // 0x0
    int field4;                     // 0x4
    char pad8[0xb4 - 8];            // 0x8..0xb3
    unsigned char unknown_b4_;               // 0xb4
    unsigned char unknown_b5_;               // 0xb5
    signed char unknown_b6_;                 // 0xb6
    signed char unknown_b7_;                 // 0xb7
    signed char b8;                 // 0xb8
    char unknown_b9_;                     // 0xb9
    unsigned short unknown_ba_;              // 0xba
    signed char unknown_bc_;                 // 0xbc
};

// USA: func_0208f7ec
extern "C" ARM void func_0208f7ec(struct InitState0208f7ecStruct* s) {
    s->field0 = 0;
    s->field4 = 0;
    s->unknown_b4_ = 0;
    s->unknown_b5_ = 0;
    s->unknown_b6_ = 1;
    s->unknown_b7_ = -1;
    s->b8 = -1;
    s->unknown_ba_ = 0;
    s->unknown_bc_ = -1;
}
