#include <globaldefs.h>

// USA: func_020d1b68
extern "C" ARM void func_020d1b68(const unsigned char* table, unsigned char* arg1, const unsigned char* data, unsigned int len) {
    unsigned char var0 = *arg1;
    unsigned int i = 0;
    if (i < len) {
        do {
            var0 = table[(unsigned char)(var0 ^ *data++)];
            i++;
        } while (i < len);
    }
    *arg1 = var0;
}
