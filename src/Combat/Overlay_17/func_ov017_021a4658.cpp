#include <globaldefs.h>

extern "C" void func_ov017_021b2f64(unsigned char* self);

// USA: func_ov017_021a4658
extern "C" ARM unsigned char* func_ov017_021a4658(unsigned char* base, int combatantId) {
    int var0;
    for (var0 = 0; var0 < 0xc; var0++) {
        unsigned char* var1 = base + var0 * 0x48;
#if defined(jpn)
        if (var1[0x352e] != 0) {
            if (var1[0x352f] == 0 && combatantId == *(short*)(var1 + 0x3534)) {
                return base + 0x352c + var0 * 0x48;
#else
        if (var1[0x373e] != 0) {
            if (var1[0x373f] == 0 && combatantId == *(short*)(var1 + 0x3744)) {
                return base + 0x373c + var0 * 0x48;
#endif
            }
        }
    }

    int var2;
    for (var2 = 0; var2 < 0xc; var2++) {
        unsigned char* var3 = base + var2 * 0x48;
#if defined(jpn)
        if (var3[0x352e] == 0) {
            unsigned char* var4 = base + 0x352c + var2 * 0x48;
#else
        if (var3[0x373e] == 0) {
            unsigned char* var4 = base + 0x373c + var2 * 0x48;
#endif
            func_ov017_021b2f64(var4);
#if defined(jpn)
            return base + 0x352c + var2 * 0x48;
#else
            return base + 0x373c + var2 * 0x48;
#endif
        }
    }

    for (;;) {}
}
