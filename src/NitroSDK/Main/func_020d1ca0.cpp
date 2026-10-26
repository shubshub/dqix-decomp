#include <globaldefs.h>

extern "C" void func_020d1b68(const unsigned char* table, unsigned char* arg1, const unsigned char* data, unsigned int len);

// USA: func_020d1ca0
extern "C" ARM unsigned char func_020d1ca0(const unsigned char* table, const unsigned char* data, unsigned int len) {
    unsigned char var0 = 0;
    func_020d1b68(table, &var0, data, len);
    return var0;
}
