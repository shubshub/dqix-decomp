#include <globaldefs.h>

struct Struct_0204b878;
extern "C" void func_0204b878(struct Struct_0204b878* obj, int a2, int a3, int a4,
                                                  short a5, short a6, short a7, short a8, unsigned short a9);

struct Struct0204c8f0 {
    char pad0[0x4];
    void* field4;               // 0x4
    char pad1[0x94];            // 0x8..0x9b
    int unknown_9c_;                // 0x9c
    char pad2[0xc];              // 0xa0..0xab
    short field_ac;               // 0xac
    short unknown_ae_;               // 0xae
    char pad3[0x10];              // 0xb0..0xbf
    short unknown_c0_;                // 0xc0
    unsigned short unknown_c2_;       // 0xc2
    char pad4[0x1];                 // 0xc4
    unsigned char unknown_c5_;          // 0xc5
    char pad5[0x2];                   // 0xc6..0xc7
    short unknown_c8_;                    // 0xc8
};

// Main, originally SomeFunc0204c8f0 (USA 0x0204c8f0, EUR 0x0204c900, JPN 0x0204d700)
extern "C" ARM void WindowPane_Draw(struct Struct0204c8f0* lr) {
    if (lr->field4 == NULL) return;
    if (!(lr->unknown_c5_ & 1) || lr->unknown_9c_ == 0) return;
    if (lr->unknown_c5_ & 0x20) return;

    func_0204b878(
        (struct Struct_0204b878*)lr->field4,
        (int)((char*)lr + 0xc8),
        0, 0,
        lr->field_ac, lr->unknown_ae_, lr->unknown_c8_, lr->unknown_c0_,
        lr->unknown_c2_);
}
