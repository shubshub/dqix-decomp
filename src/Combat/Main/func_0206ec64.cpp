#include <globaldefs.h>
extern "C" void func_0209953c(unsigned short value);
// USA: func_0206ec64
extern "C" void func_0206ec64(int unused, int index, unsigned char* data, unsigned int count) {
    int rem = index % 2;
    int half = index / 2;
    if (count <= (unsigned int)half) {
        func_0209953c(0x3e7);
        return;
    }

    unsigned char var2 = data[half];
    if (rem != 0) {
        unsigned int nibble = var2 & 0xf;
        if (nibble >= 0xf) {
            return;
        }
        nibble = nibble + 1;
        data[half] = (nibble & 0xff) | (var2 & 0xf0);
    } else {
        unsigned int nibble = (var2 >> 4) & 0xff;
        if (nibble < 0xf) {
            unsigned int var5 = nibble + 1;
            unsigned int low = var2 & 0xf;
            unsigned char var7 = (unsigned char)var5;
            data[half] = (var7 << 4) | low;
        }
    }
}
