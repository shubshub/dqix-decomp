#include <globaldefs.h>

// USA: func_020d1ba0
extern "C" ARM void func_020d1ba0(unsigned short* table, unsigned short arg1) {
    unsigned int var0;
    unsigned int i;
    unsigned int bit;
    i = 0;
    do {
        var0 = i;
        bit = 0;
        do {
            if (var0 & 1) {
                var0 = arg1 ^ (var0 >> 1);
            } else {
                var0 = var0 >> 1;
            }
            bit++;
        } while (bit < 8);
        table[i] = (unsigned short)var0;
        i++;
    } while (i < 0x100);
}
