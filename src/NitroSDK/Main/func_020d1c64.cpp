#include <globaldefs.h>

// USA: func_020d1c64
extern "C" ARM void func_020d1c64(const unsigned int* table, unsigned int* arg1, const unsigned char* data, unsigned int len) {
    unsigned int var0 = *arg1;
    unsigned int i = 0;
    if (i < len) {
        do {
            var0 = table[(unsigned char)(var0 ^ *data++)] ^ (var0 >> 8);
            i++;
        } while (i < len);
    }
    *arg1 = var0;
}
