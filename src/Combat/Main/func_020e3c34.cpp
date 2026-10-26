#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct CombatState020e3c34 {
    unsigned char header;    // 0
    unsigned char pad1[7];   // 1..7
    unsigned char byte8;     // 8
    unsigned char byte9;     // 9
    unsigned short unknown_a_;   // 0xa
    int unknown_c_;              // 0xc
    int unknown_10_;             // 0x10
    int unknown_14_[2];         // 0x14, 0x18
    int unknown_1c_;             // 0x1c
    int word_20;             // 0x20
    unsigned char unknown_24_;   // 0x24
};

// USA: func_020e3c34
extern "C" ARM void func_020e3c34(CombatState020e3c34* obj) {
    int i;
    func_0204693c((ByteHeader0204693c*)obj);
    obj->header = 0x4d;
    obj->unknown_1c_ = 0;
    obj->word_20 = 0;
    for (i = 0; i < 2; i++) {
        obj->unknown_14_[i] = -1;
    }
    obj->byte8 = 0;
    obj->byte9 = 0;
    obj->unknown_a_ = 0;
    obj->unknown_c_ = 0;
    obj->unknown_10_ = 0;
    obj->unknown_24_ = 1;
}
