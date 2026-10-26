#include <globaldefs.h>
// USA: func_0208349c
extern "C" ARM unsigned char* func_0208349c(unsigned char* base, int idx) {
    unsigned char* table[11];
    table[0] = base + 0x570;
    table[1] = base + 0x5a0;
    table[2] = base + 0x56f;
    table[3] = base + 0x56f;
    table[4] = base + 0x56f;
    table[5] = base + 0x5d0;
    table[6] = base + 0x600;
    table[7] = base + 0x630;
    table[8] = base + 0x660;
    table[9] = base + 0x690;
    table[10] = base + 0x6c0;
    return table[idx];
}
