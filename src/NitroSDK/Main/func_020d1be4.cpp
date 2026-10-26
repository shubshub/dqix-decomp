#include <globaldefs.h>

// USA: func_020d1be4
extern "C" ARM void func_020d1be4(const unsigned short* table, unsigned short* arg1, const unsigned char* data, unsigned int len) {
    unsigned int var0 = *arg1;
    unsigned int i = 0;
    if (i < len) {
        do {
            var0 = table[((var0 ^ *data++) << 24) >> 24] ^ (var0 >> 8);
            i++;
        } while (i < len);
    }
    *arg1 = (unsigned short)var0;
}
