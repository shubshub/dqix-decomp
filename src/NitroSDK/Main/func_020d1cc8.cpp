#include <globaldefs.h>

extern "C" void func_020d1be4(const unsigned short* table, unsigned short* arg1, const unsigned char* data, unsigned int len);

// USA: func_020d1cc8
extern "C" ARM unsigned short func_020d1cc8(const unsigned short* table, const unsigned char* data, unsigned int len) {
    unsigned short var0 = 0;
    func_020d1be4(table, &var0, data, len);
    return var0;
}
