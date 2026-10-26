#include <globaldefs.h>

struct Struct_ov031_022073a4 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned int address;
};
extern "C" int func_ov031_02206150(int, int, int, unsigned int, unsigned int, int);

// USA: func_ov031_022073a4
extern "C" ARM int func_ov031_022073a4(int arg0, int buffer, int size, int flags, const Struct_ov031_022073a4* destination) {
    unsigned short var0;
    unsigned int address;
    if (destination) {
        unsigned short var2 = destination->unknown_2_;
        unsigned int var3 = destination->address;
        var0 = ((var2 >> 8) & 0xff) | ((var2 << 8) & 0xff00);
        address = ((var3 >> 24) & 0xff) | ((var3 >> 8) & 0xff00) |
                  ((var3 << 8) & 0xff0000) | ((var3 << 24) & 0xff000000);
    } else {
        var0 = 0;
        address = 0;
    }
    return func_ov031_02206150(arg0, buffer, size, var0, address, flags);
}
