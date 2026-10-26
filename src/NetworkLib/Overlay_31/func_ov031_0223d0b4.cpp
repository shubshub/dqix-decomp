#include <globaldefs.h>

struct Struct_ov031_0223d0b4 {
    unsigned char pad[0x30];
    unsigned short mask;
    unsigned short pressed;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};

extern unsigned char data_ov031_02290d40[];
extern unsigned char data_ov031_02290d48[];

#define STATE0223d0b4 (*(Struct_ov031_0223d0b4**)(data_ov031_02290d40 + 4))

// USA: func_ov031_0223d0b4
extern "C" ARM void func_ov031_0223d0b4(void) {
    Struct_ov031_0223d0b4* state = STATE0223d0b4;
    unsigned short a = *(volatile unsigned short*)0x4000130;
    unsigned short b = *(volatile unsigned short*)0x27fffa8;
    unsigned short var3 = (unsigned short)(((a | b) ^ 0x2fff) & 0x2fff);
    state->pressed = (unsigned short)((state->mask ^ var3) & var3);
    STATE0223d0b4->unknown_36_ = (unsigned short)(state->mask & (state->mask ^ var3));
    STATE0223d0b4->mask = var3;
    STATE0223d0b4->unknown_34_ = STATE0223d0b4->pressed;

    int i = 0;
    unsigned char* var5 = data_ov031_02290d48;
    do {
        unsigned short bit = (unsigned short)(1 << i);
        if (!(var3 & bit)) {
            *var5 = 0;
        } else {
            *var5 = *var5 + 1;
            if (*var5 == 0x28) {
                STATE0223d0b4->unknown_34_ |= bit;
            } else if (*var5 == 0x2f) {
                STATE0223d0b4->unknown_34_ |= bit;
                *var5 = 0x28;
            }
        }
        i++;
        var5++;
    } while (i < 14);
}
