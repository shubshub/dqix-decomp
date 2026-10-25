#include <globaldefs.h>

struct Obj0204b878;
extern void CallFunc0204b620IfField0x14_0204b878(struct Obj0204b878* obj, int a2, int a3, int a4,
                                                  short a5, short a6, short a7, short a8, unsigned short a9);

struct Struct0204c8f0 {
    char pad0[0x4];
    void* field4;               // 0x4
    char pad1[0x94];            // 0x8..0x9b
    int state_9c;                // 0x9c
    char pad2[0xc];              // 0xa0..0xab
    short field_ac;               // 0xac
    short field_ae;               // 0xae
    char pad3[0x10];              // 0xb0..0xbf
    short field_c0;                // 0xc0
    unsigned short field_c2;       // 0xc2
    char pad4[0x1];                 // 0xc4
    unsigned char flags_c5;          // 0xc5
    char pad5[0x2];                   // 0xc6..0xc7
    short field_c8;                    // 0xc8
};

// Main, originally SomeFunc0204c8f0 (USA 0x0204c8f0, EUR 0x0204c900, JPN 0x0204d700)
ARM void WindowPane_Draw(struct Struct0204c8f0* lr) {
    if (lr->field4 == NULL) return;
    if (!(lr->flags_c5 & 1) || lr->state_9c == 0) return;
    if (lr->flags_c5 & 0x20) return;

    CallFunc0204b620IfField0x14_0204b878(
        (struct Obj0204b878*)lr->field4,
        (int)((char*)lr + 0xc8),
        0, 0,
        lr->field_ac, lr->field_ae, lr->field_c8, lr->field_c0,
        lr->field_c2);
}
